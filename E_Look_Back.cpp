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
    int cal(int a,int b)
    {
        int count=0;
        if(a==b)
        {
            return 0;
        }
        if(a>b)
        {
        while(a>b)

        {
            ++count;
            b*=2;
        }
        return count;
        }
        else
        {
           // b/=2;
             while(b>a)

        {
            --count;
            a*=2;
        }
        if(b==a)
        return count;
        return count+1;
        }
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int& x:nums)
        cin>>x;
        vector<int> arr(n,0);
        for(int i=1;i<nums.size();++i)
        {
            arr[i]=cal(nums[i-1],nums[i]);
        }
        //print(arr);
        int cur=0;
        long long ans=0;
        for(int i=0;i<arr.size();++i)
        {
            cur+=arr[i];
            if(cur<0)
            cur=0;
            ans+=cur;
        }
        cout<<ans<<endl;

        
    }