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
int main()
{
    int roundc;
    cin >> roundc;
    vector<int> ans;
    for (int ic = 0; ic < roundc; ++ic)
    {
        int n;
        cin>>n;
        vector<int> nums,arr;
        for(int i=0;i<n;++i)//熊孩子搞破坏前的数组
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        for(int i=0;i<n;++i)//你找到的数组，也许是他的杰作
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        int m;
        cin>>m;
        vector<int> vals;
        for(int i=0;i<m;++i)//熊孩子用的工具的后半
        {
            int temp;
            cin>>temp;
            vals.push_back(temp);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=arr[i])
            mp[arr[i]]++;//查出是修改后的
        }
        for(int i=0;i<vals.size();++i)
        {
            mp[vals[i]]--;
        }
        bool safe=true;
        for(auto p:mp)
        if(p.second>0)
        safe=false;
        if(safe)
        {
            bool d=false;
            for(int n:arr)
            if(vals.back()==n)
            d=true;
            if(d)
        cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;

    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}