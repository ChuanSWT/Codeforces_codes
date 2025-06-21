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
int cal(int x){
    int ans=0;
    while(x){
        ans+=(x&1);
        x>>=1;
    }
    return 1<<ans;
}
int makeInt(int mask,int x){
    int ans=0;
    int index=0;
    for(int i=0;i<=30;++i){
        if((1<<i)&x){
            if((1<<index)&mask){
                ans|=(1<<i);
            }
            ++index;
        }
    }
    return ans;
}
void compete_solution()
{
    int n,x;
    cin >> n>>x;
    
    int rst=cal(x);
    vector<int> nums;
    for(int i=0;i<rst&&i<n;++i){
        nums.push_back(makeInt(i,x));
    }
    while(nums.size()<n){
        nums.push_back(0);
    }
    int or_sum=0;
    for(int x:nums) or_sum|=x;
    if(or_sum==x){
        print(nums);
    }
    else{
        nums.back()=x;
        print(nums);
    }

}