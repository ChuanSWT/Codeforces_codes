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
    vector<int> nums1=cin_nums(n);
    vector<int> nums2=cin_nums(n);

    vector<vector<int>> nums;
    vector<vector<int>> ans;
    map<vector<int>,int> mp;
    for(int i=0;i<n;++i){
        nums.push_back({nums1[i],nums2[i]});
        mp[{nums1[i],nums2[i]}]=i;
    }
    if(n%2){//奇数情况下 将相同的移到中间
        vector<int> target;
        for(int i=0;i<nums.size();++i){
            auto arr=nums[i];
            if(arr[0]==arr[1]){
                if(!target.empty()){
                    cout<<-1<<endl;
                    return;
                }
                target=arr;
            }
        }
        if(target.empty()){
            cout<<-1<<endl;
            return;
        }
        int a=mp[target];
        int b=n/2;
        if(a!=b)//blyat
        {
        ans.push_back({a,b});
        swap(nums[a],nums[b]);
        mp[nums[a]]=a;
        mp[nums[b]]=b;
        }
    }
    else{//偶数情况下 检测相同的
        for(int i=0;i<nums.size();++i){
            if(nums[i][0]==nums[i][1]){
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n/2;++i){
        int oppo=n-i-1;
        if(nums[i][0]==nums[oppo][1]&&nums[i][1]==nums[oppo][0])
            continue;
        vector<int> arr=nums[i];
        vector<int> rev_arr=nums[i];
        reverse(rev_arr.begin(),rev_arr.end());
        if(!mp.count(rev_arr)){
            cout<<-1<<endl;
            return;
        }
        int idx=mp[rev_arr];
        ans.push_back({idx,oppo});
        swap(nums[idx],nums[oppo]);
        mp[nums[idx]]=idx;
        mp[nums[oppo]]=oppo;
    }
    for(int i=0;i<nums.size();++i){
        int oppo=n-i-1;
        if(nums[i][0]==nums[oppo][1]&&nums[i][1]==nums[oppo][0])
            continue;
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto arr:ans){
        ++arr[0];
        ++arr[1];
        print(arr);
    }


    
}