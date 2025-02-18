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
    //构造长度为n的正整数数组
    //要求异或和正好等于sum/n
    if(n%2==1){
        for(int i=0;i<n;++i){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    //1 1 1
    //1 1 1 1 1
    //奇数可以

    /*for(int i=1;i<10;++i)
        for(int j=i;j<10;++j)
            for(int k=j;k<10;++k)
                for(int a=k;a<10;++a)
                    if((i^j^k^a)*4==i+j+k+a)
                    cout<<i<<" "<<j<<" "<<k<<" "<<a<<endl;*/
    
    //1 2 2 3 3 4
    //5 ,15/6
    //2 4 4 6 6 8
    //10 5
    //1 3 
    //3 7 7 7 7 7 7 7

    /*for(int i=1;i<10;++i)
        for(int j=i;j<10;++j)
            for(int k=j;k<10;++k)
                for(int a=k;a<10;++a)
                    for(int b=a;b<10;++b)
                        for(int c=b;c<10;++c)
                        for(int d=c;d<10;++d)
                        for(int e=d;e<10;++e)
                    if((i^j^k^a^b^c^d^e)*8==i+j+k+a+b+c+d+e)
                    cout<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;*/
    //1 2 2 3
    //1 1 1 2 2 3 3 3
    //1 1 1 1 1 2 2 3 3 3 3 3

    if(n%4==2){
        for(int i=0;i<n;++i){
            if(i%2==0)
            cout<<1<<' ';
            else
            cout<<3<<' ';
        }
        cout<<endl;
        return;
    }
    if(n%4==0){
        for(int i=0;i<(n-2)/2;++i)
        cout<<1<<' ';
        cout<<2<<' ';
        cout<<2<<' ';
        for(int i=0;i<(n-2)/2;++i)
        cout<<3<<' ';
        cout<<endl;
    }
    
}