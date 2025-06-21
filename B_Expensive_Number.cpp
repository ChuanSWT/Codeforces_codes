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
    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
    for(char c:s){
        if(c=='0')
            cnt+=1;
    }
    if(cnt==0){
        cout<<s.size()-1<<endl;
        return;
    }
    //现在至少有一个0
    //302010 ans=2
    //枚举个位数
    //结果一定是1
    int maxv=0;//可以保留的0的数量
    for(int i=0;i<s.size();++i){
        if(s[i]=='0')
            continue;
        int val=s[i]-'0';
        int sum=0;
        for(int j=0;j<i;++j){
            sum+=s[j]=='0';
        }
        maxv=max(maxv,sum);
    }
    cout<<n-maxv-1<<endl;
    

    
}