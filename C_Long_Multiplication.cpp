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
    string num1,num2;
    cin>>num1;
    cin>>num2;
    //3916
    //3582
    //分类讨论

    //当前数位相同
    ////之前数位较大 一定不换
    ////之前数位较小 一定换
    ///之前相同
    ////之后数位较大 一定换
    ////之后数位较小 一定不换
    //当前数位不同
    ////之前数位较大
    ////之后数位较大
    bool snap=false;
    for(int i=0;i<num1.size();++i){
        if(num1[i]==num2[i]){
            continue;
        }
        if(num1[i]<num2[i]){
            if(!snap){
                swap(num1[i],num2[i]);
                snap=true;
            }
            else{
                continue;
            }
        }
        else{
            if(snap){
                swap(num1[i],num2[i]);
            }
            snap=true;
        }
    }
    cout<<num1<<endl;
    cout<<num2<<endl;
    
}