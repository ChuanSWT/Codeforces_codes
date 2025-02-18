#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
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
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    //以某位为结尾 他说的为真 对应的方案数
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][1]=1;
    if(nums[0]==0){
        dp[0][0]=1;
    }
    for(int i=1;i<dp.size();++i){
        //t->t
        if(nums[i]==nums[i-1]){
            dp[i][0]+=dp[i-1][0];
            dp[i][0]%=mod;
        }
        //t->f
        dp[i][1]+=dp[i-1][0];
        dp[i][1]%=mod;
        //f->t
        if((i!=1&&nums[i]-nums[i-2]==1)||(i==1&&nums[i]==1)){
            dp[i][0]+=dp[i-1][1];
            dp[i][0]%=mod;
        }
    }
    //for(auto arr:dp)
    //print(arr);
    cout<<(dp.back()[0]+dp.back()[1])%mod<<endl;

}