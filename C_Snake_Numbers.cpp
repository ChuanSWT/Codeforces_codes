#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <iomanip>
#include <numeric>
#include <functional>
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
    //cin >> roundc;
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
//if top==0 可继续指定
int dfs(int i,string &s,int top,int is_limit,map<vector<int>,int> &mp)
{
    if(i==s.size())
        return 1;
    //cout<<top<<" "<<i<<endl;
    if(!is_limit)
        if(mp.find({top,i})!=mp.end())
            return mp[{top,i}];
    int sum=0;
    if(top==-1)
    {
        for(int take=0;take<=9;++take)
        {
            if(take==0)
            sum+=dfs(i+1,s,-1,0,mp);
            else
            sum+=dfs(i+1,s,take,0,mp);
        }
    }
    else
    {
    for(int take=0;take<=9;++take)
    {
        if(take>=top)
        continue;
        if(!is_limit)
        {
            sum+=dfs(i+1,s,top,0,mp);
        }
        else
        {
            if(take+'0'>s[i])
                continue;
            sum+=dfs(i+1,s,top,take+'0'==s[i],mp);
        }
        
    }
    }
    mp[{top,i}]=sum;
    return sum;
}
bool check(string s)
{
    for(int i=1;i<s.size();++i)
    {
        if(s[i]>=s[0])
        return false;
    }
    return true;
}
void compete_solution()
{
    string left,right;
    cin>>left;
    cin>>right;
    int ans=0;
    for(int head=0;head<=9;++head)
    {
        if(head+'0'<=right[0])
        {
            if(head==0)
            {
                map<vector<int>,int> mp1;
                ans+=dfs(1,right,-1,0,mp1);
                //map<vector<int>,int> mp2;
                //ans-=dfs(1,left,-1,0,mp2);
                continue;
            }
            map<vector<int>,int> mp1;
            ans+=dfs(1,right,head,head+'0'==right[0],mp1);
            //map<vector<int>,int> mp2;
            //ans-=dfs(1,left,head,head+'0'==left[0],mp2);
        }
    }
    for(int head=0;head<=9;++head)
    {
        if(head+'0'<=left[0])
        {
            if(head==0)
            {
                //map<vector<int>,int> mp1;
                //ans+=dfs(1,right,-1,0,mp1);
                map<vector<int>,int> mp2;
                ans-=dfs(1,left,-1,0,mp2);
                continue;
            }
            //map<vector<int>,int> mp1;
            //ans+=dfs(1,right,head,head+'0'==right[0],mp1);
            map<vector<int>,int> mp2;
            ans-=dfs(1,left,head,head+'0'==left[0],mp2);
        }
    }
    ans+=check(left);
    cout<<ans<<endl;
}