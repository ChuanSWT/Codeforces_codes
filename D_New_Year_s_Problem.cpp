#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;


void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
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
    vector<vector<int>> grid=cin_edges(n,m);
    vector<int> pre_max(m,0);
    for(int x=0;x<grid.size();++x)
    {
        for(int y=0;y<grid[0].size();++y)
        {
            pre_max[y]=max(pre_max[y],grid[x][y]);
        }
    }
    int maxv=0;
    for(int x=0;x<grid.size();++x)
    {
        vector<vector<int>> arr;
        for(int i=0;i<grid[0].size();++i)
        {
            arr.push_back({grid[x][i],i});
        }
        sort(arr.rbegin(),arr.rend());
        vector<int> mark(grid[0].size(),0);
        int cur=0x3f3f3f3f;
        cur=min(cur,arr[0][0]);
        cur=min(cur,arr[1][0]);
        mark[arr[0][1]]=1;
        mark[arr[1][1]]=1;
        for(int i=0;i<mark.size();++i)
        {
            if(mark[i])
            continue;
            cur=min(cur,pre_max[i]);
        }
        maxv=max(maxv,cur);
    }
    cout<<maxv<<endl;

    
}