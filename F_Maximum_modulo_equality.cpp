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
    #include<numeric>
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
        if(x==-1)
        return y;
        if(y==-1)
        return x;
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }   
    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
class SegmentTree {
private:
    vector<int> tree;
    int n;

    // 建立线段树
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // 叶子节点
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            // 递归建立左子树
            buildTree(arr, 2 * node + 1, start, mid);
            // 递归建立右子树
            buildTree(arr, 2 * node + 2, mid + 1, end);
            // 内部节点的值是左右子树的最大值
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // 查询区间最大值
    int queryTree(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            // 区间不相交
            return -1;
        }
        if (L <= start && end <= R) {
            // 完全包含
            return tree[node];
        }
        int mid = (start + end) / 2;
        // 查询左子树和右子树的最大值
        int leftMax = queryTree(2 * node + 1, start, mid, L, R);
        int rightMax = queryTree(2 * node + 2, mid + 1, end, L, R);
        return gcd(leftMax, rightMax);
    }

public:
    // 构造函数
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    // 查询区间最大值
    int query(int L, int R) {
        return queryTree(0, 0, n - 1, L, R);
    }
};
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> nums(n);
        for(auto&x:nums)
        cin>>x;
        vector<vector<int>> query(m,vector<int>(2));
        for(auto&arr:query)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        --arr[1];
        }
        if(nums.size()==1)
        {
            for(int i=0;i<query.size();++i)
            cout<<0<<" ";
            cout<<endl;
            return;
        }

        //可减去某个数，使对于另一个数呈倍数
        //或者统计与最大值的差
        //两数间差值 集合并gcd
        vector<int> rst;
        for(int i=1;i<nums.size();++i)
        rst.push_back(abs(nums[i]-nums[i-1]));
        //print(rst);
        SegmentTree *test=new SegmentTree(rst);

        for(auto arr:query)
        {
            int left=arr[0];
            int right=arr[1];
            if(left==right)
            {
                cout<<0<<" ";
                continue;
            }
            --right;
            int result=test->query(left,right);
            cout<<result<<" ";
        }
        cout<<endl;
        
    }