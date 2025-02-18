    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    using namespace std;
    #define MOD 1000000007
    void compete_solution();
    int main()
    {
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    vector<int> cin_vector(int length)
    {
        vector<int> a(length,0);
        for(int i=0;i<length;++i)
        cin>>a[i];
        return a;
    }
    void compete_solution()
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> nums(n);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        sort(nums.begin(),nums.end());
        int index=1;
        long long money=k;
        while(index<nums.size())
        {
            if(money<index*(nums[index]-nums[index-1]))
            break;
            money-=index*(nums[index]-nums[index-1]);
            nums[index-1]=nums[index];
            ++index;
        }
        for(int i=0;i<index-1;++i)
        nums[i]=nums[index-1];

        for(int i=0;i<index;++i)
        nums[i]+=money/index;
        money%=index;
        for(int i=0;i<index;++i)
        {
            if(money<=0)
            break;
            --money;
            ++nums[i];
        }
        for(int i=index;i<n;++i)
        {
            nums[i]=nums[index];
        }
        long long sum=0;
        for(long long num:nums)
        {
            //cout<<num<<" ";
        sum+=num;
        }
        //cout<<endl;
        
        //cout<<minv<<endl;
        cout<<sum-(n-1)<<endl;
    }