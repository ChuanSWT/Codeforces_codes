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


bool check(vector<int> nums,int n){
    int sum=0;
    for(int i=1;i<n;++i){
        sum+=nums[i];
    }
    for(int i=n;i<n;++i){
        sum-=nums[i];
    }
    if(sum==nums[0]){
        return false;
    }
    return true;
}
void dfs(vector<int> nums,vector<int> &mask,vector<int>&path,int dep,vector<int> &ans){
    if(dep==nums.size()){
        int sum=0;
        for(int i=0;i<path.size();++i){
            if(i%2==0){
                sum+=path[i];
            }
            else{
                sum-=path[i];
            }
        }
        if(sum<=0)
            return;
        for(int x:nums){
            if(x==sum)
                return;
        }
        ans=path;
        return;
    }
    for(int i=0;i<nums.size();++i){
        if(mask[i]){
            continue;
        }
        path.push_back(nums[i]);
        mask[i]=1;
        dfs(nums,mask,path,dep+1,ans);
        path.pop_back();
        mask[i]=0;
    }
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(2*n);
    set<int> st;
    for(int x:nums){
        st.insert(x);
    }
    sort(nums.rbegin(),nums.rend());
    vector<int> add;
    vector<int> minus;
    int sum=0;
    for(int i=0;i<n;++i){
        minus.push_back(nums[i]);
        add.push_back(nums[i+n]);
        sum-=nums[i];
        sum+=nums[i+n];
    }
    for(int i=0;i<add.size();++i){
        int cur=add[i];
        int newSum=sum-add[i];
        int rst=add[i]-newSum;
        if(rst>0&&!st.count(rst)){
            for(int &x:add){
                if(x==cur)
                    x=rst;
            }
        }
        vector<int> ans={cur};
        for(int i=0;i<add.size();++i){
            ans.push_back(add[i]);
            ans.push_back(minus[i]);
        }
        print(ans);return;
    }
}