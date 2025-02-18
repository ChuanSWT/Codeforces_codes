#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
#include<tuple>
using namespace std;
#define MOD 1000000007
void compete_solution();
int main()
{
    int roundc;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
vector<int> make_vector(int length)
{
    vector<int> a(length,0);
    for(int i=0;i<length;++i)
    cin>>a[i];
    return a;
}
void compete_solution()
{
    int n;
    cin>>n;
    vector<int> nums=make_vector(n);
    int left=1,right=1e9;
    long long min1=LLONG_MAX;
    vector<int>rst;
    while(left<right)
    {
        int mid=(left+right)/2;
        long long need=0;
        vector<int> ans;
        for(int n:nums)
        {
        need+=mid/n+((mid%n)!=0);
        ans.push_back(mid/n+((mid%n)!=0));
        }
        if(need>=mid)
        left=mid+1;
        else
        {
            if(need<min1)
            {
                rst=ans;
                min1=need;
            }
            right=mid;
        }
    }
    if(rst.empty())
    cout<<-1<<endl;
    else
    {
    for(int n:rst)
    cout<<n<<" ";
    cout<<endl;
    }
}