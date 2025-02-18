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
    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc=1;
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
class NumArray {
private:
    vector<int> nums;
    vector<int> treeAdd;  // 用于存储区间更新的增量
    vector<int> treeSum;  // 用于存储数组的前缀和
    int n;

    // 更新树状数组
    void updateTree(vector<int>& tree, int i, int delta) {
        for (; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    // 获取前缀和
    int queryTree(const vector<int>& tree, int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : nums(nums.size()), treeAdd(nums.size() + 1), treeSum(nums.size() + 1), n(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    // 单点更新
    void update(int index, int val) {
        int delta = val;
        nums[index] = val;
        updateTree(treeSum, index + 1, delta);
    }

    // 查询范围和 [left, right]
    int sumRange(int left, int right) {
        return queryTree(treeSum, right + 1) - queryTree(treeSum, left);
    }

    // 更新范围 [left, right]，每个元素增加 val
    void rangeUpdate(int left, int right, int val) {
        if(left>=right)
        return;
        updateTree(treeAdd, left + 1, val);      // 在 left 位置增加 val
        updateTree(treeAdd, right + 2, -val);    // 在 right+1 位置减少 val
    }

    // 查询 index 位置的值，包含区间更新后的值
    int getValue(int index) {
        return nums[index] + queryTree(treeAdd, index + 1);
    }
bool copy(NumArray *other)
    {
        this->nums=other->nums;
        this->treeAdd=other->treeAdd;
        this->treeSum=other->treeSum;
        this->n=other->n;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> nums(n);
        for(auto&x:nums)
        cin>>x;
        vector<int> emp(5001,0);
        NumArray *dp=new NumArray(emp);
        int sum=0;
        for(int x:nums)
        {
            if(x==0)
            {
                ++sum;
                NumArray *ndp=new NumArray(emp);
                ndp->copy(dp);
                for(int i=1;i<5001;++i)
                {
                    int cur=ndp->sumRange(i,i);
                    int pre=dp->sumRange(i-1,i-1);
                    if(pre>cur)
                    ndp->update(i,pre);
                }
                dp->copy(ndp);
                for(int i=0;i<10;++i)
            {
                int val=dp->getValue(i);
                cout<<val<<" ";
            }
            cout<<endl;
                continue;
            }
            bool plus=x>0;
            x=abs(x);
            if(plus)
            {
                int left=0;
                int right=min(5000,sum);
                dp->rangeUpdate(left,right,1);
            }
            else
            {
                int left=0;
                int right=5000;
                right=min(right,sum-x);
                dp->rangeUpdate(left,right,1);

            }
            for(int i=0;i<10;++i)
            {
                int val=dp->getValue(i);
                cout<<val<<" ";
            }
            cout<<endl;

        }
        int maxv=0;
        for(int i=0;i<5001;++i)
        {
            maxv=max(maxv,dp->getValue(i));
        }
        //?
        cout<<maxv<<endl;

        
        

        
    }