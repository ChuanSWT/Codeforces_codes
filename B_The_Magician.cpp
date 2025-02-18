#include<bits/stdc++.h>
//#define int signed char
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
map<int,set<vector<int>>> mp;
vector<vector<vector<int>>> tmp(4);
vector<int> in(4,0);
vector<int> out(4,0);
set<vector<int>> st;
int best_score;
bool check(vector<int> &cur,vector<int>& trans)
{
    for(int i=0;i<4;++i)
    if(trans[i]>cur[i])
    return false;

    return true;
}
bool is_end(vector<int> &cur)
{

    for(int i=4;i<10;++i)
    {
        if(cur[i])
        return false;
    }
    return true;
}
int cal(vector<int> &cur)
{
    int ans=0;
    int master=cur[10];
    priority_queue<int> pq;
    vector<int> nums={cur[0],cur[1],cur[2],cur[3]};
    sort(nums.rbegin(),nums.rend());
    for(int i=0;i<nums.size();++i)
    {
        ans+=nums[i]/5;
        nums[i]%=5;
        if(master+nums[i]>=5)
        {
            master-=5-nums[i];
            ++ans;
        }
    }
    return ans;
}
bool check_trans(int target,vector<int>&trans)
{
    for(int i=0;i<4;++i)
        if(in[i]&&trans[i])
            return false;
    if(out[target])
        return false;
    return true;
}
//int count_1=0;
void dfs(vector<int> &cur,int &ans)
{
    if(st.find(cur)!=st.end())
    return;
    st.insert(cur);
    //++count_1;
    //if(count_1%100000==0)
    //cout<<count_1<<endl;
    /*for(int x:cur)
    cout<<x<<" ";
    cout<<endl;*/
    if(is_end(cur))
    {
        int rst=cal(cur);
        ans=max(ans,rst);
        return;
    }

    for(int i=4;i<8;++i)//to +4
    {
        if(cur[i]==0)
        continue; 
        cur[i]=0;
        for(int cnt=0;cnt<=3;++cnt)
        {
            for(auto &arr:tmp[cnt])
            {
                if(check(cur,arr)==false)
                continue;
                if(check_trans(i-4,arr)==false)
                continue;
                if(arr[i-4])
                continue;
                for(int k=0;k<4;++k)
                {
                    out[k]+=arr[k];
                    cur[k]-=arr[k];
                }
                in[i-4]+=cnt;
                cur[i-4]+=cnt;
                dfs(cur,ans);
                for(int k=0;k<4;++k)
                {
                    out[k]-=arr[k];
                    cur[k]+=arr[k];
                }
                in[i-4]-=cnt;
                cur[i-4]-=cnt;
            }
        }
        cur[i]=1;
    }
bool ok=true;
    for(int i=4;i<8;++i)
    if(cur[i])
    ok=false;
    if(ok)
    if(cur[8])
    {
        cur[8]=0;
        for(int i=0;i<4;++i)//from
        {
            if(in[i])
            continue;
            if(cur[i]==0)
            continue;
            //cout<<"use 8"<<endl;
            --cur[i];
            ++cur[10];
            dfs(cur,ans);
            ++cur[i];
            --cur[10];
        }
        cur[8]=1;
    }
    if(ok)
    if(cur[9])
    {
        cur[9]=0;
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<5;++j)
            {
                int from=i;
                int to=j;
                if(to==4)
                    to=10;
                if(cur[from]==0)
                continue;
                if(in[from])
                continue;
                if(out[to])
                continue;
                ++out[from];
                ++in[to];
                --cur[from];
                ++cur[to];
                dfs(cur,ans);
                --out[from];
                --in[to];
                ++cur[from];
                --cur[to];
            }
        }
        cur[9]=1;
    }
}
void Lonelyper(){
    int n;
    cin>>n;
    vector<int> cards(4,0);
    vector<int> cur(11,0);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        string temp;
        cin>>temp;
        if(temp[1]=='D')
        ++cur[0];
        if(temp[1]=='C')
        ++cur[1];
        if(temp[1]=='H')
        ++cur[2];
        if(temp[1]=='S')
        ++cur[3];
    }
    for(int &x:cards)
    {
        while(x>=5)
        {
            ++ans;
            x-=5;
        }
    }
    int max_score=0;
    for(int x:cards)
    max_score+=x;
    max_score/=5;
    max_score-=ans;
    best_score=max_score;
    // 4 card 6 tarror 1 master

    for(int i=4;i<10;++i)
    cin>>cur[i];
    /*for(int x:cur)
    cout<<x<<" ";
    cout<<endl;*/

    dfs(cur,ans);
    cout<<ans<<endl;

}
void make_mp(vector<int> cur,int dep,int target)
{
    if(dep==target)
    {
        mp[target].insert(cur);
        return;
    }
    for(int i=0;i<4;++i)
    {
        cur[i]++;
        make_mp(cur,dep+1,target);
        cur[i]--;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    vector<int> cur(4,0);
    for(int i=0;i<=3;++i)
        make_mp(cur,0,i);
    //map<int,set<vector<int>>> mp;
    //vector<vector<vector<int>>> tmp(4,vector<vector<int>>(4));
    for(int i=0;i<4;++i)
    {
        for(auto arr:mp[i])
        {
        tmp[i].push_back(arr);
        }
    }
    while(t --){
        st.clear();
        Lonelyper();
    }
    return 0;
}