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
class segmentTree {
private:
    vector<int> seg_tree;
    vector<int> arr;
public:
    segmentTree(int n) {
        arr.resize(n + 1);
        seg_tree.resize(4 * (n + 1));
        build(1, 1, n);
    }
    segmentTree(vector<int> nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        arr = nums;
        seg_tree.resize(4 * (n + 1));
        build(1, 1, n);
    }
    void push_up(int root) {
        seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //最小值改min
    }
    //建树
    //[L,R]就是对应arr数组里面的数
    void build(int root, int L, int R) {
        if (L == R) {
            seg_tree[root] = arr[L];
            return;
        }
        int mid = (L + R) >> 1;
        build(root << 1, L, mid);
        build(root << 1 | 1, mid + 1, R);
        push_up(root);
    }
    int query0(int root, int L, int R, int LL, int RR) {
        return query(root, L, R, LL + 1, RR + 1);
    }
    int query(int root, int L, int R, int LL, int RR) {
        if (LL <= L && R <= RR) return seg_tree[root];
        int Ans = 0;
        int mid = (L + R) >> 1;
        if (LL <= mid) Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //最小值改min
        if (RR > mid) Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //最小值改min
        return Ans;
    }
};

void compete_solution()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> nums;
    for(char c:s){
        nums.push_back(c-'a');
    }
    segmentTree test(nums);
    int q;
    cin>>q;
    while(q--){
        int left,right;
        cin>>left>>right;
        int rst=test.query(1,1,n,left,right);
        cout<<rst<<endl;
    }




    
}