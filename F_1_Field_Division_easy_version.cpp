#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define MOD 1000000007
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.first>b.first)
    return false;
    if(a.second>b.second)
    return false;
    return true;
}
int main()
{
    int roundc;
    cin >> roundc;
    vector<int> ans;
    for (int ic = 0; ic < roundc; ++ic)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>> cache;
        for(int i=0;i<k;++i)
        {
            int t1,t2;
            cin>>t2>>t1;
            cache.push_back(make_pair(t1,t2));
        }
        sort(cache.begin(),cache.end(),compare);
        long long sum=0;
        vector<vector<int>> left;
        //left.push_back({-1,-1});
        for(auto p:cache)
        {
            left.push_back({p.second,p.first});
            //cout<<p.second<<" "<<p.first<<endl;
        }
        //cout<<"hi"<<endl;
        vector<vector<int>> nums;
        for(int i=0;i<left.size();++i)
        {
            if(nums.empty())
            nums.push_back(left[i]);
            else
            {
            while(left[i][1]<nums.back()[1])
            nums.pop_back();
            nums.push_back(left[i]);
            }
        }
        /*for(auto a:nums)
        {
            for(auto b:a)
            cout<<b<<" ";
            cout<<endl;
        }*/
        /*
1 2 
2 2 
4 3 */
set<vector<int>> st;
for(auto p:left)
st.insert({p[1],p[0]});
        for(int i=1;i<nums.size();++i)
        sum+=(nums[i][0]-nums[i-1][0])*nums[i][1];
        sum+=nums[0][0]*nums[0][1];
        sum+=(n-nums.back()[0]-1)*nums.back()[1];
        cout<<sum<<endl;
        for(int i=0;i<k;++i)
        {
            if(st.find({cache[i].second,cache[i].first})==st.end())
            cout<<0<<" ";
            else
            cout<<1<<" ";
        }
        cout<<endl;
    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}