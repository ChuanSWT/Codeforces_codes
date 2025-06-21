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
    int n,x;
    cin >> n>>x;
    if(n==1&&x==0){
        cout<<-1<<endl;
        return;
    }
    if(n==1){
        cout<<x<<endl;
        return;
    }
    if(x==1){
        if(n%2==0){
            cout<<n+3<<endl;

        }
        else{
            cout<<n<<endl;
        }
        return;
    }
    if(x==0){
        if(n%2==0){
            cout<<n<<endl;
        }
        else{
            cout<<n+3<<endl;
        }
        return;
    }
    int len=n;
    vector<int> ans;
    while(x!=0&&len!=0){
        --len;
        int idx=-1;
        for(int i=0;i<40;++i){
            int mask=1ll<<i;
            if(mask&x){
                idx=i;
            }
        }
        ans.push_back(1<<idx);
        x-=1<<idx;
    }
    if(x!=0){
        ans.back()^=x;
        x=0;
    }

    int rst=0;
    rst+=accumulate(ans.begin(),ans.end(),0ll);
    if(len%2==0){
        rst+=len;
    }
    else{
        rst+=len+1;
    }
    cout<<rst<<endl;




    
}