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
bool is_prime(int n){
    for(int i=1;i*i<=n;++i){
        if(n%i==0)
        return false;
    }
    return true;
}
int cal(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum=0;
    for(int x:a){
        sum+=x;
    }
    int index=a.size()-1;
    int minv=sum;
    int idx=0;
    while(index>=0&&idx<b.size()){
        sum-=a[index];
        sum+=b[idx];
        minv=min(minv,sum);
        --index;
        ++idx;
    }
    return minv;

}
void compete_solution()
{
    int n;
    cin>>n;
    int left,right;
    cin>>left>>right;
    vector<int> nums=cin_nums(n);
    //长度必须选偶数
    //一定只从一边选
    vector<int> nums1;
    vector<int> nums2;
    vector<int> nums3;
    --left;
    --right;
    for(int i=0;i<left;++i){
        nums1.push_back(nums[i]);
    }
    for(int i=left;i<=right;++i){
        nums2.push_back(nums[i]);
    }
    for(int i=right+1;i<nums.size();++i){
        nums3.push_back(nums[i]);
    }
    int rst1=cal(nums2,nums1);
    int rst2=cal(nums2,nums3);
    cout<<min(rst1,rst2)<<endl;
}