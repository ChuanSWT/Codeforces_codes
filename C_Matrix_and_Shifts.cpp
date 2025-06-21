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
    int n;
    cin >> n;
    vector<string> grid(n);
    for(auto&s:grid)
        cin>>s;
    int maxv=0;
    int sum=0;
    for(auto arr:grid){
        for(auto x:arr){
            if(x=='1')
                ++sum;
        }
    }
    for(int x=0;x<grid.size();++x){
        int cnt=0;
        for(int i=0;i<n;++i){
            int newX=(x+i)%n;
            int newY=i;
            if(grid[newX][newY]=='1')
                ++cnt;
        }
        maxv=max(maxv,cnt);
    }
    cout<<sum-maxv+(n-maxv)<<endl;

    
}