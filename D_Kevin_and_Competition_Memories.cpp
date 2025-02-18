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
    int n,m;
    cin >> n>>m;
    vector<int> people=cin_nums(n);
    vector<int> problem=cin_nums(m);
    int limit=people[0];
    sort(people.begin(),people.end());
    sort(problem.begin(),problem.end());
    int p_idx=0;
    int pb_idx=0;
    
    while(p_idx<people.size()&&people[p_idx]<=limit)
        ++p_idx;
    while(pb_idx<problem.size()&&problem[pb_idx]<=limit)
        ++pb_idx;
    //这个难度下比他更强的人数
    vector<int> devote(m,0);
    for(int i=pb_idx;i<devote.size();++i)
    {
        int difficuty=problem[i];
        while(p_idx<people.size()&&people[p_idx]<difficuty)
        ++p_idx;
        devote[i]=n-p_idx;
    }
    sort(devote.begin(),devote.end());
    //print(devote);
    for(int i=1;i<=m;++i)
    {
        int sum=0;
        for(int j=0;j<m;j+=i)
        {
            if(j+i-1<m)
            sum+=devote[j+i-1]+1;
        }
        cout<<sum<<" ";

            
    }
    cout<<endl;
    
}