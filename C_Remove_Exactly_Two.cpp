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
bool is_prime(int n){
    for(int i=1;i*i<=n;++i){
        if(n%i==0)
        return false;
    }
    return true;
}

void compete_solution()
{
    int n;
    cin>>n;
    vector<vector<int>> raw_edges=cin_edges(n-1,2);
    //要么是一条边
    //要么是两个点
    for(auto &arr:raw_edges){
        --arr[0];
        --arr[1];
    }
    map<int,set<int>> mp;
    vector<int> nums(n,0);
    for(auto edge:raw_edges){
        mp[edge[0]].insert(edge[1]);
        mp[edge[1]].insert(edge[0]);
        ++nums[edge[0]];
        ++nums[edge[1]];
    }
    // 6+6 -1
    // 6+6 -1 -1
    //能做出最大贡献的顶点 若只存在1个 则必须考虑和次 大
    //若有两个 则直接开始决断
    set<vector<int>> st;
    for(auto &edge:raw_edges){
        st.insert({edge[0],edge[1]});
        st.insert({edge[1],edge[0]});
    }
    int maxv=0;
    for(auto &p:mp){
        maxv=max(maxv,(int)p.second.size());
    }
    int cnt=0;
    for(auto &p:mp){
        if(p.second.size()==maxv)
        ++cnt;
    }
    if(cnt==1){
        int target;
        for(auto &p:mp){
            if(p.second.size()==maxv){
                target=p.first;
            }
        }
        mp.erase(target);
        int maxv2=0;
        for(auto &p:mp){
            maxv2=max(maxv2,(int)p.second.size());
        }
        vector<int> nodes;
        for(auto &p:mp){
            if(p.second.size()==maxv2)
                nodes.push_back(p.first);
        }
        for(int x:nodes){
            if(st.find({target,x})==st.end()){
                cout<<maxv+maxv2-1<<endl;
                return;
            }
        }
        cout<<maxv+maxv2-2<<endl;
        return;
    }
    else{
        vector<int> nodes;
        for(auto &p:mp){
            if(p.second.size()==maxv){
                nodes.push_back(p.first);
            }
        }
        for(int i=0;i<nodes.size();++i){
            for(int j=i+1;j<nodes.size();++j){
                if(st.find({nodes[i],nodes[j]})==st.end()){
                    cout<<maxv*2-1<<endl;
                    return;
                }
            }
        }
        cout<<maxv*2-2<<endl;
    }
    //会赢的

}