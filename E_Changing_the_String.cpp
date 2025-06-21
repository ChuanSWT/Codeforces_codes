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
#include <unordered_map>
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<char>> queries(q, vector<char>(2));
    for (auto &arr : queries)
    {
        cin >> arr[0] >> arr[1];
    }

    unordered_map<string, set<int>> sts;
    for (int i = 0; i < queries.size(); ++i)
    {
        auto query = queries[i];
        char x = query[0], y = query[1];
        string temp;
        temp += x;
        temp += y;
        sts[temp].insert(i);
    }
    string ans = s;
    for (char &c : ans)
    {
        if (c == 'a')
        {
            // 挺好
            continue;
        }
        else
        {
            if (c == 'b')
            {
                if(sts["ba"].size()){
                    int idx=*sts["ba"].begin();
                    sts["ba"].erase(idx);
                    c='a';
                    continue;
                }
                if(sts["bc"].size()&&sts["ca"].size()){
                    int idx_bc=*sts["bc"].begin();
                    //cout<<idx_bc<<endl;
                    if(sts["ca"].lower_bound(idx_bc)==sts["ca"].end())
                        continue;
                    int idx_ca=*sts["ca"].lower_bound(idx_bc);
                    sts["bc"].erase(idx_bc);
                    sts["ca"].erase(idx_ca);
                    c='a';
                    continue;
                }
            }
            else
            { 
                if(sts["ca"].size()){//any
                    int idx=*sts["ca"].begin();
                    sts["ca"].erase(idx);
                    c='a';
                    continue;
                }
                if(sts["cb"].size()&&sts["ba"].size()){
                    int idx_cb=*sts["cb"].begin();
                    if(sts["ba"].lower_bound(idx_cb)==sts["ba"].end()){
                        if(sts["cb"].size()){
                    int idx=*sts["cb"].rbegin();
                    sts["cb"].erase(idx);
                    c='b';
                    continue;
                }
                        continue;
                    }
                    int idx_ba=*sts["ba"].lower_bound(idx_cb);
                    sts["cb"].erase(idx_cb);
                    sts["ba"].erase(idx_ba);
                    c='a';
                    continue;
                }
                if(sts["cb"].size()){
                    int idx=*sts["cb"].rbegin();
                    sts["cb"].erase(idx);
                    c='b';
                    continue;
                }
            }
        }
    }
    cout << ans << endl;
    /*vector<set<int>> sts(200);

     for(int i=0;i<s.size();++i){
         sts[s[i]].insert(i);
     }
     string ans=s;
     for(auto query:queries){
         int x=query[0],y=query[1];
         if(sts[x].empty())
             continue;
         if(x<y){
             int from_idx=*sts[x].rbegin();
             sts[x].erase(from_idx);
             sts[y].insert(from_idx);
             ans[from_idx]=y;
         }
         else{
             int from_idx=*sts[x].begin();
             sts[x].erase(from_idx);
             sts[y].insert(from_idx);
             ans[from_idx]=y;
         }
     }
     cout<<ans<<endl;*/
}