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
set<int> st;
signed main()
{
    for(int i=1;i<=500000;++i){
        int sum=(1ll+i)*i/2ll;
        int rst=sqrt(sum);
        if((rst*rst==sum)||((rst+1)*(rst+1)==sum)||((rst-1)*(rst-1)==sum)){
            st.insert(i);
        }
    }
    /*for(int x:st)
        cout<<x<<" ";
        cout<<endl;*/
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


/*bool check(vector<int> ans){
    int sum=0;
    for(int x:ans){
        sum+=x;
        int rst=sqrt(sum);
        if((rst*rst==sum)||((rst+1)*(rst+1)==sum)||((rst-1)*(rst-1)==sum)){
            cout<<rst<<endl;
            return false;
        }
    }
    return true;
}*/

void compete_solution()
{
    int n;
    cin >> n;
    if(st.find(n)!=st.end()){
        cout<<-1<<endl;
        return;
    }
    //1 2 3 4 5 6 7 8 9
    //2 1 3 4 5 6 7 9 8
    //2 3 6 10 15 21 28 37....
    vector<int> ans;
    for(int i=1;i<=n;++i){
        ans.push_back(i);
        if(st.find(i-1)!=st.end()){
            int sz=ans.size();
            swap(ans[sz-1],ans[sz-2]);
        }
    }
    /*if(!check(ans)){
        cout<<"no!"<<endl;
        //return;
    }*/
    print(ans);
}