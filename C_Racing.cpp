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




bool check(vector<int> nums,vector<vector<int>> queries){
    int cur=0;
    for(int i=0;i<nums.size();++i){
        int left=queries[i][0],right=queries[i][1];
        cur+=nums[i];
        if(cur<left||cur>right)
            return false;
    }
    return true;
}
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=cin_nums(n);

    vector<vector<int>> queries=cin_matrix(n,2);
    //前面可停可上升
    vector<int> ans=nums;
    //反悔贪心
    vector<int> stk;
    int cur=0;
    for(int i=0;i<queries.size();++i){
        int left=queries[i][0],right=queries[i][1];
        if(nums[i]==-1)
            stk.push_back(i);
        else{
            cur+=nums[i];
        }
        while(cur<left){
            if(stk.empty()){
                cout<<-1<<endl;
                return;
            }
            int idx=stk.back();
            stk.pop_back();
            ans[idx]=1;
            ++cur;
        }
    }
    for(int &x:ans){
        if(x==-1)
            x=0;
    }
    if(!check(ans,queries)){
        cout<<-1<<endl;
        return;
    }
    print(ans);




    
}