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

//计算前缀和(包含)
int cal(vector<int> &nums,int mid){
    int n=nums.size();
    int sum=accumulate(nums.begin(),nums.end(),0ll);
    int ans=0;
    ans+=mid/n*sum;
    mid%=n;
    for(int i=0;i<mid;++i){
        ans+=nums[i];
    }
    return ans;

}

void compete_solution()
{
    int n,k,x;
    cin >> n>>k>>x;
    vector<int> nums=cin_nums(n);
    int sum=accumulate(nums.begin(),nums.end(),0ll)*k;
    int left=0,right=n*k;
    while(left<right){
        int mid=(left+right)/2;
        int rst=cal(nums,mid);
        if(sum-rst>=x){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    cout<<left<<endl;
    

    
}