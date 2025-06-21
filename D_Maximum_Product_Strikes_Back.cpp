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
//选到负数前 需要舍弃的2
vector<int> c(vector<int> nums){
    int cnt=0;//会删掉多少个2
    int cnt2=0;//删多少个
    for(int i=0;i<nums.size();++i){
        ++cnt2;
        if(abs(nums[i])==2)
            ++cnt;
        if(nums[i]<0)
            break;
    }
    return {cnt,cnt2};
}
int cal(vector<int> nums){
    int flag=1;
    int cnt=0;
    for(int x:nums){
        if(x<0){
            flag=!flag;
        }
        if(abs(x)==2){
            ++cnt;
        }
    }
    if(flag)
        return cnt;
    return -cnt;
}

void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);

    nums.push_back(0);
    int left=0,right=n;
    int maxv=0;
    for(int i=0;i<nums.size();++i){
        if(nums[i]==0)
            continue;
        if(i!=0&&nums[i-1]!=0)
            continue;
        vector<int> arr;
        for(int j=i;j<nums.size();++j){
            if(nums[j]!=0)
                arr.push_back(nums[j]);
            else{
                break;
            }
        }
        if(cal(arr)>=0){
            int rst=cal(arr);
            if(rst>maxv){
                left=i;
                right=n-(arr.size()+i);
                maxv=rst;
            }
            continue;
        }
        int rst=cal(arr);
        vector<int> arr2=arr;
        reverse(arr2.begin(),arr2.end());
        vector<int> rst1=c(arr);
        vector<int> rst2=c(arr2);
        //cout<<rst1[1]<<" "<<rst2[1]<<endl;
        if(rst1[0]<rst2[0]){
            int frst=-rst-rst1[0];
            if(frst>maxv){
                maxv=frst;
                left=i+rst1[1];
                right=n-(arr.size()+i);
            }
        }
        else{
            int frst=-rst-rst2[0];
            if(frst>maxv){
                maxv=frst;
                left=i;
                right=n-(i+(int)arr.size())+rst2[1];
            }
        }

    }
    cout<<left<<" "<<right<<endl;
    
    
}