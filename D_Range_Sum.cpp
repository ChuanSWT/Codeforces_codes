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
set<set<int>> mem;
void dfs(int dep,set<int>&st,int target,set<set<int>> &anss){
    if(mem.find(st)!=mem.end())
    return;
    mem.insert(st);
    if(dep==target){
        int sum=0;
        int maxv=0;
        int minv=0x3f3f3f3f;
        for(int x:st){
        sum+=x;
        maxv=max(maxv,x);
        minv=min(minv,x);
        }
        if((maxv-minv)*(maxv-minv)==sum){
            anss.insert(st);
        }
        return;
    }
    for(int i=1;i<20;++i){
        if(st.find(i)!=st.end())
        continue;
        st.insert(i);
        dfs(dep+1,st,target,anss);
        st.erase(i);
    }
}
void compete_solution()
{
    int n;
    cin>>n;
    //构造数组 元素互不相同 使(max-min)^2==sum
    //8 64
    //1 2 3 4 6 7 8 9
    //4 5 6 7 9 10 11 12
    //6
    //1 2 3 5 6 7
    //24->36
    //3 4 5 7 8 9

    //5
    //1 2 5 6 7
    //21->36
    //+3
    //9
    //1 2 3 4 9 10 11 12 13
    //65->144 79
    //?
    //1 2 3 4 7 8 9 10 11
    //+5
    //都是中间隔两位



    /*set<set<int>> anss;
    set<int> st;
    dfs(0,st,9,anss);
    for(auto x:anss){
        for(int xx:x)
        cout<<xx<<" ";
        cout<<endl;
    }*/
    if(n%2!=0){
        vector<int> ans;
        for(int i=0;i<n/2;++i){
            ans.push_back(i+1);
        }
        int t1=ans.back();

        for(int i=t1+3;ans.size()<n;++i){
            ans.push_back(i);
        }
        int sum=0;
        for(int x:ans)
            sum+=x;
        int target=ans.back()-ans[0];
        target*=target;
        for(auto &x:ans){
            x+=(target-sum)/n;
        }
        print(ans);
        return;
    }
    vector<int> ans;
    for(int i=1;i<=n+1;++i){
        if(i==n/2+1)
        continue;
        ans.push_back(i);
    }
int sum=0;
        for(int x:ans)
            sum+=x;
        int target=ans.back()-ans[0];
        target*=target;
        for(auto &x:ans){
            x+=(target-sum)/n;
        }
        print(ans);
        return;
    
}