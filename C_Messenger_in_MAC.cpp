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
int cal_mex(vector<int> nums){
    set<int> st;
    for(int x:nums)
    st.insert(x);
    int ans=0;
    while(st.find(ans)!=st.end())
        ++ans;
    return ans;
}
static bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
void compete_solution()
{
    int n,limit;
    cin>>n>>limit;
    vector<vector<int>> raw_queries=cin_edges(n,2);
    /*
4 3
1 5   2
2 4   1
4 3
2 3   3
    */
    //第一项加起来
    //第二项找最短？
    //第一项是阅读信息花费时间
    //第二项是信息的位置，之间周转会耗费时间
    //近且信息大 远且信息小
    //可以n2
    //滑窗？
    //先相对位置归0
    //并且排序

    vector<vector<int>> queries=raw_queries;
    sort(queries.begin(),queries.end(),compare);
    for(int i=queries.size()-1;i>=0;--i){
        queries[i][1]-=queries[0][1];
    }
    //for(auto arr:queries)
    //    print(arr);
/*
4 0 
4 0 
2 0 
2 1 
1 2 
*/
    //信息可能不是连续
    //值域大
    //dp?
    //到当前结尾时 ？ 是否可行?
    //或者枚举开头?
    //枚举所有区间？
    int ans=0;
    for(int start=0;start<queries.size();++start){
        priority_queue<int> pq;
        int pq_sum=0;
        int d_sum=0;
        for(int end=start;end<queries.size();++end){
            d_sum=queries[end][1]-queries[start][1];
            if(d_sum>limit)
                break;
            pq.push(queries[end][0]);
            pq_sum+=queries[end][0];
            while(pq_sum+d_sum>limit){
                int val=pq.top();
                pq.pop();
                pq_sum-=val;
                
            }
            ans=max(ans,(int)pq.size());
        }
    }
    cout<<ans<<endl;
    
}