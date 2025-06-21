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



vector<int> cal(vector<int> nums){
    int n=nums.size();
    vector<int> ans(n,-1);
    map<int,int> mp;
    for(int i=0;i<n;++i){
        mp[nums[i]]=i;
    }
    int index=0;
    while(nums.size()>1){
        ++index;
        vector<int> mask(nums.size(),0);
        if(index%2==0){
            for(int i=1;i+1<mask.size();++i){
                if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                    mask[i]=1;
                }
            }
            if(nums[0]>nums[1]){
                mask[0]=1;
            }
            int m=nums.size();
            if(nums[m-1]>nums[m-2]){
                mask[m-1]=1;
            }
            vector<int> newNums;
            for(int i=0;i<mask.size();++i){
                if(!mask[i])
                    ans[mp[nums[i]]]=index;
                else
                    newNums.push_back(nums[i]);
            }
            nums=newNums;
        }
        else{
            for(int i=1;i+1<mask.size();++i){
                if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]){
                    mask[i]=1;
                }
            }
            if(nums[0]<nums[1]){
                mask[0]=1;
            }
            int m=nums.size();
            if(nums[m-1]<nums[m-2]){
                mask[m-1]=1;
            }
            vector<int> newNums;
            for(int i=0;i<mask.size();++i){
                if(!mask[i])
                    ans[mp[nums[i]]]=index;
                else
                    newNums.push_back(nums[i]);
            }
            nums=newNums;
        }
        
    }
    return ans;
}
/*
1 1 -1 
1 -1 1 2 1 
3 1 2 1 -1 1 1 2 
1 1 1 -1 1 1 1 
1 1 1 1 -1 
-1 1 1 1 1 
-1 1 2 1 2 

*/
int fd(vector<int> idxs,int n){
    for(int i=0;i<idxs.size();++i){
        if(idxs[i]==0||idxs[i]==n-1)
            continue;
        if(i==0||i==idxs.size()-1){
            return i;
        }
        if(idxs[i-1]!=idxs[i]-1||idxs[i+1]!=idxs[i]+1)
            return i;
    }
    return 0;
}
vector<vector<int>> make(vector<int>nums){
    vector<vector<int>> ans;
    vector<int> line={nums[0]};
    for(int i=1;i<nums.size();++i){
        if(nums[i]==nums[i-1]+1){
            line.push_back(nums[i]);
        }
        else{
            ans.push_back(line);
            line={nums[i]};
        }
    }
    ans.push_back(line);
    return ans;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    int mid=-1;
    for(int i=0;i<nums.size();++i){
        if(nums[i]==-1)
            mid=i;
    }
    int maxv=*max_element(nums.begin(),nums.end());//?
    int left=1,right=n;
    vector<int> ans(n,0);
    map<int,vector<int>> mp;
    for(int i=0;i<nums.size();++i){
        mp[nums[i]].push_back(i);
    }
    for(int j=1;j<=maxv;++j){
        if(j%2){
            vector<int> idxs=mp[j];
            for(int i=0;i<idxs.size()&&idxs[i]<mid;++i){
                ans[idxs[i]]=right--;
            }
            for(int i=idxs.size()-1;i>=0&&idxs[i]>mid;--i){
                ans[idxs[i]]=right--;
            }
        }
        else{
            vector<int> idxs=mp[j];
            for(int i=0;i<idxs.size()&&idxs[i]<mid;++i){
                ans[idxs[i]]=left++;
            }
            for(int i=idxs.size()-1;i>=0&&idxs[i]>mid;--i){
                ans[idxs[i]]=left++;
            }
        }
        //print(ans);
    }
    for(int &x:ans){
        if(x==0){
            x=left;
        }
    }
    print(ans);
}
