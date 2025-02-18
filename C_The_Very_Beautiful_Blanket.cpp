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
bool check(vector<vector<int>> &grid)
{
    for(int i=4;i<=grid.size();++i)
    {
        for(int j=4;j<=grid[0].size();++j)
        {
            
            vector<vector<int>> newG(4,vector<int>(4));
            for(int x=i-4;x<i;++x)
            {
                for(int y=j-4;y<j;++y)
                {
                    newG[x-i+4][y-j+4]=grid[x][y];
                }

            }
            //for(auto arr:newG)
            //print(arr);
            //cout<<endl;
            int v1=newG[0][0]^newG[1][0]^newG[0][1]^newG[1][1];
            int v3=newG[2][0]^newG[3][0]^newG[2][1]^newG[3][1];
            int v2=newG[0][2]^newG[1][2]^newG[0][3]^newG[1][3];
            int v4=newG[2][2]^newG[3][2]^newG[2][3]^newG[3][3];
            //cout<<v1<<" "<<v2<<' '<<v3<<' '<<v4<<endl;
            if(v1!=v4||v2!=v3)
            {
                cout<<v1<<" "<<v2<<' '<<v3<<' '<<v4<<endl;
                cout<<i-4<<" "<<j-4<<endl;
            return false;
            }
        }
    }
    return true;
}
bool ok=false;
void dfs(int dep,vector<vector<int>> &grid,set<int> &st)
{
    if(dep==grid[0].size()*grid.size()&&check(grid))
    {
        ok=true;
        for(auto arr:grid)
        print(arr);
        return ;
    }
    if(ok)
    return ;
    for(int x=0;x<grid.size();++x)
    {
        for(int y=0;y<grid[0].size();++y)
        {
            if(grid[x][y]==-1)
            for(int i=1;i<=grid.size()*grid[0].size();++i)
            {
                if(st.find(i)!=st.end())
                continue;
                grid[x][y]=i;
                st.insert(i);
                dfs(dep+1,grid,st);
                st.erase(i);
                grid[x][y]=-1;
            }
        }
    }
}
bool check_p(int x,int y, vector<vector<int>> &grid)
{
    return (x>=0&&x<grid.size()&&y>=0&&y<grid[0].size());
}
void compete_solution()
{
    //cout<<(5^6^7^8)<<endl;
    //cout<<(13^14^15^16)<<endl;
    int n,m;
    cin >>n>>m;
    int cur=0;
    vector<vector<int>> grid(256,vector<int>(256,-1));
    for(int i=0;i<grid.size();i+=2)
    {
        for(int j=0;j<grid[0].size();j+=2)
        {
            grid[i][j]=cur;
            grid[i][j+1]=cur+1;
            grid[i+1][j]=cur+2;
            grid[i+1][j+1]=cur+3;
            cur+=4;
        }
    }
    
    
    cout<<n*m<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}