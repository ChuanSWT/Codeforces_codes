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



/*bool check1(vector<int> nums){
    for(int x:nums){
        if(x==0)
            return false;
    }
    return true;
}
vector<int> cal(vector<int> r_mst){
    vector<int> ans={0,0};
    for(int x:r_mst){
        if(x%2){
            ans[1]=max(ans[1],x);
        }
        else{
            ans[0]=max(ans[0],x);
        }
    }
    if(ans[0]==1)
    return ans;
}
bool check(int step,vector<int> limit){
    if(step%2==0){
        return step<=limit[0];
    }
    return step<=limit[1];
}*/
void compete_solution()
{
    int n,m,sz1;
    cin >> n>>m>>sz1;
    vector<int> mst=cin_nums(sz1);
    vector<vector<int>> r_edges=cin_matrix(m,2);
    sort(mst.begin(),mst.end());
    for(auto &arr:r_edges){
        for(int &x:arr)
            --x;
    }
    vector<int> odd_nums,even_nums;
    for(int x:mst){
        if(x%2)
            odd_nums.push_back(x);
        else    
            even_nums.push_back(x);
    }
    
    //是一个完全普通的图
    //mst中的是走路步数
    //从1出发
    //mst中最大值为1e4
    //输出每个点是否能到
    //奇数偶数分解?
    //奇数偶数都存在 即可以任意走
    //只有一方存在
    //：
    int sum=accumulate(mst.begin(),mst.end(),0ll);
    vector<vector<int>> edges(n);
    for(auto arr:r_edges){
        int x=arr[0],y=arr[1];
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int odd_sum=0,even_sum=0;
    for(int x:mst){
        if(x%2){
            odd_sum+=x;
        }
        else{
            even_sum+=x;
        }
    }
    int mx_odd,mx_even;
    if(odd_nums.size()%2){
        mx_odd=sum;
        mx_even=sum-odd_nums[0];
    }
    else{
        if(odd_nums.empty()){
            mx_odd=0;
            mx_even=sum;
        }
        else{
        mx_odd=sum-odd_nums[0];
        mx_even=sum;
        }
    }
    //cout<<mx_odd<<" "<<mx_even<<endl;
    vector<vector<int>> mem(n,vector<int>(2,0));
    vector<vector<int>> tried(n,vector<int>(2,0));
    //深度 当前节点
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,0});
    
    while(pq.size()){
        auto p=pq.top();
        pq.pop();
        int cur_d=p.first;
        int cur=p.second;
        if(cur_d>sum)
            continue;
        if(mem[cur][cur_d%2])
            continue;
        if(tried[cur][cur_d%2])
            continue;
        tried[cur][cur_d%2]=1;
        if(((cur_d%2==0&&cur_d<=mx_even)||(cur_d%2==1&&cur_d<=mx_odd)))
            mem[cur][cur_d%2]=1;    
        for(int x:edges[cur]){
            if(!mem[x][(cur_d+1)%2])
                pq.push({cur_d+1,x});
        }

    }
    //for(auto arr:mem)
        //print(arr);
    mst[0]=sum;
    string s;
    for(int i=0;i<n;++i){
        if(mem[i][0]+mem[i][1]){
            s+='1';
        }
        else{
            s+='0';
        }
    }
    cout<<s<<endl;

    
}