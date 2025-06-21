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
    int n;
    cin >> n;
    vector<vector<int>> r_edges=cin_matrix(n-1,2);
    for(auto&arr:r_edges){
        for(int &x:arr){
            --x;
        }
    }
    vector<vector<int>> edges(n);
    for(auto arr:r_edges){
        int x=arr[0],y=arr[1];
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    queue<vector<int>> qu;
    qu.push({0,-1});
    auto try_ist=[&](vector<pair<int,int>>rst,vector<int>&ans)->void{
        int tot_d=rst[0].first+rst[1].first;
        int one=max(rst[0].second,rst[1].second);
        int two=min(rst[0].second,rst[1].second);
        if(tot_d>ans[0]){
            ans={tot_d,one,two};
            return;
        }
        if(tot_d<ans[0])
            return;
        if(one>ans[1]){
            ans={tot_d,one,two};
            return;
        }
        if(one<ans[1])
            return;
        if(two>ans[2]){
            ans={tot_d,one,two};
            return;
        }
        if(two<ans[2])
            return;
        return;
    };
    //ans: 距离 顶点1 顶点2
    //最大距离 对应顶点号 
    auto cmp=[&](pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.second<b.second;
    };
    vector<int> visited(n,0);
    auto dfs=[&](auto&&dfs,int cur,int pre,vector<int>&ans)->pair<int,int>{
        vector<pair<int,int>> rsts;
        for(int x:edges[cur]){
            if(x==pre)
                continue;
            if(visited[x])
                continue;
            pair<int,int> rst=dfs(dfs,x,cur,ans);
            rsts.push_back(rst);
        }
        for(int i=0;i<2&&i<rsts.size();++i){
            for(int j=i+1;j<rsts.size();++j){
                if(cmp(rsts[i],rsts[j]))
                    swap(rsts[i],rsts[j]);
            }
        }
        if(rsts.size()>=2){
            try_ist({rsts[0],rsts[1]},ans);
        }
        if(rsts.size()>=1){
            try_ist({rsts[0],{0,cur}},ans);
        }
        try_ist({{0,cur},{0,cur}},ans);
        if(rsts.empty()){
            return {1,cur};
        }
        return {rsts[0].first+1,rsts[0].second};
    };

    auto dfs2=[&](auto&&dfs2,int cur,int pre,int target,vector<int>&path,bool &finished)->void{
        if(visited[cur])
            return;
        if(finished){
            return;
        }
        if(cur==target){
            finished=true;
            for(int x:path){
                visited[x]=1;
            }
            for(int x:path){
                for(int y:edges[x]){
                    if(visited[y]==0){
                        qu.push({y,x});
                    }
                }
            }
            return;
        }
        for(int x:edges[cur]){
            if(x==pre)
                continue;
            path.push_back(x);
            dfs2(dfs2,x,cur,target,path,finished);
            path.pop_back();
        }
    };  
    //set<vector<int>> deb; 
    vector<vector<int>> anss;
    while(qu.size()){
        auto arr=qu.front();
        qu.pop();
        vector<int> ans(3,-1);
        int root=arr[0],pre=arr[1];
        dfs(dfs,root,pre,ans);
        anss.push_back(ans);

        /*if(deb.count(ans)){
            print(arr);
            return;
        }
        deb.insert(ans);*/

        vector<int> path={ans[1]};
        bool finished=false;
        dfs2(dfs2,ans[1],-1,ans[2],path,finished);
    }
    auto cmp2=[&](vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[2]<b[2];
    };
    //anss.erase(unique(anss.begin(), anss.end()), anss.end());
    sort(anss.rbegin(),anss.rend(),cmp2);
    
    for(auto arr:anss){
        for(int x:arr){
            cout<<x+1<<' ';
        }
        
    }
    cout<<endl;



    
}