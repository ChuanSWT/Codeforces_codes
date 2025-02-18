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
void dfs(vector<int> &path,vector<int> &ans){

}
void compete_solution()
{
    int n;
    cin>>n;
    vector<string> grid(n);
    for(auto &s:grid)
    cin>>s;
//输入为无向图 行数即为数字大小
//
//1 2 3 4 5
//理想状态 前面全是 1，后面也全是 1
//若前面为0 左移 若后面 0 右移
vector<int> ans(n);
for(int i=0;i<n;++i){
    int index=i;
    for(int y=0;y<grid[i].size();++y){
        if(y==i)
        continue;
        if(grid[i][y]=='0'){
            if(y>i){
                ++index;
            }
            else
            --index;
        }   
    }
    ans[index]=i;
}
for(auto &x:ans)
++x;
print(ans);



    

    
}