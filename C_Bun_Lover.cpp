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
    vector<long long> ans;
    for (int i = 0; i < round; ++i)
    {
        long long n;
        cin>>n;
        long long plus=(3+n);
        long long temp=5+(n-1)*plus;
        ans.push_back(temp);
    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}
