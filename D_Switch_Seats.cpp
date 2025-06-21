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



int fd(int val,int idx,map<int,vector<int>> &mp){
    for(int x:mp[val]){
        if(x!=idx)
            return x;
    }
    return -1;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(2*n);
    //1 2 3 4 5 1 2 3 4 5
    //1 2   2 3...

    map<int,vector<int>> mp;
    for(int i=0;i<nums.size();++i){
        mp[nums[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<nums.size();++i){
        int v1=nums[i-1];
        int v2=nums[i];
        if(v1==v2)
            continue;
        int v11=fd(v1,i-1,mp);
        int v22=fd(v2,i,mp);
        //1212
        if(abs(v11-v22)==1&&abs(i-1-v11)>1&&abs(i-v22)>1){
            ++ans;
        }
    }
    ans/=2;
    cout<<ans<<endl;
    
}