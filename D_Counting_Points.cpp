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
    int n,m;
    cin >> n>>m;
    vector<vector<int>> circles(n,vector<int>(2));
    for(auto &arr:circles)
        cin>>arr[0];
    for(auto &arr:circles)
        cin>>arr[1];
    //sort(circles.begin(),circles.end());

    map<int,int> mp;
    for(auto arr:circles){
        int p=arr[0];
        int r=arr[1];
        for(int i=p-r;i<=p+r;++i){
            int left=1,right=0x3f3f3f3f;
            while(left<right){
                int mid=(left+right)/2;
                //在圆内
                if(abs(p-i)*abs(p-i)+mid*mid<=r*r){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            mp[i]=max(mp[i],left-1);
        }
    }
    int sum=0;
    for(auto p:mp){
        sum+=1+p.second*2;
        //cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<sum<<endl;
}