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
int t = 1;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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



int cal(vector<int> nums1,vector<int> nums2){
    int n=nums1.size();
    int cnt=0;
    while(accumulate(nums1.begin(),nums1.end(),0ll)!=0){
        print(nums1);
        vector<int> mv(n,0);
        for(int i=0;i<nums1.size();++i){
            mv[i]=min(nums1[i],nums2[i]);
        }
        for(int i=0;i<n;++i){
            nums1[i]-=mv[i];
            nums2[i]-=mv[i];
        }
        int vk=nums1.back();
        for(int i=n-1;i>0;--i){
            nums1[i]=nums1[i-1];
        }
        nums1[0]=vk;
        ++cnt;
    }
    return cnt;
}
bool check(vector<int> nums1,vector<int> nums2){
    for(int i=0;i<nums1.size();++i){
        if(nums1[i]>nums2[i])
            return false;
    }
    return true;
}
void compete_solution()
{
    int n,_;
    cin >> n>>_;
    vector<int> nums1=cin_nums(n);
    vector<int> nums2=cin_nums(n);
    int cur=0,ans=0;
    int pre=0;
    for(int i=0;i<2*n;++i){
        cur+=nums1[i%n]-nums2[i%n];
        if(cur<=0){
            cur=0;
            ans=max(ans,i-pre);
            pre=i;
        }
    }
    cout<<max(ans,1ll)<<endl;
}