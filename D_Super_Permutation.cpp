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
    vector<vector<int>> ans;
    for (int i = 0; i < round; ++i)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            ans.push_back({1});
            continue;
        }
        if(n%2)
        {
            ans.push_back({-1});
            continue;
        }
        int left=1,right=n;
        bool cur=true;
        int index=1;
        vector<int> arr(n+1,0);
        vector<int> ss;
        while(left<=right)
        {
            if(cur)
            {
                ss.push_back((left-index+n)%n);
                cur=false;
                index=left;
                ++left;
            }
            else
            {
                ss.push_back((right-index)%n);
                cur=true;
                index=right;
                --right;
            }
        }
        for(int &n1:ss)
        if(n1==0)
        {
           n1=n; 
           break;
        }
        ans.push_back(ss);

    }
    for (auto n : ans)
    {
        for(int num:n)
        cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
