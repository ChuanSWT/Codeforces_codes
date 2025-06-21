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

int cal_mex_ex0(map<int,int> mp){
    for(int i=1;i<1e8;++i){
        if(mp[i]==0)
            return i;
    }
    return -1;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    int cnt=0;
    for(int x:nums){
        if(x==0)
            ++cnt;
    }
    if(cnt==0){
        cout<<n<<endl;
        return;
    }
    if(nums[0]==0){
        cout<<n-cnt+1<<endl;
        return;
    }
    map<int,int> mp;
    for(int x:nums){
        ++mp[x];
    }
    int cur_mex=cal_mex_ex0(mp);
    vector<int> nxt_mex(n,-1);
    for(int i=0;i<nums.size();++i){
            if(--mp[nums[i]]==0){
                cur_mex=min(cur_mex,nums[i]);
            }
        nxt_mex[i]=cur_mex;
    }
    //print(nxt_mex);
    int minv=0x3f3f3f3f;
    for(int i=0;i<nums.size();++i){
        if(nums[i]!=0)
            minv=min(minv,nums[i]);
        if(nums[i]==0&&minv>=nxt_mex[i]){
            cout<<n-cnt+1<<endl;
            return;
        }
        if(nums[i]!=0&&minv<nxt_mex[i]){
            cout<<n-cnt<<endl;
            return;
        }
    }
    cout<<n-cnt<<endl;




    
}