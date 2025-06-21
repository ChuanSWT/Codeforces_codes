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
    //cin >> t;
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



vector<vector<int>> make(string &s,int k){
    int n=s.size();
    vector<vector<int>> jump(n,vector<int>(k,0x3f3f3f3f));
    vector<int> mp(k,0x3f3f3f3f);
    for(int i=n-1;i>=0;--i){
        jump[i]=mp;
        mp[s[i]-'a']=i;
    }
    return jump;
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<string> queries(q);
    for(auto &s:queries){
        cin>>s;
    }
    //010101
    //111
    //找到最远满足的最后一个字母
    //前面建立跳转表
    vector<int> arr_s;
    for(char c:s){
        arr_s.push_back(c-'a');
    }
    
    vector<vector<int>> jump=make(s,k);
    map<int,int> mp;
    for(int i=0;i<n;++i){
        if(mp.count(arr_s[i]))
            continue;
        mp[arr_s[i]]=i;
    }
    //cout<<"oj"<<endl;
    //return;
    vector<int> maxv;
    for(auto &arr:jump){
        maxv.push_back(*max_element(arr.begin(),arr.end()));
    }
    vector<int> mem(n,-1);
    for(auto query:queries){
        vector<int> arr;
        for(char &c:query){
            arr.push_back(c-'a');
        }
        //print(arr);
        bool bad=false;
        if(!mp.count(arr[0])){
            cout<<0<<'\n';
            continue;
        }
        int index=mp[arr[0]];
        for(int i=1;i<arr.size();++i){
            index=jump[index][arr[i]];
            if(index==0x3f3f3f3f){
                bad=true;
                break;
            }
        }
        if(bad){
            cout<<0<<'\n';
            continue;
        }
        int cnt=0;
        vector<int> path;
        bool memed=false;
        int ans=-1;
        while(index!=0x3f3f3f3f){
            if(mem[index]!=-1){
                cout<<cnt+mem[index]<<endl;
                ans=cnt+mem[index];
                memed=true;
                break;
            }
            path.push_back(index);
            index=maxv[index];
            ++cnt;
        }
        if(!memed){
            cout<<cnt<<'\n';
            ans=cnt;
        }
        for(int i=0;i<path.size();++i){
            mem[path[i]]=ans-i;
        }
    }
    
}