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
        //别忘记longlong
        long long n,m;
        cin>>n>>m;
        vector<long long> target(n,0);
        vector<long long > nums(m,0);
        for(auto& x:target)
        cin>>x;
        for(auto& x:nums)
        cin>>x;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        reverse(nums.begin(),nums.end());
        vector<long long> left(n,0);
//print(target);
//print(nums);
        for(int i=0;i<n;++i)
        left[i]=abs(nums[i]-target[i]);
        for(int i=1;i<left.size();++i)
        left[i]+=left[i-1];
        
        reverse(nums.begin(),nums.end());
        reverse(target.begin(),target.end());
        
        vector<long long> right(n,0);
        for(int i=0;i<n;++i)
        right[i]=abs(nums[i]-target[i]);
        for(int i=1;i<right.size();++i)
        right[i]+=right[i-1];
       // print(left);
        //print(right);
        long long ans=0;
        for(int i=0;i<n-1;++i)
        {
            ans=max(ans,left[i]+right[n-i-2]);
        }
        ans=max(ans,left.back());
        ans=max(ans,right.back());
        cout<<ans<<endl;
        

        
    }