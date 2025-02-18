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
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
vector<int> buildParentArray(vector<vector<int>>& edges) {
    if (edges.empty()) {
        return {-1};
    }
    int n = edges.size()+1;
    // 构建邻接表
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(0);
    
    // BFS遍历设置父节点
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            // 当邻接点不是父节点时，设置父节点并加入队列
            if (v != parent[u]) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    return parent;
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

class TreeAncestor
{
    vector<vector<int>> pa;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        int m = 30;
        pa.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i)
            pa[i][0] = parent[i];       // 跟据已有讯息，赋予所有1层直接父节点
        for (int i = 0; i < m - 1; ++i) // 每个层数。。
        {
            for (int x = 0; x < n; ++x) // 每一个节点。。
            {
                int p = pa[x][i]; // 提取 倍增父节点
                if (p != -1)
                    pa[x][i + 1] = pa[p][i]; // 1+1==2 2+2==4 。。。
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int m = 30;
        for (int i = 0; i < m; ++i)
        {
            // 逐位上升
            if ((k >> i) & 1)
            {
                node = pa[node][i];
                if (node < 0)
                    break;
            }
        }
        return node;
    }
    int lca(int a, int a_dep, int b, int b_dep)
    {
        if (a_dep > b_dep)
        {
            swap(a, b);
            swap(a_dep, b_dep);
        }
        int diff = b_dep - a_dep;
        b_dep=a_dep;
        for (int i = 29; i >= 0; --i)
        {
            if(binpow(2,i)>=diff){
                b=pa[b][i];
                diff-=binpow(2,i);
            }
        }
        for(int i=30;i>=0;--i){
            if(pa[b][i]!=pa[a][i]){
                b=pa[b][i];
                a=pa[a][i];
            }
        }
        return pa[a][0];
    }
};
class fenWick
{
    vector<int> tree;

public:
    fenWick(int n) : tree(n) {}
    fenWick(vector<int> nums)
    {
        int n = nums.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            add(i + 1, nums[i]);
        }
    }
    // 把下标为 i 的元素增加 val
    void add(int i, int val)
    {
        ++i;//对齐
        // cout<<i<<" "<<val<<endl;
        while (i < tree.size())
        {
            tree[i] += val;
            i += i & -i;
        }
    }

    // 返回下标在 [1,i] 的元素之和
    int pre(int i)
    {
        ++i;//对齐
        int res = 0;
        while (i > 0)
        {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};
class unionFind
{
public:
    vector<int> f, rank;
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
class graphMeth
{
public:
    int n;
    vector<vector<int>> edges;
    vector<int> nums;
    // default
    graphMeth(int sz, vector<vector<int>> raw_edges) : edges(sz), n(sz)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
    // 点权
    graphMeth(int sz, vector<vector<int>> raw_edges, vector<int> vals) : edges(sz), n(sz), nums(vals)
    {
        for (auto edge : raw_edges)
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
    }
};
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    vector<vector<int>> raw_edges=cin_matrix(n-1,2);
    for(auto &arr:raw_edges){
        --arr[0];
        --arr[1];
    }
    int maxv=0;
    set<int> st;
    for(int x:nums)
        st.insert(x);
    if(st.size()==1){
        cout<<0<<endl;
        return;
    }
    maxv=*st.rbegin();
    int sub=*(++st.rbegin());
    int cnt=0;
    for(int x:nums)
        if(x==maxv)
            ++cnt;
    
    vector<vector<int>> edges(n);
    for(auto arr:raw_edges){
        edges[arr[0]].push_back(arr[1]);
        edges[arr[1]].push_back(arr[0]);
    }
    int ans=-1;
    vector<int> mark(n,0);
    auto dfs=[&](auto&& self,int node)->int{
        int child_sum=0;
        for(int x:edges[node]){
            if(mark[x])
                continue;
            mark[x]=1;
            child_sum+=self(self,x);
            mark[x]=0;
        }
        if(nums[node]==maxv)
            ++child_sum;
        if(child_sum<cnt&&nums[node]==sub){
            ans=node;
        }
        return child_sum;
    };
    dfs(dfs,0);
    if(ans==-1){
        cout<<0<<endl;
        return;
    }
    cout<<ans<<endl;
}