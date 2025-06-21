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


/*vector<int> ans;
int maxv=0;
vector<int> path;
int cal(){
    set<int> st;
    for(int i=1;i<path.size();++i){
        st.insert(gcd(path[i-1],path[i]));
    }
    st.insert(gcd(path[0],path.back()));
    return st.size();
}
void dfs(int dep,vector<int>&mask){
    if(dep==mask.size()){
        if(cal()>maxv){
            maxv=cal();
            ans=path;
        }
        return;
    }
    for(int i=0;i<mask.size();++i){
        if(mask[i]==0){
            mask[i]=1;
            path.push_back(i+1);
            dfs(dep+1,mask);
            mask[i]=0;
            path.pop_back();
        }
    }
}*/
void compete_solution()
{
    int n;
    cin >> n;
    //组建排列 
    //分数计算：视为循环数组 得分为所有相邻元素的GCD的单一集合大小
    //你需要最大化得分

    //n蛮大的 1e5
   // vector<int> mask(n,0);
    //dfs(0,mask);
    //print(ans);
    //1
    //1 2
    //1 2 3
    //1 2 4 3
    //1 2 4 3 5 
    //1 2 3 6 4 5 
    //1 2 3 6 4 5 7 
    //1 2 3 6 4 8 5 7 
    //1 2 3 4 8 6 9 5 7 
    //1 2 3 4 8 5 10 6 9 7 
    //好像是非素数就要往前插入
    //不同的数目和什么有关系?
    //倍数？
    //质数似乎没什么用
    vector<int> d(n+1,0);
    vector<int> ans;
    ans.push_back(1);
    for(int i=2;i<d.size();++i){
        if(d[i])
            continue;
        ans.push_back(i);
        for(int j=i*2;j<d.size();j*=2){
            if(d[j])
                continue;
            d[j]=1;
            ans.push_back(j);
        }
    }
    print(ans);
}