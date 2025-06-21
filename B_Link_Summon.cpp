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




int init_make(vector<int>& nums){
    int cnt=0;
    for(int i=0;i<4;++i){
        if(nums[4]>=nums[i]){
            int temp=nums[i];
            cnt+=temp;
            nums[4]-=temp;
            nums[i]-=temp;
        }
        else{
            int temp=nums[4];
            cnt+=temp;
            nums[4]-=temp;
            nums[i]-=temp;
        }
    }
    cnt+=nums[2]/2;
    nums[2]%=2;
    return cnt;
}
int pp(vector<int> &nums,vector<int> op){
    int minv=0x3f3f3f3f;
    for(int i=0;i<nums.size();++i){
        if(op[i]){
            minv=min(minv,nums[i]/op[i]);
        }
    }
    for(int i=0;i<nums.size();++i){
        nums[i]-=minv*op[i];
    }
    return minv;
}
int cal(vector<vector<int>> &ops,vector<int> nums){
    int ans=0;
    for(int i=0;i<ops.size();++i){
        int rst=pp(nums,ops[i]);
        ans+=rst;
    }
    ans+=(nums[0]+nums[1]*2ll)/6ll;
    return ans;
}
void compete_solution()
{
    vector<int> nums=cin_nums(5);
    int ans1=0;
    ans1+=init_make(nums);
    if(nums.back()){
        cout<<nums.back()/2+ans1<<endl;
        return;
    }
    vector<vector<int>> ops={
        {2,0,0,1,0},
        {0,1,0,1,0},
        {0,0,1,1,0},
        {0,0,0,2,0},
        {3,0,1,0,0},
        {1,1,1,0,0},
        {0,2,1,0,0},
        {0,3,0,0,0},
        
    };
    sort(ops.begin(),ops.end());
    
    int ans2=0;
    int cnt=0;
    while(true){
        int rt=cal(ops,nums);
        ans2=max(ans2,rt);
        ++cnt;
        bool flag=next_permutation(ops.begin(),ops.end());
        if(!flag){
            //cout<<cnt<<endl;
            break;
        }
    }
    cout<<ans1+ans2<<endl;





    
}