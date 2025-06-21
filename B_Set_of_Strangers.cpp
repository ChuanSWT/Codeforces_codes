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



class graphMeth
{
public:
    int n;
    vector<vector<int>> edges;
    vector<int> nums;
    // default
    graphMeth(int sz, vector<vector<int>> raw_edges) : edges(sz), n(sz)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
    // 点权
    graphMeth(int sz, vector<vector<int>> raw_edges, vector<int> vals) : edges(sz), n(sz), nums(vals)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
};
vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};
void dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>>&mark){
    //cout<<x<<" "<<y<<endl;
    mark[x][y]=1;
    for(int i=0;i<dx.size();++i){
        int newX=x+dx[i];
        int newY=y+dy[i];
        if(newX>=0&&newY>=0&&newX<matrix.size()&&newY<matrix[0].size()){
            if(matrix[newX][newY]==matrix[x][y]&&mark[newX][newY]==0)
                dfs(newX,newY,matrix,mark);
        }
    }
}
void compete_solution()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> matrix=cin_matrix(n,m);
    vector<vector<int>> mark(n,vector<int>(m,0));
    map<int,int> mp;
    map<int,int> color;
    int sum=0;
    for(int x=0;x<matrix.size();++x){
        for(int y=0;y<matrix[0].size();++y){
            if(mark[x][y])
                continue;
            dfs(x,y,matrix,mark);
            int val=1;
            for(int i=0;i<dx.size();++i){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0&&newY>=0&&newX<n&&newY<m){
                    if(matrix[newX][newY]==matrix[x][y])
                        val=2;
                }
            }
            color[matrix[x][y]];
            color[matrix[x][y]]=max(color[matrix[x][y]],val);
        }
    }
    for(auto [_,cnt]:color){
        sum+=cnt;
    }
    int minv=0x3f3f3f3f;
    for(auto [_,cnt]:color){
        minv=min(minv,sum-cnt);
    }
    cout<<minv<<endl;

}