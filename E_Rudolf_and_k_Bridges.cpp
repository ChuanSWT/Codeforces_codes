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
int inf=0x3f3f3f3f3f3f3f3f;
int cal(vector<int> height,int d){
    int n=height.size();
    vector<int> dp(n,inf);
    dp[0]=1;
    multiset<int> st;
    st.insert(1);
    for(int i=1;i<dp.size();++i){

        if(i-d-2>=0){
            auto p=st.find(dp[i-d-2]);
            st.erase(p);
        }
        int minv=*st.begin();
        dp[i]=height[i]+1ll+minv;
        st.insert(dp[i]);
        //o x x o i=3 d=1
        
    }
    return dp.back();
}
void compete_solution()
{
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    vector<vector<int>> grid=cin_edges(n,m);
    vector<int> results;
    //cout<<"hi"<<endl;
    //return;
    for(int x=0;x<grid.size();++x){
        results.push_back(cal(grid[x],d));
    }
    int ans=inf;
    for(int i=0;i+k<=results.size();++i)
    {
        int sum=0;
        for(int j=i;j<i+k;++j)
        sum+=results[j];
        ans=min(ans,sum);
    }

    cout<<ans<<endl;


    
}