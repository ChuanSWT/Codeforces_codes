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
vector<int> primes;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    vector<int> mark(1e7+10,0);
    for(int i=2;i<mark.size();++i){
        if(mark[i])
            continue;
        for(int j=i*2;j<mark.size();j+=i){
            mark[j]=1;
        }
    }
    for(int i=2;i<mark.size();++i){
        if(mark[i]==0)
            primes.push_back(i);
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
int lcm(int x,int y){
    return x*y/gcd(x,y);
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
bool is_prime(int x){
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}



void compete_solution()
{
    int n   ;
    cin >> n;
    /*for(int a=1;a<=n;++a){
        for(int b=a+1;b<=n;++b){
            if(lcm(a,b)%gcd(a,b))
                continue;
            if(is_prime(lcm(a,b)/gcd(a,b))){
                cout<<a<<" "<<b<<endl;
                cout<<lcm(a,b)/gcd(a,b)<<endl;
            }
        }
    }*/
    //n,prime*n
    int ans=0;
    for(int i=1;i*2<=n;++i){
        int left=0,right=primes.size();
        while(left<right){
            int mid=(left+right)/2;
            if(i*primes[mid]<=n){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        ans+=left;
    }
    cout<<ans<<'\n';

    
}