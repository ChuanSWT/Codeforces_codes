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
    vector<vector<int>> querys=cin_edges(n,2);
    set<int> st;
    vector<int> pre_sum(2*n+1,0);
    map<int,int> mp;//针对于原子
    for(auto arr:querys)
        if(arr[0]==arr[1])
        {
            ++mp[arr[0]];
            pre_sum[arr[0]]=1;
        }
    for(int i=1;i<pre_sum.size();++i)
    {
        pre_sum[i]+=pre_sum[i-1];
    }
    string ans;
    for(auto arr:querys)
    {
        int left=arr[0];
        int right=arr[1];
        if(left==right)
        {
            if(mp[left]==1)
                ans+='1';
            else
                ans+='0';
            continue;
        }
        int sum=pre_sum[right];
        sum-=pre_sum[left-1];
        int length=right-left+1;
        if(length==sum)
        ans+='0';
            else
        ans+='1';
    }
    cout<<ans<<endl;
    

    
}