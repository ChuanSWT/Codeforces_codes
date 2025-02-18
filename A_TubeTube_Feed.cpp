#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
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
    int round;
    cin >> round;
    vector<int> ans;
    for (int i = 0; i < round; ++i)
    {
        int n,t;
        cin>>n>>t;
        vector<int> time,fun;
        for(int i=0;i<n;++i)
        {
            int temp=0;
            cin>>temp;
            time.push_back(temp);
        }
        for(int i=0;i<n;++i)
        {
            int temp=0;
            cin>>temp;
            fun.push_back(temp);
        }
        int max1=0;
        int index=-1;
        for(int i=0;i<n;++i)
        {
            if(time[i]+i<=t&&fun[i]>max1)
            {
                max1=fun[i];
                index=i;
            }
        }
        if(index!=-1)
        ans.push_back(index+1);
        else
        ans.push_back(index);
    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}
