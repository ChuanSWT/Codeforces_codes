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
void compete_solution()
{
    int n;
    cin >> n;
    int mod=998244353;
    vector<int> nums=cin_nums(n);
    for(auto&x:nums){
        --x;
    }
    int ans=0;
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i=0;i<dp.size();++i){
        int val=nums[i];
        if(val==2){
            
            if(i!=0){
                ans+=dp[i-1][1];
                ans%=mod;
                dp[i][0]+=dp[i-1][0];
                dp[i][0]%=mod;
                dp[i][1]+=dp[i-1][1];
                dp[i][1]%=mod;
            }
            continue;
        }
        if(i!=0){
        dp[i][0]+=dp[i-1][0];
        dp[i][0]%=mod;
        dp[i][1]+=dp[i-1][1];
        dp[i][1]%=mod;
        }
        if(val==0)
        {
        dp[i][0]+=1;
        dp[i][0]%=mod;
        }
        if(i!=0&&val==1)
        {
            dp[i][1]+=dp[i-1][0];
            dp[i][1]%=mod;
            dp[i][1]+=dp[i-1][1];
            dp[i][1]%=mod;
        }
    }
    cout<<ans<<endl;
}