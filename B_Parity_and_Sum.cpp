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
        int n;
        cin>>n;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        //操作后只会变为奇数
        //使用最大的奇
        sort(nums.begin(),nums.end());
        //结尾为奇数情况
        int sum=0;//偶数量
        for(int x:nums)
        if(x%2==0)
        ++sum;
        if(sum==n)
        {
            cout<<0<<endl;
            return;
        }
        if(nums.back()%2==1)
        {
            cout<<sum<<endl;
            return;
        }
        long long max1=0;
        long long max0=0;
        for(int i=0;i<nums.size()-1;++i)
        if(nums[i]%2==0)
        max0=max(max0,nums[i]);
        else
        max1=max(max1,nums[i]);
        bool ok=true;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]%2==0)
            {
                if(max1<nums[i])
                {
                    ok=false;
                    break;
                }
                else
                max1+=nums[i];
            }
        }
        if(!ok)
        sum+=1;
        cout<<sum<<endl;

        
        
    }