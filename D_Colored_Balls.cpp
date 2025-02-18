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
    //cin >> roundc;
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
bool check(vector<int> nums){
    for(int i=0;i<nums.size();++i)
        if(nums[0]!=nums[i])
            return false;

    return true;
}
int mod=998244353;
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    sort(nums.begin(),nums.end());
    //有两种成组方式，要么单独放，要么放两个不同的
    //特别的，对于只有一种颜色，答案为颜色的球数
    //01 01 1 1==4
    //02 02 2 2==4
    //01 02 01 02 12 12==6
    //最坏情况5e3个球[题目特别限制]
    //动态规划
    //1e3 6e3 6e3
    //以这个颜色为结束 能获得的组数中 单个球的组的数量的 对应方法数
    //前缀和优化？
    //！背包 在这之前能填多少 当前又为多少 的方法数
    //
    int ans=0;
    vector<int> dp(6000,0);
    dp[0]=1;
    for(int i=0;i<nums.size();++i){
        int cur=nums[i];
        for(int j=0;j<dp.size();++j){
            if(cur>=j)
                ans+=cur*dp[j];
            else{
                ans+=((cur+j)/2+(cur+j)%2)*dp[j];
            }
            ans%=mod;
        }

        for(int j=dp.size()-1;j>=0;--j){
            if(j-cur>=0)
            {
                dp[j]+=dp[j-cur];
                dp[j]%=mod;
            }
        }
        //print(dp);
    }
    ans%=mod;
    cout<<ans<<endl;
}
//2 1 1
//