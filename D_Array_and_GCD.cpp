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
vector<int> pre_prime_sum;
void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    vector<int> d(6e6,0);
    for(int i=2;i<d.size();++i){
        if(d[i])    
            continue;
        for(int j=i+i;j<d.size();j+=i){
            d[j]=1;
        }
    }
    for(int i=2;i<d.size();++i){
        if(d[i]==0)
        pre_prime_sum.push_back(i);
    }
    for(int i=1;i<pre_prime_sum.size();++i){
        pre_prime_sum[i]+=pre_prime_sum[i-1];
    }
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




void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    sort(nums.rbegin(),nums.rend());
    cout<<pre_prime_sum.size()<<endl;
    int maxv=0;
    int sum=0;
    //print(pre_prime_sum);
    for(int i=0;i<nums.size();++i){
        sum+=nums[i];
        if(sum>=pre_prime_sum[i])
            maxv=max(maxv,i);
    }
    cout<<n-(maxv+1)<<endl;





    
}