#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long

using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        compete_solution();
    }
    return 0;
}
void debug(int n){
    cout<<n<<endl;
}
template <typename T>
void print(const std::vector<T> &vec)
{
    for (auto element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

vector<int> cin_nums(int n)
{
    vector<int> ans(n);
    for (auto &x : ans)
        cin >> x;
    return ans;
}
vector<vector<int>> cin_matrix(int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto &arr : ans)
    {
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
    }
    return ans;
}



class graphMeth
{
public:
    int n;
    vector<vector<int>> edges;
    vector<int> nums;
    // default
    graphMeth(int sz, vector<vector<int>> raw_edges) : edges(sz), n(sz)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
    // 点权
    graphMeth(int sz, vector<vector<int>> raw_edges, vector<int> vals) : edges(sz), n(sz), nums(vals)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
};
bool check(map<int,int>& mp,vector<int> cnt){
    for(int i=0;i<26;++i){
        if(mp[i]<cnt[i])
            return false;
    }
    return true;
}
void compete_solution()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> o_mark(n,0);
    int cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]!=s[n-1-i]){
            o_mark[i]=1;
            ++cnt;
        }
    }
    cnt/=2;
    if(cnt==0){
        cout<<0<<endl;
        return;
    }
    int left=0,right=n-1;
    vector<int> nums;
    vector<int> mark;
    while(s[left]==s[right]){
        ++left;
        --right;
    }
    for(int i=left;i<=right;++i){
        nums.push_back(s[i]-'a');
        mark.push_back(o_mark[i]);
    }
    int m=nums.size();
    vector<vector<int>> pre_sum(m,vector<int>(26,0));
    for(int i=0;i<pre_sum.size();++i){
        if(mark[i])
        pre_sum[i][nums[i]]++;
        if(i!=0)
        for(int j=0;j<26;++j){
            pre_sum[i][j]+=pre_sum[i-1][j];
        }
    }
    //print(mark);
    map<int,int> mp1;
    int minv=0x3f3f3f3f;
    int temp=cnt;
    for(int i=0;i<nums.size();++i){
        if(mark[i]){
            mp1[nums[i]]++;
            --temp;
            }
        else
            if(i>=m/2){
                mp1[nums[i]]+=2;
            }
            if(temp>0)
                continue;
        //debug(i);
        
        vector<int> cnt=pre_sum.back();
        for(int j=0;j<26;++j){
            cnt[j]-=pre_sum[i][j];
        }
        if(check(mp1,cnt)){
            minv=min(minv,i+1);
            break;
        }
    }
    //cout<<minv<<endl;
    reverse(nums.begin(),nums.end());
    reverse(mark.begin(),mark.end());
    temp=cnt;
    vector<vector<int>> pre_sum2(m,vector<int>(26,0));
    for(int i=0;i<pre_sum2.size();++i){
        if(mark[i])
        pre_sum2[i][nums[i]]++;

        if(i!=0)
        for(int j=0;j<26;++j){
            pre_sum2[i][j]+=pre_sum2[i-1][j];
        }
    }
    mp1.clear();
    for(int i=0;i<nums.size();++i){
        if(mark[i]){
            ++mp1[nums[i]];
            --temp;
        }
        else
            if(i>=m/2){
                mp1[nums[i]]+=2;
            }
        if(temp>0)
            continue;
        vector<int> cnt=pre_sum2.back();
        for(int j=0;j<26;++j){
            cnt[j]-=pre_sum2[i][j];
        }
        if(check(mp1,cnt)){
            minv=min(minv,i+1);
            break;
        }
    }
    cout<<minv<<endl;
}