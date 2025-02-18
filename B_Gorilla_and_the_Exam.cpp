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

int cal(int left,int right)
{
    int maxv = 0;
    for (int i = left; i <= right; ++i)
    {
        for (int j = i + 1; j <= right; ++j)
        {
            for (int k = j + 1; k <= right; ++k)
                maxv = max(maxv, (i ^ j) + (j ^ k) + (i ^ k));
        }
    }
    return maxv;
}
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
    int n,k;
    cin>>n>>k;
    vector<int> nums=cin_nums(n);
    map<int,int> mp;
    for(int x:nums)
    ++mp[x];
    int ans=mp.size();
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto p:mp)
    pq.push(p.second);
    while(pq.size()&&k>=pq.top())
    {
        k-=pq.top();
        pq.pop();
        --ans;
    }
    cout<<max(ans,1ll)<<endl;

}