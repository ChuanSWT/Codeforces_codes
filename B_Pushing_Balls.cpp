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



bool check(string line){
    bool within=true;
    for(int i=0;i<line.size();++i){
        if(line[i]=='1'){
            if(within){
                continue;
            }
            else{
                return false;
            }
        }
        else{
            within=false;
        }
    }
    return true;
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<string> r_grid(n);
    for(auto&s:r_grid){
        cin>>s;
    }
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int x=0;x<grid.size();++x){
        for(int y=0;y<grid[0].size();++y){
            if(r_grid[x][y]=='0'){
                grid[x][y]=0;
            }
            else{
                grid[x][y]=1;
            }
        }
    }
    vector<vector<int>> mark(n,vector<int>(m,0));
    for(int x=0;x<grid.size();++x){
        for(int y=0;y<grid[0].size();++y){
            if(grid[x][y]==0)
                break;
            mark[x][y]=1;
        }
    }
    
    for(int y=0;y<grid[0].size();++y){
        for(int x=0;x<grid.size();++x){
            if(grid[x][y]==0)
                break;
            mark[x][y]=1;
        }
    }
    /*for(auto arr:mark)
        print(arr);*/
    for(int x=0;x<grid.size();++x){
        for(int y=0;y<grid[0].size();++y){
            if(mark[x][y]==0&&r_grid[x][y]=='1'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}