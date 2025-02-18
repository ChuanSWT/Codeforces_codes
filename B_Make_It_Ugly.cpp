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
bool check(vector<int> nums){
    for(int i=0;i<nums.size();++i)
        if(nums[0]!=nums[i])
            return false;

    return true;
}
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    //全部相同？
    if(check(nums)){
        cout<<-1<<endl;
        return;
    }
    //2 2 1 2 2 2 2 优先删除短
    //找到最长子数组？
    //题目保证是好看数组
    int cur=0;
    int minv=0x3f3f3f3f;
    nums.push_back(-1);
    for(int i=0;i<nums.size();++i){
        if(nums[i]==nums[0]){
            ++cur;
        }
        else{
            if(cur!=0)
                minv=min(minv,cur);
            cur=0;
        }
    }
    cout<<minv<<endl;
    //题目给出的数组首尾肯定相同
    //其余数字只能孤立
    //2 1 1 1 2 2

    
}