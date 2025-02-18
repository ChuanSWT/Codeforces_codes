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
    void make(vector<int>& nums)
    {
        int maxv=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();++i)//进行关键的第一次/第二次迭代
        {
            ++mp[nums[i]];
            if(mp[nums[i]]>=2)
            maxv=max(maxv,nums[i]);
            nums[i]=maxv;
        }
       // print(nums);

    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int &x:nums)
        cin>>x;

        long long sum=0;
        for(int x:nums)
        sum+=x;
        make(nums);
        for(int x:nums)
        sum+=x;
        make(nums);
        for(int x:nums)
        sum+=x;
        long long s=0;
        for(int x:nums)
        s+=x;
        for(int i=nums.size()-1;i>=0;--i)
        {
            s-=nums[i];
            sum+=s;
        }
        cout<<sum<<endl;
    }