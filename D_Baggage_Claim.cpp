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



int mod=1e9+7;
void compete_solution()
{
    int n,m,k;
    cin >> n>>m>>k;
    vector<vector<int>> points=cin_matrix(5,2);

    for(auto &p:points){
        --p[0],--p[1];
    }
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<points.size();++i){
        int x=points[i][0],y=points[i][1];
        grid[x][y]=1;
    }
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    vector<vector<int>> mark(n,vector<int>(m,0));
    auto dfs=[&](auto &&dfs,int x,int y,int dep){
        if(dep==points.size()*2+1){
            
        }
    }






    
}