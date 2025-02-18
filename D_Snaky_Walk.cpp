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
    //cin >> roundc;
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
vector<int> fd(vector<string> grid,char c)
{
    for(int x=0;x<grid.size();++x)
    {
        for(int y=0;y<grid[0].size();++y)
        {
            if(grid[x][y]==c)
            return {x,y};
        }
    }
    return {-1,-1};
}
vector<int> dx={0,0,-1,1};
vector<int> dy={1,-1,0,0};
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(auto &s:grid)
    cin>>s;
    vector<int> start=fd(grid,'S');
    vector<int> game=fd(grid,'G');
    vector<vector<vector<int>>> mem(n,vector<vector<int>>(m,vector<int>(2,0x3f3f3f3f3f3f3f3f)));

    priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
    pq.push({0ll,start[0],start[1],0});
    pq.push({0ll,start[0],start[1],1});
    while(pq.size())
    {
        auto arr=pq.top();
        pq.pop();
        int cost=arr[0];
        int x=arr[1];
        int y=arr[2];
        int status=arr[3];
        if(cost>=mem[x][y][status])
        continue;
        mem[x][y][status]=cost;
        if(status==1)
        for(int i=0;i<2;++i)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX>=0&&newX<grid.size()&&newY>=0&&newY<grid[0].size())
            {
                if(grid[newX][newY]=='#')
                continue;
                if(mem[newX][newY][status^1]<=cost+1)
                continue;
                pq.push({cost+1,newX,newY,status^1});
            }
        }
        else
        for(int i=2;i<4;++i)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX>=0&&newX<grid.size()&&newY>=0&&newY<grid[0].size())
            {
                if(grid[newX][newY]=='#')
                continue;
                if(mem[newX][newY][status^1]<=cost+1)
                continue;
                pq.push({cost+1,newX,newY,status^1});
            }
        }
    }
    int ans=min(mem[game[0]][game[1]][0],mem[game[0]][game[1]][1]);
    if(ans==0x3f3f3f3f3f3f3f3f)
    ans=-1;
    cout<<ans<<endl;

}