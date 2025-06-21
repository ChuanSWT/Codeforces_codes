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
    cin >> t;
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


bool check(vector<int> nums,int k){
    sort(nums.begin(),nums.end());
    --nums.back();
    sort(nums.begin(),nums.end());
    if(nums.back()-nums[0]>k)
        return true;
    return false;
}

void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<int> nums=cin_nums(n);
    sort(nums.begin(),nums.end());
    if(check(nums,k)){
        cout<<"Jerry"<<endl;
        return;
    }
    int sum=accumulate(nums.begin(),nums.end(),0ll);
    if(sum%2){
        cout<<"Tom"<<endl;
    }
    else{
        cout<<"Jerry"<<endl;
    }





    
}