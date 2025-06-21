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
            x = find(f[x]);
        return x;
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
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    vector<int> queries=cin_nums(n);
    for(int i=0;i<n;++i){
        --nums[i];
        --queries[i];
    }
    unionFind test(n);
    for(int i=0;i<n;++i){
        test.link(nums[i],i);
    }
    map<int,set<int>> mp;
    for(int i=0;i<n;++i){
        int p=test.find(i);
        mp[p].insert(i);
    }
    map<int,int> c2p;
    for(int i=0;i<n;++i){
        int p=test.find(i);
        int sz=mp[p].size();
        c2p[i]=sz;
    }
    set<int> deleted;
    vector<int> ans;
    int cur=0;
    for(int x:queries){
        int p=test.find(x);
        if(deleted.count(p))
        {
            ans.push_back(cur);
            continue;
        }
        deleted.insert(p);
        cur+=mp[p].size();
        ans.push_back(cur);
    }
    print(ans);
}