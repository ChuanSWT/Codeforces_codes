#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <iomanip>
#include <numeric>
#include <assert.h>
#define int long long

using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        compete_solution();
    }
    return 0;
}
void debug(int n){
    cout<<n<<endl;
}
template <typename T>
void print(const std::vector<T> &vec)
{
    for (auto element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

vector<int> cin_nums(int n)
{
    vector<int> ans(n);
    for (auto &x : ans)
        cin >> x;
    return ans;
}
vector<vector<int>> cin_matrix(int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto &arr : ans)
    {
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
    }
    return ans;
}



vector<int> count(string s,int offset){
    vector<int> ans(2,0);
    for(int i=offset;i<s.size();i+=2){
        if(s[i]=='0')
            ++ans[0];
        else
            ++ans[1];
    }
    return ans;
}
void compete_solution()
{
    int n;
    cin >> n;
    string s1,s2;
    cin>>s1>>s2;
    vector<int> rst10=count(s1,0);
    vector<int> rst11=count(s1,1);
    vector<int> rst20=count(s2,0);
    vector<int> rst21=count(s2,1);
    if(rst10[1]<=rst21[0]&&rst11[1]<=rst20[0]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}