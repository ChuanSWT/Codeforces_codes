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
    string s;
    cin>>s;
    int k;
    cin >> k;
    vector<int> nums;
    for(char c:s){
        nums.push_back(c-'0');
    }
    int n=nums.size();
    //21 1
    //1
    //考虑第一个出现0的地方
    //210888 3
    //210 :108
    //对于前一段 操作一定能降低它吗？
    //1230999 1
    //123099 : 120999
    //尽快在高位进行操作
    
    //!自高位，当s[i]>s[i+1]时删除s[i]
    //有些情况需要主动消去0 需要确保是正整数
    //!先不考虑0，最后如果有前导再调整

    vector<int> nxt_mn=nums;
    for(int i=n-2;i>=0;--i){
        nxt_mn[i]=min(nxt_mn[i],nxt_mn[n+1]);
    }
    vector<int> mark(n,0);
    int cnt=0;
    for(int i=0;i<n&&cnt<n;++i){
        if()
    }

}