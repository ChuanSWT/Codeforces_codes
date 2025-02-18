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
int cal_mex(vector<int> nums){
    set<int> st;
    for(int x:nums)
    st.insert(x);
    int ans=0;
    while(st.find(ans)!=st.end())
        ++ans;
    return ans;
}
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    //0 1/ 7 1 0 1 0 3
    //分两段一定可以？
    set<int> left;
    set<int> right;
    int r=cal_mex(nums);
    int l=0;
    map<int,int> mp;
    for(int x:nums)
        ++mp[x];
    for(int i=0;i+1<nums.size();++i){
        left.insert(nums[i]);
        while(left.find(l)!=left.end())
            ++l;
        --mp[nums[i]];
        if(mp[nums[i]]==0){
            r=min(r,nums[i]);
        }
        if(l==r){
            cout<<2<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    
    
}