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
vector<int> make(int n)
{
    vector<int> ans(n);
    int cur=0;
    int left=0,right=n-1;
    bool flag=true;
    int cur=1;
    while(left<=right)
    {  
        if(flag)
        {
            ans[left]=cur;
            ++left;
            ++cur;
            flag=false;
        }
        else
        {
            ans[right]=cur;
            --right;
            ++cur;
            flag=true;
        }
    }
    return ans;
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<int> ans(n,-1);
    ans=make(n);
    





    
}