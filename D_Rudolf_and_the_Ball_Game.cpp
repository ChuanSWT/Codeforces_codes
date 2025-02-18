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
void compete_solution()
{
    int n,m,start;
    cin>>n>>m>>start;
    --start;
    vector<pair<int,char>> queries(m);
    for(auto &p:queries)
        cin>>p.first>>p.second;
    vector<vector<int>> dp(m+1,vector<int>(n,0));
    dp[0][start]=1;
    for(int i=1;i<dp.size();++i){
        int d=queries[i-1].first;
        char op=queries[i-1].second;
        if(op=='0'||op=='?'){//顺时针
            for(int j=0;j<n;++j){
                dp[i][j]|=dp[i-1][(j-d+10*n)%n];
            }
        }
        if(op=='1'||op=='?'){
            for(int j=0;j<n;++j){
                dp[i][j]|=dp[i-1][(j+d+10*n)%n];
            }
        }

    }
    vector<int> ans;
    for(int i=0;i<dp[0].size();++i)
        if(dp.back()[i])
            ans.push_back(i+1);
    cout<<ans.size()<<endl;
    print(ans);


    
}