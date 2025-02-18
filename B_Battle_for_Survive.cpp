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
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        //n>=2
        if(n==2)
        {
            cout<<nums[1]-nums[0]<<endl;
            return;
        }
        long long sum=0;
        for(int i=0;i<n-2;++i)
        sum+=nums[i];
        long long ans=nums.back();
        long long dummy=nums[nums.size()-2];
        cout<<ans-(dummy-sum)<<endl;
        

        

        
    }