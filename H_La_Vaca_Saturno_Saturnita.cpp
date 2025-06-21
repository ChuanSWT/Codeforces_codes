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

map<int,vector<int>> childs;
void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i=2;i<1e5+100;++i){
        for(int j=i;j<1e5+100;j+=i){
            childs[j].push_back(i);
        }
    }
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


vector<int> make(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            if(i*i==n){
                ans.push_back(i);
            }
            else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int cal(vector<int>&nums,int limit){
    int left=0,right=nums.size();
    while(left<right){
        int mid=(left+right)/2;
        if(nums[mid]<limit){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return left;
}
int cal_idx(map<int,vector<int>> &mp,int k,int start){
    vector<int>& child=childs[k];
    int ans=2e5;
    for(int x:child){
        vector<int> &idxs=mp[x];
        int left=0,right=idxs.size();
        while(left<right){
            int mid=(left+right)/2;
            if(idxs[mid]<start){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        if(left!=idxs.size()){
            ans=min(ans,idxs[left]);
        }
    }
    return ans;
}
void compete_solution()
{
    int n,q;
    cin >> n>>q;
    vector<int> nums=cin_nums(n);
    vector<vector<int>> queries=cin_matrix(q,3);
    map<int,vector<int>> mp;
    for(int i=0;i<nums.size();++i){
        mp[nums[i]].push_back(i);
    }
    for(auto arr:queries){
        int ans=0;
        int left=arr[1]-1,right=arr[2]-1,k=arr[0];
        while(true){
            int end_idx=cal_idx(mp,k,left);
            if(end_idx<=right){
                ans+=(end_idx-left)*k;
                left=end_idx;
                while(k%nums[end_idx]==0){
                    k/=nums[end_idx];
                }
                continue;
            }
            if(end_idx>right){
                ans+=(right-left+1ll)*k;
                break;
            }
        }
        cout<<ans<<endl;
    }
    

    
}