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
    //1 0 0 1 ==9
    //1 1 1 0 ==7
    //0 1 1 1 ==14

    //1 0 1
    //1 1 0
    //0 1 1
    //1 0 1 1==13
    //1 1 0 0==3
    //0 1 1 1==14
    //两种情况 全是1？
    //2的幂次？
    //全0到全1
    //0 0 1 1
    //1 1 0 0
    //1 1 1 1

    //1 0 1
    //1 1
    //0 1 1
    set<int> st;
    for(int i=0;i<=30;++i){
        st.insert(1<<i);
    }
    if(st.count(n)||st.count(n+1)){
        cout<<-1<<endl;
    }
    else{
        int index=0;
        
        for(int i=0;i<=30;++i){
            if(((1<<i)&n)){
                index=i;
            }
        }
        cout<<(1<<index)-1<<endl;
        

    }
}