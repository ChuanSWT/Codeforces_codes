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
#include <random>
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


int query(int a,int b,int c){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<endl;
    int rst;
    cin>>rst;
    return rst;
}
void ans(int a,int b,int c){
    cout<<"! "<<a<<" "<<b<<" "<<c<<" "<<endl;
}
void compete_solution()
{
    std::random_device rd;
    std::mt19937 g(rd());
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=1;i<=n;++i){
        nums.push_back(i);
    }
    for(int i=0;i<10;++i)
    std::shuffle(nums.begin(), nums.end(), g);
    int a=nums[0],b=nums[1],c=nums[2];
    for(int i=0;i<15;++i){
        
        vector<int> anss(1,-1);
        for(int j=0;j<1;++j){
            anss[j]=query(a,b,c);
        }
        if(anss[0]==0){
            ans(a,b,c);
            return;
        }
        sort(anss.begin(),anss.end());
        b=anss[0];
        /*for(int j=1;j<2;++j){
            if(anss[j]!=b&&anss[j]!=c)
                a=anss[j];
        }*/
    }
    for(int i=0;i<30;++i){
        
        vector<int> anss(2,-1);
        for(int j=0;j<2;++j){
            anss[j]=query(a,b,c);
        }
        if(anss[0]==0){
            ans(a,b,c);
            return;
        }
        sort(anss.begin(),anss.end());
        if(anss[0]==anss.back()){
            b=anss[0];
            continue;
        }
        b=anss[0];
        c=anss.back();
        /*for(int j=1;j<2;++j){
            if(anss[j]!=b&&anss[j]!=c)
                a=anss[j];
        }*/
    }
    ans(a,b,c);
}