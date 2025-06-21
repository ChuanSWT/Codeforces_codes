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
void debug(int n)
{
    cout << n << endl;
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
    int x, y;
    cin >> x >> y;

    if(x==y){
        cout<<-1<<endl;
        return;
    }
    //主要解决1的同时存在矛盾
    int minv=0x3f3f3f3f;
    int maxv=-1;
    for(int i=0;i<40;++i){
        int mask=1ll<<i;
        if((x&mask)&&(y&mask)){
            maxv=max(maxv,i);
            minv=min(minv,i);
        }
    }
    if(minv==-1){
        cout<<-1<<endl;
        return;
    }
    int ans=0;
    bool status=0;
    for(int i=minv;i<=40;++i){
        if((x^y)==(x|y))
            break;
        
        int mask=1ll<<i;
        if((x&mask)&&(y^mask)){
            status=1;
        }
        if((x&mask)(y^mask))
        x+=mask;
        y+=mask;
        ans+=mask;
    }
    cout<<ans<<endl;



}