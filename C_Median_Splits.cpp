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


vector<int> make(vector<int> nums,int limit){
    int n=nums.size();
    vector<int> ans(n,0);
    int cur=0;
    for(int i=0;i<nums.size();++i){
        if(nums[i]<=limit){
            cur+=1;
        }
        else{
            cur-=1;
        }
        if(cur>=0){
            ans[i]=1;
        }
    }
    return ans;
}

bool check01(vector<int> nums){
    vector<int> pre_sum=nums;
    for(int i=1;i<nums.size();++i){
        pre_sum[i]+=pre_sum[i-1];
    }
    map<int,int> mp;
    for(int i=0;i+1<nums.size();++i){
        ++mp[pre_sum[i]];
    }
    for(int i=0;i+2<nums.size();++i){
        --mp[pre_sum[i]];
        if(mp[pre_sum[i]]==0){
            mp.erase(pre_sum[i]);
        }
        int cur=pre_sum[i];
        if(mp.rbegin()->first>=cur&&cur>=0){
            return true;
        }
    }
    return false;
}
void compete_solution()
{
    int n,limit;
    cin >> n>>limit;
    vector<int> nums=cin_nums(n);
    //print(nums);
    vector<int> nums01=nums;
    for(int &x:nums01){
        if(x<=limit){
            x=1;
        }
        else
            x=-1;
    }
    //print(nums01);
    if(check01(nums01)){
        cout<<"YES"<<endl;
        return;
    }
    reverse(nums01.begin(),nums01.end());
    if(check01(nums01)){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> rev_nums=nums;
    reverse(rev_nums.begin(),rev_nums.end());


    vector<int> nums1=make(nums,limit);
    vector<int> nums2=make(rev_nums,limit);
    for(int i=1;i<n;++i){
        nums1[i]|=nums1[i-1];
        nums2[i]|=nums2[i-1];
    }
    reverse(nums2.begin(),nums2.end());
    for(int i=0;i+2<n;++i){
        if(nums1[i]&&nums2[i+2]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;return;
    
}