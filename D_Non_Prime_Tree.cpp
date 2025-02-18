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
#define martix vector<vector<int>>
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
bool is_prime(int n)
{
    if(n==1)
    return false;
    for(int i=2;i*i<=n;++i)
    if(n%i==0)
    return false;

    return true;
}
class meth
{
    public:
    int n;
    martix edges;
    vector<int> mark;
    meth(int sz,martix other):edges(sz),mark(sz,0)
    {
        n=sz;
        for(auto arr:other)
        {
            edges[arr[0]].push_back(arr[1]);
            edges[arr[1]].push_back(arr[0]);
        }
    }
    vector<int> ans;
    vector<int> dfs()
    {
        ans.resize(n);
        int p=1;
        dfs_helper(0,p);
        return ans;
    }
    void dfs_helper(int cur,int &p)
    {
        mark[cur]=1;
        ans[cur]=p;
        ++p;
        for(int x:edges[cur])
        {
            if(mark[x])
            continue;
            while(is_prime(p-ans[cur]))
                ++p;
            dfs_helper(x,p);
        }
    }
};
void compete_solution()
{
    int n;
    cin >> n;
    martix edges=cin_edges(n-1,2);

    for(auto&arr:edges)
        {
            for(int &x:arr)
            --x;
        }
    meth *test=new meth(n,edges);
    vector<int> rst=test->dfs();
    print(rst);

    
}