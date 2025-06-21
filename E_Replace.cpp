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
#include <assert.h>
#define int long long

using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
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

//检测环的大小
int check(int cur,vector<int> &cedges){
    set<int> st;
    st.insert(cur);
    while(cedges[cur]!=-1){
        cur=cedges[cur];
        if(st.count(cur)){
            if(cedges[cur]==cur)
                return 1;
            st.insert(cur);
            return st.size();
        }
        st.insert(cur);
    }
    return 0;
}

void compete_solution()
{
    int n;
    cin >> n;
    string s,t;
    cin>>s>>t;
    vector<int> nums1(n);
    for(int i=0;i<s.size();++i){
        nums1[i]=s[i]-'a';
    }
    vector<int> nums2(n);
    for(int i=0;i<t.size();++i){
        nums2[i]=t[i]-'a';
    }
    //只有一个出度
    //只有简单环 定点数+1
    //链条: 定点数-1
    vector<set<int>> edges(26);
    vector<int> cedges(26,-1);//肯定是-1或单个元素
    for(int i=0;i<nums1.size();++i){
        int x=nums1[i];
        int y=nums2[i];
        if(cedges[x]!=-1&&cedges[x]!=y){
            cout<<-1<<endl;
            return;
        }
        cedges[x]=y;

        edges[x].insert(y);
        edges[y].insert(x);
    }
    //print(cedges);
    //26个顶点的图
    int bad_cnt=0;
    vector<int> mark(26,0);
    int ans=0;
    for(int i=0;i<26;++i){
        if(mark[i])
            continue;
        //首先看有多大 
        set<int> st;
        queue<int> qu;
        qu.push(i);
        mark[i]=1;
        while(qu.size()){
            int node=qu.front();
            qu.pop();
            st.insert(node);
            for(int x:edges[node]){
                if(mark[x])
                    continue;
                mark[x]=1;
                qu.push(x);
            }
        }
        int minv=0x3f3f3f3f;
        for(int x:st){
            int rst=check(x,cedges);

            minv=min(minv,rst);
        }
        bad_cnt+=minv;
        if(st.size()==1)
            continue;
        if(minv==st.size()){
            ans+=st.size()+1;
        }
        else{
            if(minv==0)
                ans+=st.size()-1;
            else
                ans+=(int)st.size();
        }

    }
    //print(mark);
    //cout<<bad_cnt<<endl;
    if(bad_cnt==26){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;




    
}