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



int cal(int sum0,int maxv1,int temp1){
    temp1-=maxv1/2*2;
    sum0+=temp1;
    int ans=maxv1+sum0;
    return ans;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    int odd_cnt=0;
    int odd_sum=0,even_sum=0;
    int odd_max=0,even_max=0;
    int temp0=0,temp1=0;
    for(int x:nums){
        if(x%2){
            ++odd_cnt;
            odd_sum+=x;
            odd_max=max(odd_max,x);
            temp1+=x/2*2;
        }
        else{
            even_sum+=x;
            even_max=max(even_max,x);
            temp0+=x;
        }
    }
    if(odd_sum==0){
        cout<<even_max<<endl;
        return;
    }
    if(even_sum==0){
        cout<<odd_max<<endl;
        return;
    }
    int ans1=cal(even_sum,odd_max,temp1);//供给给奇数
    int ans2=temp0+odd_sum-odd_cnt;

    int ans=max({ans1,ans2});
    
    cout<<ans<<endl;
    /*cout<<odd_sum<<even_max<<temp0<<endl;
    int ans1=cal(odd_sum,even_max,temp0);
    int ans2=cal(even_sum,odd_max,temp1);
    cout<<ans1<<" "<<ans2<<endl;
    cout<<max(ans1,ans2)<<endl;*/
    //cout<<max(odd_max+even_sum+temp1,even_max+odd_sum+temp0)<<endl;
    
}