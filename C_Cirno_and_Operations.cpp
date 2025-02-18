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
vector<vector<int>> make(int n)
{
    vector<vector<int>> ans(n, vector<int>(n + 1, 0));
    ans[0][0] = 1;

    for (int i = 1; i < n; ++i)
    {
        ans[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}
int cal(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> rst = make(n);
    vector<int> arr;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i % 2 == 0)
            arr.push_back(rst.back()[i]);
        else
            arr.push_back(-rst.back()[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i] * nums[i];
    }
    return abs(sum);
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums = cin_nums(n);
    if (nums.size() == 1)
    {
        cout << nums[0] << endl;
        return;
    }
    int ans = accumulate(nums.begin(), nums.end(), 0ll);
    // 任意重排元素 //任意计算区间差值 //可以不执行操作
    // 9 7 9 -9 9 -8 7 -8 9
    //-9 -8 -8
    // 7 7 8 9 9 9
    // 最好让正数和负数进行运算?
    //-9 9 -8 9 -8 9 8 7 7
    // 18 -17 17 -17 17 8 7 7
    //-17 18 -17 17 17 8 7 7
    // 35 -35 34 17 8 7 7
    /// 最后一个最大值似乎无法被继承
    //-9 9 -8 9 -8 9 7 8 8
    // 18 -17 17 -17 17 -2 8 8
    //-17 18 -17 17 -2 17 8 8
    // 35 -35 34 -19 -9 8
    //-35 35 -19 34 -9 8
    // 70 -54 53 -43 17
    //-134 107 -96 60
    // 241 -203 156
    // 不够
    // 绝对值增加一定好吗？
    // 需要尽量快速均摊绝对
    //-9 -8 -8
    // 7 7 8 9 9 9
    // 787878787878.....
    //-1 1 -1 1.....
    // 2 -2 2 -2..4..8..16
    //题读假了md
    //9 7 9 -9 9 -8 7 -8 9
    //-2 2 18 -18 -17 15 -15 17
    while(nums.size()>=1){
        vector<int> newArr;
        for(int i=1;i<nums.size();++i){
            newArr.push_back(nums[i]-nums[i-1]);
        }
        ans=max(ans,abs(accumulate(newArr.begin(),newArr.end(),0ll)));
        nums=newArr;
    }
    cout<<ans<<endl;
}