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



void compete_solution()
{
    int n;
    cin >> n;
    //1是尽快入座
    //0是找完全空桌入座
    vector<int> nums=cin_nums(n);
    auto compare=[](vector<int>&a,vector<int>&b){
    if(a[0]!=b[0])
        return a[0]>b[0];
    if(a[1]!=b[1])
        return a[1]>b[1];
       
    return a[2]>b[2];

    };

    priority_queue<vector<int>,vector<vector<int>>,decltype(compare)> table_pq(compare);
    priority_queue<vector<int>,vector<vector<int>>,decltype(compare)> seat_pq(compare);
    int length=4*(sqrt(n)+5);

    for(int x=0;x<=length;++x){
        for(int y=0;y<=length;++y){
            if((x%3==1)&&(y%3==1)){
                //cout<<x+y-1<<" "<<x<<" "<<y<<endl;
                table_pq.push({x+y-1,x,y});
            }
        }
    }
    vector<int> dx={0,1,0,1};
    vector<int> dy={0,0,1,1};
    vector<int> cost={0,1,1,4};
    vector<vector<int>> ans;
    for(int request:nums){
        if((request==0)||seat_pq.empty()||(table_pq.top()[0]<seat_pq.top()[0])){
            auto arr=table_pq.top();
            table_pq.pop();
            int d=arr[0],x=arr[1],y=arr[2];
            ans.push_back({x,y});
            for(int i=1;i<dx.size();++i){
                seat_pq.push({d+cost[i],x+dx[i],y+dy[i]});
            }
        }
        else{
                auto arr=seat_pq.top();
                seat_pq.pop();
                int d=arr[0];
                int x=arr[1],y=arr[2];
                ans.push_back({x,y});
        }
    }
    for(auto arr:ans)
        print(arr);
    
}