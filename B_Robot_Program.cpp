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

int cal(string s){
    int cur=0;
    for(int i=0;i<s.size();++i){
        char c=s[i];
        if(c=='L'){
            --cur;
        }
        else{
            ++cur;
        }
        if(cur==0){
            return i+1;
        }
    }
    return -1;
}
int check_to_start(string s,int start){
    int cur=start;
    for(int i=0;i<s.size();++i){
        char c=s[i];
        if(c=='L'){
            cur-=1;
        }
        else{
            cur+=1;
        }
        if(cur==0){
            return i+1;
        }
    }
    return -1;
}
void compete_solution()
{
    int n,start,k;
    cin>>n>>start>>k;
    string s;
    cin>>s;
    int ans=0;
    if(start!=0){
        int to_start_rst=check_to_start(s,start);
        if(to_start_rst==-1){
            cout<<0<<endl;
            return;
        }
        else{
            ans+=1;
            k-=to_start_rst;
        }
    }
    int min_loop=cal(s);
    if(min_loop==-1){
        cout<<ans<<endl;
        return;
    }
    ans+=k/min_loop;
    cout<<ans<<endl;
}