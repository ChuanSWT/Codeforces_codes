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
int cal(int n)
{
    if(n==0)
    return 0;
    //1 1
    //2 2
    //3 2
    //4 3
    //5 3
    //6 4
    //7 4
    return n/2+1;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> raw_nums=cin_nums(n);
    //会对之前进行压缩
    raw_nums.push_back(2);
    vector<int> nums;
    int cur=0;
    for(int i=0;i<raw_nums.size();++i)
    {
        if(raw_nums[i]==1)
        ++cur;
        else
        {
            nums.push_back(cur);
            cur=0;
        }
    }
    //对于x只鸟，最大必须占用的牢笼数？
    int maxv=0;
    int sum=0;
    int cnt=0;
    for(int x:nums)
    {
        maxv=max(maxv,sum+x);
        cnt+=x;
        sum=cal(cnt);
    }
    cout<<maxv<<endl;
    
}