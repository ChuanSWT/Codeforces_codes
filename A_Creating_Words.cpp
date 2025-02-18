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
    string a,b;
    cin>>a;
    cin>>b;
    swap(a[0],b[0]);
    cout<<a<<" "<<b<<endl;
    
}