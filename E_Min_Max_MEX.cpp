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


int cal(vector<int> &nums,int target){
    vector<int> st(target,1);
    vector<int> cur_st=st;
    int ans=0;
    int cur=target;
    for(int x:nums){
        if(x>=target)
            continue;
        if(cur_st[x])
            --cur;
        cur_st[x]=0;
        if(cur==0){
            cur_st=st;
            cur=target;
            ++ans;
        }
    }
    return ans;
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<int> nums=cin_nums(n);
    int left=1,right=n+1;
    while(left<right){
        int mid=(left+right)/2;
        if(cal(nums,mid)<k){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    cout<<left-1<<endl;


    
}