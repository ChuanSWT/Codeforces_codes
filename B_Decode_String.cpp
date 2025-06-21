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
    cin>>n;
    string s;
    cin>>s;
    vector<string> strs;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='0'){
            strs.push_back(s.substr(i-2,3));
            i-=2;
        }
        else{
            strs.push_back(s.substr(i,1));
        }
    }
    /*for(auto str:strs){
        cout<<str<<endl;
    }*/
    string ans;
    for(string str:strs){
        if(str.size()==1){
            ans+=(str[0]-'1'+'a');
        }
        else{
            ans+=(char)('a'+10*(str[0]-'0')+1*(str[1]-'1'));
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


}