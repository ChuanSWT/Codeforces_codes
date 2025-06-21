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
    //cin >> t;
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
    cin >> n>>m;
    vector<vector<int>> r_edges=cin_matrix(m,2);
    for(auto &arr:r_edges){
        --arr[0];
        --arr[1];
    }
    vector<vector<int>> edges(n);
    for(auto arr:r_edges){
        int x=arr[0];
        int y=arr[1];
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    /*for(auto arr:edges){
        print(arr);
    }*/
    vector<int> mark(n,0);
    int ans=0;
    for(int i=0;i<n;++i){
        if(mark[i])
            continue;
        set<int> st;
        queue<int> qu;
        qu.push(i);
        while(qu.size()){
            int node=qu.front();
            qu.pop();
            st.insert(node);
            mark[node]=1;
            for(int x:edges[node]){
                if(mark[x])
                    continue;
                qu.push(x);
            }
        }
        int cnt=0;
        for(int x:st){
            cnt+=edges[x].size();
        }
        //cout<<cnt<<endl;
        //print(mark);
        cnt/=2;
        ans+=cnt-(int)st.size()+1;
    }
    cout<<ans<<endl;
    

    
}