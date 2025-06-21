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



int cal(string s){
    int cnt=0;
    for(int i=1;i<s.size();++i){
        cnt+=s[i]!=s[i-1];
    }
    return cnt;
}
bool check(string s){
    set<char> st;
    for(char c:s){
        st.insert(c);
    }
    return st.size()==1;
}
void compete_solution()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    if(check(s)){
        if(s[0]=='1'){
            cout<<s.size()+1<<endl;
        }
        else
            cout<<s.size()<<endl;
        return;
    }
    int rst=cal(s);
    int sum=s.size();
    if(s[0]=='1'){
        if(rst>=2){
            cout<<sum+rst-1<<endl;
        }
        else{
            cout<<sum+1<<endl;
        }
    }
    else{
        if(rst>=3){
            cout<<sum+rst-2<<endl;
        }
        else{
            cout<<sum+1<<endl;
        }

    }
    


    
}