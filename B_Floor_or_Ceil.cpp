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
#include <unordered_set>
#define int long long

using namespace std;

template <typename T>
void print(const std::vector<T> &vec)
{   
    for (auto element : vec)
    {
        std::cout << element << ' ';
    }
    std::cout <<'\n';
}
void compete_solution();
vector<vector<int>> anss;
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
    for(auto arr:anss)
        print(arr);
    return 0;
}
void debug(int n){
    cout<<n<<endl;
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
    int x,n,m;//ok
    //n 向下取整 m 向上取整 
    cin >> x>>n>>m;
    if(x==0){
        anss.push_back({0,0});
        return;
    }
    if(n+m>=32){
        if(n){
            int temp=x;
            while(n--){
                temp/=2;
                if(temp==0)
                    break;
            }
            if(temp==0)
                anss.push_back({0,0});
            else
                anss.push_back({0,1});
        }
        else{
            anss.push_back({1,1});
        }
        return;
    }
    //900*51==4e4 个状态
    unordered_set<int> st;
    int minv=0x3f3f3f3f,maxv=0;
    auto dfs=[&](auto&&dfs,int cur,int n1,int m1)->void{
        //mem
        if(st.count(cur*10000+n1*100+m1))
            return;
        st.insert(cur*10000+n1*100+m1);

        //update
        minv=min(minv,cur);
        if(cur==0){
            return;
        }
        if(n1==0&&m1==0){
            maxv=max(maxv,cur);
            return;
        }
        if(n1){
            if(cur==1){
                dfs(dfs,0,0,0);
            }
            else
                dfs(dfs,cur/2,n1-1,m1);
        }
        if(m1){
            if(cur==1){
                dfs(dfs,cur,n1,0);
            }
            else{
                dfs(dfs,(cur+1)/2,n1,m1-1);
            }
        }
    };
    dfs(dfs,x,n,m);
    //状态还蛮少的 (51)
    //st.insert({x,-1,-1});
    //cout<<minv<<" "<<maxv<<endl;
    anss.push_back({minv,maxv});
}