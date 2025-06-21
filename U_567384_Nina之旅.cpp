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



class unionFind
{
private:
    vector<int> f, rank;
public:
    unionFind(int sz) : f(sz), rank(sz, 1)
    {
        for (int i = 0; i < f.size(); ++i)
            f[i] = i;
    }
    int find(int x)
    {
        if (f[x] != x)
            f[x] = find(f[x]);
        return f[x];
    }
    void link(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return;
        if (rank[fx] < rank[fy])
            swap(fx, fy);
        f[fy] = fx;
        if (rank[fx] == rank[fy])
            ++rank[fx];
    }
};
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> r_edges=cin_matrix(m,3);
    int start,end;
    cin>>start>>end;

    --start,--end;
    for(auto &arr:r_edges){
        --arr[0];
        --arr[1];
    }
    unionFind test(n);
    sort(r_edges.begin(),r_edges.end(),[&](vector<int>&a,vector<int>&b)->bool{
        return a[2]<b[2];
    });

    for(int i=0;i<r_edges.size();++i){
        int x=r_edges[i][0];    
        int y=r_edges[i][1];
        int cost=r_edges[i][2];
        test.link(x,y);
        if(test.find(start)==test.find(end)){
            cout<<cost<<endl;
            return;
        }
    }
    cout<<-1<<endl;





    
}