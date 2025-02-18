#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;


void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
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
    cin>>n;
    string s;
    cin>>s;
    //i和e是没用的
    //p很有用
    //优先删除p?
    //mappppp
    //mappppie

    string pat1="pie",pat2="map";
    int ans=0;
    string temp;
    for(int i=0;i<s.size();++i){
        temp+=s[i];
        bool bad=false;
        while(temp.size()>=3){
            int sz=temp.size();
            string t;
            t+=temp[sz-3];
            t+=temp[sz-2];
            t+=temp[sz-1];
            if(t==pat1||t==pat2){
                ++ans;
                temp.clear();
            }
            else
            break;
            
        }
        if(bad)
        ++ans;
    }
    cout<<ans<<endl;

    
}