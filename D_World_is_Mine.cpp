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
using namespace std;
    template <typename T>
    void print(const std::vector<T>& vec) {
    for (auto element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    }
void compete_solution();
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int roundc;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
vector<vector<int>> *dp;
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < nums.size(); ++i)
        cin >> nums[i];
    map<int, int> mp;
    for (int num : nums)
        mp[num]++;

    nums.clear();
    for(auto p:mp)
    nums.push_back(p.second);
    vector<vector<int>> dp(nums.size()+1,vector<int>(5001,-1));
    dp[0][0]=0;//考虑到大下标，吃了多少蛋糕--最大预留了多少步
    for(int i=1;i<dp.size();++i)
    {
        for(int j=1;j<dp[0].size();++j)//给与，但是预留
        {
            if(dp[i-1][j-1]!=-1)
                dp[i][j]=dp[i-1][j-1]+1;
        }
        int cnt=nums[i-1];
        for(int j=1;j<dp[0].size();++j)//过掉这次
        {
            if(dp[i-1][j]==-1)
            continue;
            if(dp[i-1][j]>=cnt)
            dp[i][j]=max(dp[i][j],dp[i-1][j]-cnt);
            
        }
        
    }
    /*for(auto arr:dp)
    print(arr);*/
    int minv=0x3f3f3f3f;
    for(int i=0;i<dp.back().size();++i)
    if(dp.back()[i]!=-1)
    minv=min(minv,i);
    cout<<minv<<endl;


    
}