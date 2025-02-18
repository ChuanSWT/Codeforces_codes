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
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    for(auto &x:nums)
    x=abs(x);
    map<int,int> mp;
    for(int x:nums)
    ++mp[x];

    int one=0;
    int two=0;
    for(auto p:mp)
    {
        if(p.second==1)
        ++one;
        else
        ++two;
    }
    vector<int> nums1;
    for(int i=0;i<one+two;++i)
    nums1.push_back(1);
    for(int i=0;i<two;++i)
    nums1.push_back(-1);
    vector<int> nums2;
    for(int i=0;i<two;++i)
    {
        nums2.push_back(1);
        nums2.push_back(-1);
    }
    for(int i=0;i<one;++i)
        nums2.push_back(1);
    for(int i=1;i<nums1.size();++i)
        nums1[i]+=nums1[i-1];
    for(int i=1;i<nums2.size();++i)
        nums2[i]+=nums2[i-1];
    print(nums1);
    print(nums2);
    
}