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



int cal(vector<int> nums){
    int ans=0;
    for(int x:nums){
        ans*=2;
        ans+=x;
    }
    return ans;
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<vector<string>> strss(k+1,vector<string>(n));
    for(auto &arr:strss){
        for(auto &s:arr)
            cin>>s;
    }
    //cout<<strss.size()<<" "<<strss[0].size()<<endl;
    /*for(auto arr:strss){
        print(arr);
    }*/
    vector<vector<int>> grid(k,vector<int>(n,0));
    for(int x=0;x<k;++x){
        for(int y=0;y<n;++y){
            //cout<<x<<" "<<y<<endl;
            //cout<<strss[0][k]<<endl;
            if(strss[x+1][y]==strss[0][y]){
                grid[x][y]=1;
            }
        }
    }
    vector<int> mark(n,0);
    for(auto arr:grid){
        for(int i=0;i<arr.size();++i){
            mark[i]|=arr[i];
        }
    }
    if(accumulate(mark.begin(),mark.end(),0)!=mark.size()){
        cout<<-1<<endl;
        return;
    }
    int maxv=0;
    for(int i=0;i<grid.size();++i){
        int t=accumulate(grid[i].begin(),grid[i].end(),0);
        maxv=max(maxv,t);
    }
    int ans=n+2*(n-maxv);
    cout<<ans<<endl;


    
}