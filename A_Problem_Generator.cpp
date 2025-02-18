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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> arr(7,0);
        for(char c:s)
        ++arr[c-'A'];
        int sum=0;
        for(int n1:arr)
        if(n1<m)
        sum+=m-n1;
        ans.push_back(sum);

    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}