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

void find_dep(int cur,int pre,int dep,vector<vector<int>> &edges,map<int,vector<int>> &ans){
    ans[dep].push_back(cur);
    for(int x:edges[cur]){
        if(x!=pre){
            find_dep(x,cur,dep+1,edges,ans);
        }
    }
}
vector<int> doit(int root,int pre,vector<vector<int>> &edges){
    vector<int> ans;
    map<int,vector<int>> dep_mp;
    find_dep(root,pre,0,edges,dep_mp);
    for(auto p=dep_mp.rbegin();p!=dep_mp.rend();++p){
        auto arr=p->second;
        for(int x:arr)
            ans.push_back(x);
    }
    return ans;
}

void compete_solution()
{
    int n,start,end;
    cin >> n>>start>>end;
    vector<vector<int>> raw_edges=cin_matrix(n-1,2);

    --start;
    --end;
    for(auto &arr:raw_edges){
        --arr[0];
        --arr[1];
    }
    vector<vector<int>> edges(n);
    for(auto arr:raw_edges){
        edges[arr[0]].push_back(arr[1]);
        edges[arr[1]].push_back(arr[0]);
    }
    //!必定经过唯一路径
    //起点之前的子树 会拉回
    //一个是终点后的子树 会牵扯
    //一个是中间的乱七八糟 都可能
    //找到最短路径 保留顺序  处理子树问题
    //深度返回

    vector<int> path;
    vector<int> temp;
    temp.push_back(start);
    auto dfs=[&](auto&&dfs,int cur,int pre)->void{
        if(cur==end){
            path=temp;
        }
        for(int x:edges[cur]){
            if(x!=pre){
                temp.push_back(x);
                dfs(dfs,x,cur);
                temp.pop_back();
            }
        }
    };
    dfs(dfs,start,-1);
    //print(path);
    set<int> st;
    for(int x:path){
        st.insert(x);
    }
    vector<int> ans;
    for(int i=0;i<path.size();++i){
        int cur=path[i];
        for(int x:edges[cur]){
            if(st.find(x)!=st.end())
                continue;
            
            vector<int> rst=doit(x,cur,edges);
            for(int x:rst){
                ans.push_back(x);
            }
        }
        ans.push_back(cur);
    }
    for(int &x:ans)
        ++x;
    print(ans);




}