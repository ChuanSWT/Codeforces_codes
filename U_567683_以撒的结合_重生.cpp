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


void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<string> strs(n);
    for(auto&s:strs)
        cin>>s;
    vector<vector<int>> cnt(n,vector<int>(m,0));    
    map<char,vector<int>> mp;
    mp['N']={-1,0};
    mp['S']={1,0};
    mp['W']={0,-1};
    mp['E']={0,1};
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            if(strs[x][y]!='#'){
                for(int i=0;i<4;++i){
                    int nx=x+dx[i],ny=y+dy[i];
                    ++cnt[nx][ny];
                }
                if(mp.count(strs[x][y])){
                    int nx=x+mp[strs[x][y]][0],ny=y+mp[strs[x][y]][1];
                    cnt[nx][ny]-=100;
                }
            }
        }
    }
    /*for(auto arr:cnt)
        print(arr);*/
    map<int,int> mp2;
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            if(strs[x][y]=='#'){
                ++mp2[cnt[x][y]];
            }
        }
    }
    cout<<mp2[2]+mp2[3]+mp2[4]<<" "<<mp2[1]<<'\n';



    
}