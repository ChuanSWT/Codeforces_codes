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
    void compete_solution(long long n);
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
        long long n;
        while(scanf("%lld",&n)!=EOF)
        compete_solution(n);
        return 0;
    }
    void compete_solution(long long n)
    {
        vector<long long> nums={1,1};
        while(nums.back()<1e16)
        {
            nums.push_back(nums[nums.size()-2]+nums.back());
        }
        int left=0,right=0;
        long long sum=0;
        bool ok=false;
        while(right<nums.size())
        {
            sum+=nums[right];
            ++right;
            while(sum>n)
            {
                sum-=nums[left];
                ++left;
            }
            if(sum==n)
            ok=true;
        }
        if(ok)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
        

        
    }