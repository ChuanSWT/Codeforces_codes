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
void dfs(int cur,multiset<int>& mst,int &a_cnt,int &b_cnt,bool &bad){
    if(bad)
    return;
    if(b_cnt>a_cnt){
        bad=true;
        return;
    }
    if(mst.find(cur)!=mst.end()){
        auto p=mst.find(cur);
        mst.erase(p);
        --a_cnt;
        --b_cnt;
        return;
    }
    ++b_cnt;
    dfs(cur/2,mst,a_cnt,b_cnt,bad);
    dfs(cur/2+cur%2,mst,a_cnt,b_cnt,bad);

}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums1=cin_nums(n);
    vector<int> nums2=cin_nums(m);

    multiset<int> mst;
    for(int x:nums1)
        mst.insert(x);
    bool bad=false;
    int a_cnt=n;
    int b_cnt=m;
    for(int x:nums2){
        dfs(x,mst,a_cnt,b_cnt,bad);
    }
    if(bad||mst.size()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

}