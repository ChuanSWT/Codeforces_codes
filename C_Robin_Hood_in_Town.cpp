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
        vector<long long>nums(n);
        for(auto&x:nums)
        cin>>x;
        if(n==1)
        {
            cout<<-1<<endl;
            return;
        }
        if(n==2)
        {
            cout<<-1<<endl;
            return;
        }
        sort(nums.begin(),nums.end());
        long long vip=nums[nums.size()/2];
        long long sum=0;
        for(auto x:nums)
        {
        sum+=x;
        }
        long long x=2ll*n*vip-sum;
        ++x;
        if(x<0)
        x=0;
        cout<<x<<endl;
        

        
    }