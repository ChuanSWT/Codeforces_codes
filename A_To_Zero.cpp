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




void compete_solution()
{
    int n,k;
    cin >> n>>k;
    int cnt=0;
    if(n%2==0){
        if(k%2==0){
            cout<<n/k+(n%k!=0)<<endl;
        }
        else{
            //-odd -even
            cout<<n/(k-1)+(n%(k-1)!=0)<<endl;
        }
    }
    else{
        if(k%2==0){
            cnt+=1;
            n-=k-1;
            cout<<cnt+n/k+(n%k!=0)<<endl;
        }
        else{
            cnt+=1;
            n-=k;
            cout<<cnt+n/(k-1)+(n%(k-1)!=0)<<endl;
        }
    }




    
}