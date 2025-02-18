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
int cal(int n,vector<vector<int>> raw_edges)
{
    vector<int> nums(n,0);
    for(auto arr:raw_edges)
    {
        ++nums[arr[0]];
        ++nums[arr[1]];
    }
    int cnt=0;
    for(int x:nums)
    if(x==1)
    ++cnt;
    return cnt*(n-cnt);
}
class meth{
    public:
    vector<vector<int>> edges;
    vector<int> lock;
    vector<int> rank;
    meth(int n,vector<vector<int>> raw_edges):edges(n),lock(n,0),rank(n,0)
    {
        for(auto arr:raw_edges)
        {
            edges[arr[0]].push_back(arr[1]);
            edges[arr[1]].push_back(arr[0]);
            ++lock[arr[0]];
            ++lock[arr[1]];
        }
    }
    void make_rank()
    {
        vector<int> cur;
        vector<int> nxt;
        set<int> st;
        for(int i=0;i<lock.size();++i)
            if(lock[i]==1)
            {
                cur.push_back(i);
                st.insert(i);
            }
        int cur_rank=0;
        while(cur.size())
        {
            while(cur.size())
            {
                int node=cur.back();
                cur.pop_back();
                --lock[node];
                rank[node]=cur_rank;
                for(int x:edges[node])
                {
                    --lock[x];
                    if(st.find(x)==st.end())
                    {
                    nxt.push_back(x);
                    st.insert(x);
                    }
                }

            }
            ++cur_rank;
            cur=nxt;
            nxt.clear();
        }
    }
    int find_edge(vector<vector<int>> raw_edges)
    {
        int ans=0;
        //print(rank);
        for(auto arr:raw_edges)
        {
            if(rank[arr[0]]==1&&rank[arr[1]]==1)
            ++ans;
        }
        return ans;
    }
    int find_point()
    {
        int ans=0;
        for(int x:rank)
        if(x==2)
        ++ans;

        return ans;
    }
};
void compete_solution()
{
    int n;
    cin >> n;
    vector<vector<int>> raw_edges=cin_edges(n-1,2);
    for(auto &arr:raw_edges)
    {
        --arr[0];
        --arr[1];
    }
    int ans=0;
    ans+=cal(n,raw_edges);
    //找到最小深度为2以上的点，可以作为对手的起点
    meth *test=new meth(n,raw_edges);
    test->make_rank();
    int p_cnt=test->find_point();
    
    int e_cnt=test->find_edge(raw_edges);
    //cout<<p_cnt<<endl;
    //cout<<e_cnt<<endl;
    ans+=p_cnt*e_cnt;
    cout<<ans<<endl;

    
    
}