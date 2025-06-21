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



bool check1(vector<int> nums){
    for(int x:nums){
        if(x==0)
            return false;
    }
    return true;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    if(check1(nums)){
        cout<<"YES"<<endl;
            return;
    }
    //只需要关注两侧?
    //1 0 1
    //3 2 3
    for(int i=1;i<nums.size();++i){
        if(nums[i]==0&&nums[i-1]==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;







    
}