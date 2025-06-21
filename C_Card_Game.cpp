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



void compete_solution()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    if(s[0]=='B'&&s.back()=='B'){
        cout<<"Bob"<<endl;
        return;
    }
    if(s[0]=='A'&&s.back()=='A'){
        cout<<"Alice"<<endl;
        return;
    }
    map<char,int> mp;
    for(char c:s){
        ++mp[c];
    }
    if(s[0]=='B'&&s.back()=='A'){
        if(s[n-2]=='B'){
            cout<<"Bob"<<endl;
            return;
        }
        else{
            cout<<"Alice"<<endl;
            return;
        }
    }


    if(s[0]=='A'&&s.back()=='B'){
        if(mp['B']==1){
            cout<<"Alice"<<endl;
            return;
        }
        else{
            cout<<"Bob"<<endl;
            return;
        }
    }


    
}