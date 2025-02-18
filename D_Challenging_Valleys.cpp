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
        vector<int> nums(n+2,INT_MAX);
        for(int i=1;i<nums.size()-1;++i)
        cin>>nums[i];
        bool left=false;
        bool right=false;
        int count=0;
        for(int i=1;i<nums.size()-1;++i)
        {
            if(nums[i]>nums[i-1])
            left=false;
            if(nums[i]<nums[i-1])
            left=true;
            if(nums[i]<nums[i+1])
            right=true;
            if(nums[i]>nums[i+1])
            right=false;
            if(left&&right)
            {
                left=false;
                right=false;    
                ++count;
            }
        }
        if(count==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }