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




void compete_solution()
{
    int n;
    cin >> n;
    vector<int> parent=cin_nums(n-1);
    for(int &x:parent)
        --x;
    parent.insert(parent.begin(),-1);
    //统计 同级同根的孩子
    vector<vector<int>> edges(n+1);
    for(int i=0;i<parent.size();++i){
        if(parent[i]==-1)
            continue;
        edges[i].push_back(parent[i]);
        edges[parent[i]].push_back(i);
    }
    //cout<<"hi"<<endl;
    //return;
    vector<int> dfs_rsts={1};
    auto dfs=[&](auto&&dfs,int cur,int pre)->void{
        int rst=0;
        for(int x:edges[cur]){
            if(x==pre)
                continue;
            rst+=1;
            dfs(dfs,x,cur);
        }
        if(rst!=0)
            dfs_rsts.push_back(rst);
    };
    dfs(dfs,0,-1);
    //print(dfs_rsts);
    vector<int> nums;
    for(int x:dfs_rsts){
        nums.push_back(x);
    }
    //先在第一轮全部感染一下
    sort(nums.rbegin(),nums.rend());
    int maxv=0;
    //print(nums);
    for(int i=0;i<nums.size();++i){
        maxv=max(maxv,i+nums[i]);
        nums[i]-=(int)nums.size()-i;
        nums[i]=max(0ll,nums[i]);
    }
    if(accumulate(nums.begin(),nums.end(),0)==0){
        cout<<maxv<<endl;
        return;
    }
    int real_ans=nums.size();
    while(nums.size()){
        sort(nums.rbegin(),nums.rend());
        nums[0]=max(nums[0]-1,0ll);
        for(int &x:nums){
            x=max(x-1,0ll);
        }
        while(nums.size()&&nums.back()==0)
            nums.pop_back();
        ++real_ans;
    }
    cout<<real_ans<<endl;
    
    
}