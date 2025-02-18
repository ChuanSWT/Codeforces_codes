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
    cin >> n;
    vector<int> nums=cin_nums(n);

    map<int,int> mp;
    for(int x:nums)
        ++mp[x];
    priority_queue<int> pq;
    vector<int> ans(n+1,-1);
    /*ans[0]=mp[0];
    for(int i=0;i<mp[0];++i)
        pq.push(0);*/
    vector<int> base_ans(n+1,0);
    for(int i=0;i<ans.size();++i)
    {
        if(i!=0)
        base_ans[i]+=base_ans[i-1];
        int pre_target=i-1;
        int target=i;
        int rst=0;
        if(mp.find(target)!=mp.end())
            rst+=mp[target];
        if(pre_target!=-1)
        {
            if(pq.size()==0)
            {
                break;
            }
            //cout<<pq.top()<<endl;
            base_ans[i]+=pre_target-pq.top();
            rst+=base_ans[i];
            pq.pop();
        }
        for(int j=0;j<mp[target];++j)
            pq.push(target);
        ans[i]=rst;
    }
    print(ans);


    
}