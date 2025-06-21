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




void compete_solution()
{
    int n,m;
    cin >> n>>m;
    vector<int> fib(11,0);
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<fib.size();++i){
        fib[i]=fib[i-1]+fib[i-2];
    }
    vector<vector<int>> queries=cin_matrix(m,3);

    string ans;
    for(auto arr:queries){
        sort(arr.begin(),arr.end());
        int x=arr[0],y=arr[1],z=arr[2];
        int len1=fib[n];
        int len2=fib[n-1];
        if(len1+len2>z||len1>x||len1>y){
            ans+='0';
        }
        else{
            ans+='1';
        }
    }
    cout<<ans<<endl;




    
}