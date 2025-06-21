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


int c(int n,int a){
    int left=a;
    int right=n-a+1;

    return max(left,right);
}
int c2(int n,int a){
    int left=a;
    int right=n-a+1;

    return min(left,right);
}
int cal(int n,int m){
    int ans=1;
    while(n!=1){
        n=c2(n,n/2+n%2);
        ++ans;
    }
    while(m!=1){
        m=c2(m,m/2+m%2);
        ++ans;
    }
    return ans;
}
void compete_solution()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    
    int n1=n,m1=c2(m,b);

    int n2=c2(n,a),m2=m;
    //cout<<n1<<" "<<m1<<endl;
    //cout<<n2<<" "<<m2<<endl;
    int rst=0x3f3f3f3f;
    rst=min(rst,cal(n1,m1));
    rst=min(rst,cal(n2,m2));
    cout<<rst<<endl;



    
}