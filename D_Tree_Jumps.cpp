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
int mod=998244353;
//记忆化搜索？
void dfs(int cur,int dep,map<int,vector<int>> &ans,vector<vector<int>>&edges,int pre){
    ans[dep].push_back(cur);
    for(int x:edges[cur]){
        if(x==pre)
            continue;
        dfs(x,dep+1,ans,edges,cur);
    }
}

void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n-1);
    
    vector<vector<int>> edges(n);
    //set<vector<int>> st;
    for(int i=0;i<nums.size();++i){
        edges[nums[i]-1].push_back(i+1);
        edges[i+1].push_back(nums[i]-1);
        //st.insert({i+1,nums[i]-1});
        //st.insert({nums[i]-1,i+1});
    }  
    for(int&x:nums)
        --x;
    /*vector<vector<int>> edges(n);
    set<vector<int>> st;
    for(int i=0;i<nums.size();++i){
        edges[nums[i]-1].push_back(i+1);
        edges[i+1].push_back(nums[i]-1);
        st.insert({i+1,nums[i]-1});
        st.insert({nums[i]-1,i+1});
    }   */
    map<int,vector<int>> dep;
    dfs(0,0,dep,edges,-1);
    
    vector<int> minus(n,0);
    map<int,int> dep_deserve;
    priority_queue<vector<int>> pq;
    for(auto [d,arr]:dep){
        for(int x:arr){
            pq.push({d,x});
        }
    }
    while(pq.size()){
        auto arr=pq.top();
        //print(arr);
        pq.pop();
        int cur=arr[1];
        int deep=arr[0];
        if(cur==0)
            break;
        int sum=1;
        sum+=dep_deserve[deep];
        sum%=mod;
        sum-=minus[cur];
        sum+=mod;sum+=mod;
        sum%=mod;
        minus[nums[cur-1]]+=sum;
        minus[nums[cur-1]]%=mod;
        dep_deserve[deep-1]+=sum;
        dep_deserve[deep-1]%=mod;
    }
    cout<<(dep_deserve[0]+1)%mod<<endl;
    //深度 节点
}