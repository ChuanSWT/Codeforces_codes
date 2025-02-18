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
#define matrix vector<vector<int>>
#define line vector<int>
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
bool flag;
int cal_start(int n,int m,matrix persons){
    for(int i=0;i<persons.size();++i){
        if(n==0||m==0){
            if(n==0)
                flag=true;
            else
                flag=false;
            return i;
        }
        if(persons[i][0]>persons[i][1])
            --n;
        else
            --m;
    }
    return -1;
}
int cal_tot(int n,int m,matrix persons){
    int sum=0;
    bool f=false;
    for(int i=0;i<persons.size();++i){
        vector<int> arr=persons[i];
        if(n==0||m==0)
            f=true;
        if(f){
            if(flag)
                sum+=arr[1];
            else
                sum+=arr[0];
        }
        else{
            if(arr[0]>arr[1]){
                sum+=arr[0];
                --n;
            }
            else{
                sum+=arr[1];
                --m;
            }
        }
    }
    return sum;
}
int cal_n(int n,int m,matrix persons){
    ++n;
    int sum=0;
    for(auto arr:persons){
        if(n==0){
            sum+=arr[1];
            --m;
        }
        else if(m==0){
            sum+=arr[0];
            --n;
        }
        else{
            if(arr[0]>arr[1]){
                sum+=arr[0];
                --n;
            }
            else{
                sum+=arr[1];
                --m;
            }
        }
    }
    return sum;
}
int cal_m(int n,int m,matrix persons){
    ++m;
    int sum=0;
    for(auto arr:persons){
        if(n==0){
            sum+=arr[1];
            --m;
        }
        else if(m==0){
            sum+=arr[0];
            --n;
        }
        else{
            if(arr[0]>arr[1]){
                sum+=arr[0];
                --n;
            }
            else{
                sum+=arr[1];
                --m;
            }
        }
    }
    return sum;
}
void compete_solution()
{
    int a,b;
    cin>>a>>b;
    int base=gcd(a,b);
    a/=base;
    b/=base;
    if(a==1){
        cout<<b*b*base<<endl;
        return;
    }
    if(b==1){
        cout<<a*a*base<<endl;
        return;
    }
    cout<<a*b*base<<endl;
}