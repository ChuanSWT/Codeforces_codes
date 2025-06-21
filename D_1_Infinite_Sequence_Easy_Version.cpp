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

vector<int> simu1(int n,vector<int> nums,int wanted){
    vector<int> ans=nums;
    for(int i=n+1;i<=wanted;++i){
        int sum=0;
        for(int j=1;j<=i/2;++j){
            sum^=ans[j-1];
        }
        ans.push_back(sum);
    }
    return ans;
}
vector<int> simu2(int n,vector<int> nums,int wanted){
    vector<int> ans(wanted,0);
    ans[0]=1;
    for(int i=1;i<=wanted;++i){
        int val=ans[i-1];
        for(int j=i+1;j<=wanted;++j){
            if(j/2>=i){
                ans[j-1]+=val;
            }
        }
    }
    return ans;
}
bool check(int target,int x){
    for(int i=0;i<=30;++i){
        if((target&(1<<i))<(x&(1<<i)))
            return false;
    }
    return true;
}
int dfs(int m, int n, int sum, vector<int>& pre_sum) {
    if (m<=n) 
        return pre_sum[m];
    //触底
    if(m%2==0){
        return sum^dfs(m>>1,n,sum,pre_sum);
    }
    return sum;
}
void compete_solution()
{
    int n,l1,r1;
    cin >> n>>l1>>r1;
    vector<int> nums=cin_nums(n);
    
    int target=l1;
    if(target<=n){
        cout<<nums[target-1]<<endl;
        return;
    }
    //下标从1开始
    //1 1 1 0 
    /* auto rst1=simu1(n,nums,87);
    print(rst1);
    auto rst2=simu1(n,nums,87);
    print(rst2);
    for(int i=1;i<rst1.size();i+=2){
        if(!rst1[i]){
            cout<<i+1<<endl;
        }
    }*/
    //考虑有哪些前缀可以在此发挥作用？
    int ans=0;
    vector<int> pre_sum=nums;
    for(int i=1;i<pre_sum.size();++i){
        pre_sum[i]^=pre_sum[i-1];
    }
    //从此开始对齐到1
    pre_sum.insert(pre_sum.begin(),0);
    //cout<<100000000000ll/2<<endl;
    if(n%2==0){
        int rst=dfs(target/2ll,n,pre_sum.back()^pre_sum[n/2],pre_sum);
        cout<<rst<<endl;
    }
    else{
        int rst=dfs(target/2ll,n,pre_sum.back(),pre_sum);
        cout<<rst<<endl;
    }
    
}