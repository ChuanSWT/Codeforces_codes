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




bool check(vector<int> &nums,vector<vector<pair<int,int>>> &edges,int limit){
    //尽量多拿点
    //确保到每个点时拿了最多的电池
    //由前驱决定
    int n=nums.size();
    vector<int> mem(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq;
    pq.push({0,0});
    while(pq.size()){   
        auto p=pq.top();
        pq.pop();
        int cur=p.first;
        int cur_d=p.second;
        if(min(cur_d+nums[cur],limit)<=mem[cur])
            continue;
        mem[cur]=min(cur_d+nums[cur],limit);
        if(cur==n-1)
            break;
        for(auto& arr:edges[cur]){
            int x=arr.first,cost=arr.second;
            if(min(mem[cur],limit)>=cost){
                pq.push({x,mem[cur]});
            }
        }
    }
    return mem[n-1]!=-1;
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums=cin_nums(n);

    vector<vector<int>> r_edges=cin_matrix(m,3);
    for(auto &arr:r_edges){
        --arr[0];
        --arr[1];
    }
    vector<vector<pair<int,int>>> edges(n);
    for(auto arr:r_edges){
        int x=arr[0],y=arr[1],cost=arr[2];
        edges[x].push_back({y,cost});
    }
    int left=1,right=0x3f3f3f3f;
    while(left<right){
        int mid=(left+right)/2;
        if(!check(nums,edges,mid)){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    if(left==0x3f3f3f3f){
        cout<<-1<<endl;
        return;
    }
    cout<<left<<endl;

    



    
}