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
    cin >> n;
    vector<int> a=cin_nums(n);
    vector<int> b=cin_nums(n);
    vector<int> d=cin_nums(n);
    for(int i=0;i<n;++i){
        --a[i];
        --b[i];
    }
    map<int,int> mp;
    for(int i=0;i<b.size();++i){
        mp[b[i]]=i;
    }
    vector<int> mark(n,0);
    //考虑环
    //1 3 2 4
    //3 4 1 2
    //0 0 0 0
    //1 3 2 4
    //3 4 1 2

    //1 0 0 0
    //其中若有元素被固定 则回环失效 *1
    int mod=1e9+7;
    int ans=1;
    for(int i=0;i<n;++i){
        if(mark[i])
            continue;
        mark[i]=1;
        if(a[i]==b[i])
            continue;
        
        bool cnt=d[i]!=0;

        int cur=mp[a[i]];
        while(cur!=i){
            cnt+=d[cur]!=0;
            mark[cur]=1;
            cur=mp[a[cur]];
        }
        //cout<<cnt<<endl;
        if(cnt==0){
            ans*=2;
            ans%=mod;
        }
    }
    cout<<ans<<endl;


    
}