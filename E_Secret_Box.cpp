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
vector<int> cin_vector(int length)
{
    vector<int> a(length,0);
    for(int i=0;i<length;++i)
    cin>>a[i];
    return a;
}
vector<long long> gcd_v(long long n)
{
    //cout<<n<<endl;
    vector<long long> ans;
    for(long long i=1;i*i<=n;++i)
    if(n%i==0)
    ans.push_back(i);
    /*for(int n:ans)
    cout<<n<<" ";
    cout<<endl;*/
    return ans;
}
void compete_solution()
{
    long long x,y,z,k;
    cin>>x>>y>>z>>k;
    if(y>z)
    swap(y,z);
    long long ans=0;
    //cout<<"hi";
    for(long long i=1;i<=k&&i<=x;++i)
    {
        if(k%i)
        continue;
        long long a=i;
        long long scale=k/i;
        vector<long long> nums=gcd_v(k/i);
        for(long long n:nums)
        {
            //cout<<"hi";
            long long b=n;
            long long c=scale/n;
            if(b>y||c>z)
            continue;
            long long temp=1;
            temp*=(x-a+1);
            temp*=y-b+1;
            temp*=z-c+1;
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
    
}