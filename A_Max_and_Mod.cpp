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


bool quickCheck(vector<int>&path){
    if(path.size()<=1)
        return true;
    int n=path.size();
    int mx=max(path[n-1],path[n-2]);
    int target=n-1;
    if(mx%n!=target){
        return false;
    }
    return true;
}
void compete_solution()
{
    int n;
    cin >> n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }
    vector<int> ans={n};
    for(int i=1;i<n;++i){
        ans.push_back(i);
    }
    print(ans);
    /*vector<int> path;
    vector<int> mark(n,0);
    auto dfs=[&](auto&&dfs){
        if(!quickCheck(path))
            return;
        if(path.size()==n){
            print(path);
            return;
        }
        for(int i=0;i<mark.size();++i){
            if(mark[i])
                continue;
            mark[i]=1;
            path.push_back(i+1);
            dfs(dfs);
            path.pop_back();
            mark[i]=0;

        }
    };
    dfs(dfs);*/
    

    
}