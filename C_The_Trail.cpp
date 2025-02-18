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
void make(string s,vector<vector<int>>&mark){
    int x=0,y=0;
    mark[x][y]=1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='D')
            ++x;
        else
            ++y;
        mark[x][y]=1;
    }
}
bool check_row(int x,vector<vector<int>>&mark){
    for(int &x:mark[x])
        if(x)
        return false;
    return true;
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>> grid=cin_edges(n,m);
    vector<vector<int>> mark(n,vector<int>(m,0));
    //make mark
    make(s,mark);
    int x=0,y=0;
    int sum=0;
    mark[0][0]=0;

    int fst=0;
    if(check_row(0,mark))
    for(int i=1;i<grid[0].size();++i){
        fst+=grid[0][i];
    }
    else
    for(int i=1;i<grid.size();++i){
        fst+=grid[i][0];
    }
    grid[0][0]=-fst;
    for(int i=0;i<s.size();++i){
        if(s[i]=='D')
            ++x;
        else
            ++y;
        mark[x][y]=0;
        int cur_sum=0;
        if(check_row(x,mark)){
            for(int x:grid[x])
                cur_sum+=x;
        }
        else{
            for(int x=0;x<grid.size();++x)
            cur_sum+=grid[x][y];
        }
        grid[x][y]=sum-cur_sum;
        

    }
    for(auto arr:grid)
    print(arr);

}