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
int dfs(int i,int length,int maxv,map<vector<int>,int>&mp)
{
    if(i==length)
        return 1;
    int sum=0;
    for(int take=1;take<=maxv;++take)
    {
        if(mp.find({i+1,take})!=mp.end())
        {
            sum+=mp[{i+1,take}];
            continue;
        }
        sum+=dfs(i+1,length,take,mp);
    }
    mp[{i,maxv}]=sum;
    return sum;
}
int cal(int length,int maxv)
{
    map<vector<int>,int> mp;
    return dfs(0,length,maxv,mp);
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<int> edges=cin_nums(n);
    for(int&x:edges)
    --x;
    vector<int> record(n,0);
    for(int i=0;i<edges.size();++i)
    {
        int cur=0;
        int x=edges[i];
        while(cur<10000)
        {
            ++cur;
            record[x]=max(record[x],cur);
            x=edges[x];
        }
    }
    map<int,vector<int>> mp;
    for(int i=0;i<record.size();++i)
    {

    }
    
}