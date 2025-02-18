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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    bool back_is_positive(vector<int> &nums)
    {
        return nums.size()%2==0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;
        //奇数->取最大,偶数->取最小

        //剩余，判断是否必须马上选当前的
        map<int,int> mp;
        for(int x:nums)
        mp[x]++;

        int sz=mp.size();
        set<int> st;//标记已经选择
        vector<int> ans(sz,0x3f3f3f3f);
        set<int> cur;
        int ans_index=0;
        for(int i=0;i<nums.size();++i)
        {
            if(ans_index==ans.size())
            break;
            --mp[nums[i]];
            if(st.find(nums[i])==st.end())
            cur.insert(nums[i]);
            if(mp[nums[i]]==0)
            {
                int target;
                if(ans_index%2==0)
                target=*cur.rbegin();
                else
                target=*cur.begin();
                cur.clear();
                st.insert(target);
                ans[ans_index]=target;
                ++ans_index;
            }

        }
        cout<<ans.size()<<endl;
        print(ans);
        

        
    }