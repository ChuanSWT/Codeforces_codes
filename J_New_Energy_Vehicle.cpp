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
using namespace std;
void compete_solution();
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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
void cal(long long sum,vector<int> &provide,vector<int> &d)
{
    long long cur=sum;
    long long ans=sum;
    int pre=0;
    for(int i=0;i<provide.size();++i)
    {
        cur-=d[i]-pre;
        pre=d[i];
        if(cur<0)
        break;
        cur+=provide[i];
        ans+=provide[i];
    }
    cout<<ans<<'\n';
}
map<int,int> makeNxt(vector<int> type)
{
    map<int,int> ans;
    map<int,int> mp;
    for(int i=0;i<type.size();++i)
    {
        if(mp.find(type[i])==mp.end())
            mp[type[i]]=i;
        else
        {
            ans[mp[type[i]]]=i;
            mp[type[i]]=i;
        }
    }
    //for(auto p:ans)
    //cout<<p.first<<" "<<p.second<<endl;
    return ans;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> makePq(vector<int> &d,vector<int> &type)
{
    set<int> st;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> ans;
    for(int i=0;i<type.size();++i)
    {
        if(st.find(type[i])==st.end())
        {
        st.insert(type[i]);
        ans.push({d[i],i});
        }
    }
    return ans;
}
void compete_solution()
{
    int n, m;
    cin >> n>> m;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    vector<int> d(m);
    vector<int> type(m);
    for(int i=0;i<m;++i)
    {
    cin>>d[i]>>type[i];
    --type[i];
    }

    vector<int> max_provide(m);
    for (int i = 0; i < max_provide.size(); ++i)
        max_provide[i] = nums[type[i]];

    vector<int> cur_provide(m, 0);
    int nxt=d.back();

    //set<int> cur_types;
    vector<int> cache;

    vector<int> mark(m,0);//标记后则直接废弃
    map<int,int> nxt_mp=makeNxt(type);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq=makePq(d,type);
    int pre=0;
    for(int i=0;i<m;++i)
    {
        int sum=d[i]-pre;
        pre=d[i];
        while(sum!=0&&!pq.empty())
        {
            auto arr=pq.top();
            if(arr.first<d[i])
            {
                pq.pop();
                continue;
            }
            if(sum>=max_provide[arr.second]-cur_provide[arr.second])
            {
                sum-=max_provide[arr.second]-cur_provide[arr.second];
                cur_provide[arr.second]=max_provide[arr.second];
                pq.pop();
            }
            else
            {
                cur_provide[arr.second]+=sum;
                sum=0;
            }
        }
        if(nxt_mp.find(i)!=nxt_mp.end())
        {
            int nxt_samet_index=nxt_mp[i];
            pq.push({d[nxt_samet_index],nxt_samet_index});
        }
    }
    long long sum2=0;
    for(auto &x:nums)
        sum2+=x;
    cal(sum2,cur_provide,d);
}