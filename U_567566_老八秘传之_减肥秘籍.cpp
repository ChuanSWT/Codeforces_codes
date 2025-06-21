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


void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums=cin_nums(n);

    map<int,int> mp;
    for(int x:nums)
        ++mp[x];

    vector<int> dp(m+1,-0x3f3f3f3f);
    dp[0]=0;
    for(auto p:mp){
        int val=p.first,cnt=p.second;
        for(int i=m;i>=0;--i){
            if(i-val*cnt>=0){
                dp[i]=max(dp[i],dp[i-val*cnt]+cnt);
            }
        }
    }
    int ans=*max_element(dp.begin(),dp.end());
    cout<<ans<<endl;



    
}