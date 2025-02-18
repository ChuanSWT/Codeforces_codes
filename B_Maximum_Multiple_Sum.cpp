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
void compete_solution()
{
    int n;
    cin>>n;
    int maxv=0;
    int num=2;
    for(int i=2;i<=n;++i)
    {
        int sum=0;
        int t=i;
        int x=1;
        while(i*x<=n)
        {
            sum+=i*x;
            ++x;
        }
        if(sum>maxv)
        {
            maxv=sum;
            num=i;
        }
    }
    cout<<num<<endl;
    
}