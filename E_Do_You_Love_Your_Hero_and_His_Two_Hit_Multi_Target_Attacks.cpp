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



vector<int> make(int n){
    vector<int> nums;
    while(n){
        for(int i=2;;++i){
            int sum=i*(i-1)/2;
            if(sum>n){
                nums.push_back(i-1);
                n-=(i-1)*(i-2)/2;
                break;
            }
        }
    }
    return nums;

}
void compete_solution()
{
    int n;
    cin >> n;
    vector<vector<int>> points(500,vector<int>(2,0));
    for(int i=0;i<points.size();++i){
        points[i][1]=i;
    }
    vector<int> rst=make(n);
    int cur=0;
    for(int i=0;i<points.size();++i){
        if(rst.empty()){
            for(int j=i;j<points.size();++j){
                points[j][0]=cur;
                ++cur;
                
            }
            break;
        }
        points[i][0]=cur;
        rst.back()-=1;
        if(rst.back()==0){
            rst.pop_back();
            ++cur;
        }
        if(rst.empty()){
            for(int j=i+1;j<points.size();++j){
                points[j][0]=cur;
                ++cur;
                
            }
            break;
        }
    }
    cout<<points.size()<<endl;
    for(auto arr:points)
        print(arr);
}