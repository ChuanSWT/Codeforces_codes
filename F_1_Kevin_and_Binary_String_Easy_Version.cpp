#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto &arr : ans)
    {
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
    }
    return ans;
}
__int128 cal(int n){
    __int128 ans=1;
    for(int i=1;i<=n;++i)
    ans*=i;
    return ans;
}
int s2i(string s){
    int ans=0;
    for(int i=0;i<s.size();++i){
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}
bool check(string a,string b){
    map<char,int> mp;
    for(char c:a){
        mp[c]++;
    }
    for(char c:b){
        mp[c]--;
    }
    for(auto [_,cnt]:mp){
        if(cnt){
            return false;
        }
    }
    return true;
}
int cal(string s){
    int cnt=0;
    for(int i=0;i+1<s.size();++i){
        if(s[i]=='0'&&s[i+1]=='1')
            ++cnt;
    }
    return cnt;
}
int tran(vector<int>& mark,string &s,int index){
    int cnt=0;
    for(int i=index;i<s.size();++i){
        if(s[i]!=s[index])
            break;
        ++cnt;
        mark[i]=1;
    }
    return cnt;
}
bool s_check(string a,string b){
    int cur=0;
    int 
}
void compete_solution()
{
    string a,b;
    cin>>a>>b;
    if(!check(a,b)){
        cout<<-1<<endl;
        return;
    }
    int a_cnt=cal(a);
    int b_cnt=cal(b);
    int ans=a_cnt-b_cnt;
    //vector<int> a_arr=extract(a);
    //vector<int> a_arr=extract(a);
    if(s_check(a,b)){
        cout<<ans<<endl;
    }

}