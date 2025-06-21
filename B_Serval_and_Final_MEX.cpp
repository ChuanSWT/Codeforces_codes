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




void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    vector<vector<int>> ans;
    map<int,int> mp;
    for(int x:nums)
        ++mp[x];
    if(mp[0]==0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }
    if(nums[0]==0&&nums[n-1]==0){
        ans.push_back({1,2});
        ans.push_back({2,n-1});
        ans.push_back({1,2});
    }
    else{
        if(nums[0]==0){
            int index=0;
            for(int i=0;i<nums.size();++i){
                if(nums[i]==0)
                    index=i;
            }
            if(index==0)
                index=1;
            ans.push_back({1,index+1});
            int length=index+1;
            ans.push_back({1,n-length+1});
        }
        else{
            int index=n-1;
            for(int i=n-1;i>=0;--i){
                if(nums[i]==0)
                    index=i;
            }
            if(index==n-1)
                --index;
            ans.push_back({index+1,n});
            int length=n-index;
            ans.push_back({1,n-length+1});
        }

    }
    cout<<ans.size()<<endl;
    for(auto arr:ans)
        print(arr);

    
}