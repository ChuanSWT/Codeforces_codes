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



int mod=1e9+7;
int cal(vector<int>&a,vector<int>&b){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}
void compete_solution()
{
    int n;
    cin>>n;
    vector<vector<int>> points=cin_matrix(n,2);
    int q;
    cin>>q;
    vector<vector<int>> queries=cin_matrix(q,2);

    vector<vector<int>> dp(n,vector<int>(n,0));
    /*for(int left=0;left<dp.size();++left){
        for(int right=left+1;right<dp.size();++right){
            int maxv=0;
            for(int i=left;i<right;++i){
                maxv=max(maxv,cal(points[i],points[right]));
            }
            dp[left][right]=max(dp[left][right-1],maxv);
        }
    }
    for(auto arr:queries){
        int left=arr[0],right=arr[1];
        cout<<dp[left-1][right-1]<<endl;
    }*/
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=1;i<n;++i){
        dp[i-1][i]=cal(points[i-1],points[i]);
    }
    for(int len=3;len<=n;++len){
        for(int left=0,right=left+len-1;right<n;++left,++right){
            dp[left][right]=max({dp[left+1][right],dp[left][right-1],cal(points[left],points[right])});
        }
    }
    for(auto arr:queries){
        int left=arr[0],right=arr[1];
        cout<<dp[left-1][right-1]<<endl;
    }




    
}