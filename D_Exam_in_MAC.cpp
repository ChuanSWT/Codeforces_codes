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
int cal_mex(vector<int> nums){
    set<int> st;
    for(int x:nums)
    st.insert(x);
    int ans=0;
    while(st.find(ans)!=st.end())
        ++ans;
    return ans;
}
static bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
void compete_solution()
{
    int n,c;
    cin>>n>>c;
    vector<int> nums=cin_nums(n);
    //找出 (x,y),x和y都在[0,c],且y+x和y-x都不在集合中
    //而且y>=x
    //有点像容斥
    int ans=(c+1+1)*(c+1)/2;
    //cout<<ans<<endl;
    /*ans=0;
    for(int x=0;x<=c;++x){
        for(int y=x;y<=c;++y)
        ++ans;
    }*/
    // 4
    // 1 3
    // 2 2
    // 5
    // 1 4
    // 2 3
    int odd=0;
    int even=0;
    for(int x:nums)
    {
        if(x%2==0)
            ++even;
        else
            ++odd;
    }
    ans+=(odd)*(odd-1ll)/2ll;
    ans+=(even)*(even-1ll)/2ll;
    ans-=n;
    for(int x:nums)
    {
        ans-=c-x;
        ans-=x/2ll;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;


}