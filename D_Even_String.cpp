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
#define ll long long
#define mod 998244353
#define MOD 998244353
#define int long long

using namespace std;
struct Comb {
    int n;
    vector<int> fac, inv_fac;

    Comb(int max_n) : n(max_n), fac(max_n + 1), inv_fac(max_n + 1) {
        build();
    }

    int qpow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void build() {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = fac[i - 1] * i % MOD;

        inv_fac[n] = qpow(fac[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }

    int C(int a, int b) {
        if (b < 0 || b > a) return 0;
        return fac[a] * inv_fac[b] % MOD * inv_fac[a - b] % MOD;
    }
};
void compete_solution();
Comb *test;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test=new Comb(5e5+10);
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


//brute
bool check(vector<int> &path){
    //print(path);
    for(int i=0;i<path.size();++i){
        for(int j=0;j<path.size();++j){
            if(path[i]==path[j]&&(i+j)%2){
                return false;
            }
        }
    }
    return true;
}

bool check_ultra(vector<int> nums){
    sort(nums.rbegin(),nums.rbegin());
    int sum=accumulate(nums.begin(),nums.end(),0ll);
    int limit=sum/2ll+sum%2ll;
    if(nums[0]>limit){
        return false;
    }
    return true;

}

void compete_solution()
{
    vector<int> nums=cin_nums(26);
    //print(nums);
    sort(nums.rbegin(),nums.rend());
    if(!check_ultra(nums)){
        cout<<0<<endl;
        return;
    }
    int sum=accumulate(nums.begin(),nums.end(),0ll);
    //如果存在一个数 大到能占满奇数位还剩余 则判为-1

    //一个数 要么全占偶数位 要么全占奇数位
    int odd=sum/2+sum%2;
    int even=sum/2;
    int cur_sum=0;
    //进度 odd 选择的数目 对应的方法数
    vector<vector<int>> dp(27,vector<int>(odd+1,0));
    dp[0][0]=1;
    for(int i=1;i<dp.size();++i){
        int val=nums[i-1];
        
        if(val==0){
            for(int j=0;j<dp[0].size();++j){
                dp[i][j]+=dp[i-1][j];
            }
            continue;
        }
        
        cur_sum+=val;
        for(int j=dp[0].size()-1;j>=0;--j){
            if(j-val<0)
                continue;
            //cout<<odd<<" "<<j<<" "<<val<<endl;
            int meth=test->C(odd-(j-val),val);
            dp[i][j]+=dp[i-1][j-val]*meth;
            dp[i][j]%=mod;
        }
        for(int j=0;j<dp[0].size();++j){
            //cout<<j<<endl;
            int even_left=cur_sum-j;
            
            if(even_left<val||even_left>even)
                continue;
            int meth=test->C(even_left,val);
            dp[i][j]+=dp[i-1][j]*meth;
            dp[i][j]%=mod;
        }
    }
    /*for(auto arr:dp){
        print(arr);
    }*/
    cout<<dp.back().back()<<endl;
    

}