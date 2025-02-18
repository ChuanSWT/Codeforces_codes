#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
#include<tuple>
#include<cmath>
#include<queue>
#include<iomanip>
using namespace std;
void compete_solution();
template <typename T>
void print(const std::vector<T>& vec) {
    for (auto element : vec) {
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
map<int, int> mp;
vector<int> minv(1001,0x3f3f3f3f);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int roundc = 1;
    //cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
void compete_solution()
{
    int n;
    cin >> n;
    int ans=0;
    ans+=n/2+n%2;
    int a=n;
    int b=n-n%2;
    //cout<<a<<' '<<b<<endl;
    if(b<a)
    {
        --b;
        a-=2;
        ++ans;
    }
    if(a>0)
        ans+=a/3*2+((a%3));
    cout<<ans<<endl;


}