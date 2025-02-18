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
/*int cal(vector<int> &pre_sum,int left,int right,int time)
{
    left+=time;
    right+=time;
    left+=pre_sum.size();
    left%=pre_sum.size();
    right+=pre_sum.size();
    right%=pre_sum.size();
    if(left<=right)
    {
        int ans=0;
        ans+=pre_sum[right];
        if(left!=0)
        ans-=pre_sum[left-1];

        return ans;
    }
    //right left
    int ans=0;
    ans+=pre_sum[right];
    ans+=pre_sum.back();
    if(left!=0)
    ans-=pre_sum[left-1];
    return ans;
}*/
void compete_solution()
{
    int inf=0x3f3f3f3f3f3f3f3f;
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m));
    for(auto &arr:grid)
    arr=cin_nums(m);

    vector<vector<vector<int>>> lines(n);
    for(int i=0;i<lines.size();++i)
    {
        vector<int>arr=grid[i];
        for(int j=0;j<m;++j)
        {
            lines[i].push_back(arr);
            int bg=arr[0];
            for(int k=1;k<arr.size();++k)
                arr[k-1]=arr[k];
            arr.back()=bg;
        }
    }
    //行 偏移次数 结束位置 的最小花费
    vector<vector<vector<int>>> dp0(n+1,vector<vector<int>>(m,vector<int>(m,inf)));
    //上一行汇总
    vector<vector<int>> dp(n+1,vector<int>(m,inf));
    dp[0][0]=0;
    dp0[0][0][0]=0;
    for(int x=1;x<dp.size();++x)
    {
        for(int shift=0;shift<m;++shift)
        {
            for(int y=0;y<dp[0].size();++y)
            {
                if(y!=0)
                dp0[x][shift][y]=min(dp0[x][shift][y],dp0[x][shift][y-1]+lines[x-1][shift][y]);

                dp0[x][shift][y]=min(dp0[x][shift][y],dp[x-1][y]+lines[x-1][shift][y]+shift*k);
                dp[x][y]=min(dp[x][y],dp0[x][shift][y]);
                //for(auto arr:dp)
                //    print(arr);
            }
        }
    }
    //for(auto arr:dp)
    //print(arr);
    cout<<dp.back().back()<<endl;
    

    
}