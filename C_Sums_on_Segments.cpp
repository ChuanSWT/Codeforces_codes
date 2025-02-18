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
vector<int> cal(vector<int> nums)
{
        int cur=0;
        int maxv=0;
        for(int i=0;i<nums.size();++i)
        {
            cur+=nums[i];
            cur=max(cur,0ll);
            maxv=max(maxv,cur);
            

        }
        for(int &x:nums)
            x=-x;
        cur=0;
        int minv=0;
        for(int i=0;i<nums.size();++i)
        {
            cur+=nums[i];
            cur=max(cur,0ll);
            minv=max(minv,cur);
        }
    return {-minv,maxv};
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    int idx=-1;
    for(int i=0;i<nums.size();++i)
    if(nums[i]!=-1&&nums[i]!=1)
    idx=i;

    if(idx==-1)
    {
        vector<int> rst=cal(nums);
        vector<int> ans;
        for(int i=rst[0];i<=rst[1];++i)
        ans.push_back(i);
        cout<<ans.size()<<endl;
        print(ans);
        return;
    }
    vector<int> nums1;
    vector<int> nums2;
    for(int i=0;i<idx;++i)
    nums1.push_back(nums[i]);
    for(int i=idx+1;i<nums.size();++i)
    nums2.push_back(nums[i]);
    vector<int> rst1=cal(nums1);
    vector<int> rst2=cal(nums2);

    int right_mx=0,right_mn=0;
    int left_mx=0,left_mn=0;
    int cur=0;
    for(int i=idx-1;i>=0;--i)
    {
        cur+=nums[i];
        left_mx=max(left_mx,cur);
        left_mn=min(left_mn,cur);
    }
    cur=0;
    for(int i=idx+1;i<nums.size();++i)
    {
        cur+=nums[i];
        right_mx=max(right_mx,cur);
        right_mn=min(right_mn,cur);
    }
    int mid_val=nums[idx];
    set<int> st;
    for(int i=mid_val+left_mn+right_mn;i<=mid_val+right_mx+left_mx;++i)
    st.insert(i);
    for(int i=rst1[0];i<=rst1[1];++i)
    st.insert(i);
    for(int i=rst2[0];i<=rst2[1];++i)
    st.insert(i);
    cout<<st.size()<<endl;
    for(int x:st)
    cout<<x<<" ";
    cout<<endl;



    
}