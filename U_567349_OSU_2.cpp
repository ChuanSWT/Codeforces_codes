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


int cal(vector<int> nums,int m){
    int ans=0;
    int pv=0;
    for(int i=0;i<nums.size();++i){
        if(!pv){
            if(nums[i]==0)
                continue;
            if(i!=0&&nums[i-1]==1)
                continue;
            ++ans;
            while(i+1<nums.size()&&nums[i+1]==1){
                ++i;
            }
            pv=m;
        }
        else{
            --pv;
        }
    }
    return ans;
}

void compete_solution()
{
    int n,m;
    cin >> n>>m;

    m-=1;
    vector<string> strs(4);
    for(auto &s:strs)
        cin>>s;
    int ans=0;
    for(auto s:strs){
        vector<int> nums;
        for(char c:s){
            nums.push_back(c-'0');
        }
        ans+=cal(nums,m);
        //cout<<cal(nums,m)<<endl;
    }
    cout<<ans<<endl;
    





    
}