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



vector<int> dx={0,0,1,1};
vector<int> dy={0,1,0,1};
void compete_solution()
{
    int n,m;
    cin >> n>>m;
    vector<string> r_grid(n);
    for(auto&s:r_grid){
        cin>>s;
    }
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int x=0;x<grid.size();++x){
        for(int y=0;y<grid[0].size();++y){
            grid[x][y]=r_grid[x][y]-'0';
        }
    }
    
    vector<int> x_arr;
    vector<int> y_arr;
    for(int x=0;x<grid.size();++x){
        int sum=0;
        for(int y=0;y<grid[0].size();++y){
            sum^=grid[x][y];
        }
        x_arr.push_back(sum);
    }
    for(int y=0;y<grid[0].size();++y){
        int sum=0;
        for(int x=0;x<grid.size();++x){
            sum^=grid[x][y];
        }
        y_arr.push_back(sum);
    }
    int sum_x=accumulate(x_arr.begin(),x_arr.end(),0);
    int sum_y=accumulate(y_arr.begin(),y_arr.end(),0);
    cout<<abs(sum_x-sum_y)/2+(sum_x+sum_y)/2<<endl;
    //cout<<(accumulate(y_arr.begin(),y_arr.end(),0)+accumulate(x_arr.begin(),x_arr.end(),0))/2<<endl;

    /*
    vector<vector<int>> mark(n,vector<int>(m,0));
    int ans=0;`
    for(int x=0;x<grid.size();++x){
        for(int y=0;y<grid[0].size();++y){
            if(mark[x][y]==0&&grid[x][y]==1){
                int cnt=0;
                int sum=0;
                for(int i=0;i<dx.size();++i){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX>=0&&newX<grid.size()&&newY>=0&&newY<grid[0].size()){
                        mark[newX][newY]=1;
                        ++sum;
                        if(grid[newX][newY]==1){
                            ++cnt;
                        }
                    }
                }
                if(sum==4){
                    if(cnt==4)
                        continue;
                    if(cnt==3){
                        ++ans;
                        continue;
                    }
                    if(cnt==2){
                        cnt+=2
                    }
                }
                else
                if(sum==2){

                }
                else
                if(sum==1){

                }
            }
        }
    }
    */

}