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
    vector<int> cal(vector<int> me,vector<int> target,int k)
    {
        me[0]-=k;
        me[1]+=k;
        target[0]=max(target[0],me[0]);
        target[1]=min(target[1],me[1]);
        if(target[0]>target[1])
        return {};
        return target;
    }
    bool check(vector<vector<int>> &nums,int k)
    {
        vector<int> wide={0,0};
        for(int i=0;i<nums.size();++i)
        {
            wide=cal(wide,nums[i],k);
            if(wide.empty())
            return false;
        }
        return true;

    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> nums;
        for(int i=0;i<n;++i)
        {
            int t1,t2;
            cin>>t1>>t2;
            nums.push_back({t1,t2});
        }
        int left=0,right=0x3f3f3f3f;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(!check(nums,mid))
            left=mid+1;
            else
            right=mid;
        }
        cout<<left<<endl;
        

        
    }