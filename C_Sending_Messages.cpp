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
    void compete_solution()
    {
        long long n,f,a,b;
        //a:单位时间耗电量
        //f 剩余电量
        //b 关了又开的消耗
        cin>>n>>f>>a>>b;
        vector<long long> nums(n,0);
        for(auto& x:nums)
        cin>>x;
        sort(nums.begin(),nums.end());
        long long ans=0;
        long long time=0;
        for(int i=0;i<nums.size();++i)
        {
            long long d=nums[i]-time;
            if(d*a<b)
            {
                ans+=d*a;
            }
            else
            {
                ans+=b;
            }
            time=nums[i];
        }
        //cout<<ans<<endl;
        if(ans<f)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        

        
    }