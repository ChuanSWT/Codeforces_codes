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
string i2s(int n){
    string ans;
    while(n){
        ans+=n%10+'0';
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
void compete_solution()
{
    vector<int> nums;
    int time=25;
    for(int i=2;i<2+time;++i){
        nums.push_back(i);
    }
    vector<int> responses;
    for(int x:nums){
        cout<<"?"<<" "<<"1"<<" "<<i2s(x)<<endl;
        int rst1;
        cin>>rst1;
        cout<<"?"<<" "<<i2s(x)<<" "<<"1"<<endl;
        int rst2;
        cin>>rst2;
        responses.push_back(rst1);
        responses.push_back(rst2);
    }
    for(int i=0;i<responses.size();i+=2){
        int target=i/2+2;
        if(responses[i]==-1){
            cout<<"! "<<target-1<<endl;
            return;
        }
        if(responses[i]!=responses[i+1]){
            cout<<"! "<<responses[i]+responses[i+1]<<endl;
            return;
        }
    }
    //map<int,int> mp;

    cout<<"! "<<responses[0]*2<<endl;
}