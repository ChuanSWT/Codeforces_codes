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
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    map<int,int> mp;
    for(int x:nums)
        ++mp[x];
    int maxv=-1;
    for(auto [x,cnt]:mp){
        if(cnt>=2){
            maxv=max(maxv,x);
        }
    }
    if(maxv==-1){
        cout<<-1<<endl;
        return;
    }
    mp[maxv]-=2;
    vector<int> rst;
    for(auto [x,cnt]:mp){
        while(cnt--){
            rst.push_back(x);
        }
    }
    for(int i=1;i<rst.size();++i){
        if(rst[i-1]+maxv*2>rst[i]){
            cout<<rst[i-1]<<" "<<rst[i]<<" "<<maxv<<" "<<maxv<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}