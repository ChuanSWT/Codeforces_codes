#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;


void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
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
    cin>>n;
    vector<int> raw=cin_nums(n);
    vector<int> ned=cin_nums(n);
    int limit=0x3f3f3f3f;
    priority_queue<int,vector<int>,less<>> pq;
    int sum=0;
    for(int i=0;i<raw.size();++i){
        if(raw[i]>=ned[i])
            limit=min(limit,raw[i]-ned[i]);
        else{
            sum+=ned[i]-raw[i];
            pq.push(ned[i]-raw[i]);
        }

    }
    if(limit==0x3f3f3f3f){
        cout<<"NO"<<endl;
        return;
    }
    if(pq.size()>=2){
        cout<<"NO"<<endl;
        return;
    }
    while(pq.size()){
        int val=pq.top();
        pq.pop();
        limit-=sum;
        sum-=val;
        if(limit<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}