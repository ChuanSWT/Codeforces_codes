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
int d[5000][5000];  // 创建一个 5000x5000 的二维数组
using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        // 访问和初始化数组元素
        for (int i = 0; i < 5000; ++i) {
            for (int j = 0; j < 5000; ++j) {
                d[i][j] = 3;  // 初始化为 0
            }
        }
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




void compete_solution()
{
    
    int n;
    cin >> n;
    vector<string> strs(n);
    for(auto &s:strs)
        cin>>s;

    vector<vector<int>> edges(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(strs[i][j]=='1'){
                edges[i].push_back(j);
            }
        }
    }
    vector<int> ans;
    
    for(int i=0;i<edges.size();++i){
        if(ans.size()>=3)
            break;
        queue<int> pq;
        pq.emplace(i);
        while(pq.size()){
            int p=pq.front();
            pq.pop();
            int cur_d=p/(1<<24);
            int cur=p%(1<<24);
            if(cur_d>=3)
                break;
            if(cur_d>=d[i][cur])
                continue;
            d[i][cur]=cur_d;
            for(int &x:edges[cur]){
                if(cur_d+1>=d[i][x]||d[i][x]<=2)
                    continue;
                pq.emplace(x+((cur_d+1)<<24));
            }
        }
        bool found=true;
        for(int j=0;j<n;++j){
            if(d[i][j]==3){
                found=false;
                break;
            }
        }
        if(found)
            ans.push_back(i);
    }
    if(ans.size()<3){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        for(int i=0;i<3;++i){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
}