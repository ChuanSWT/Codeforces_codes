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
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;
        int cnt=0;
        int cur=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>=k)
            {
                cur+=nums[i];
            }
            else
            {
                if(nums[i]==0&&cur)
                {
                    --cur;
                    ++cnt;
                }
            }
        }
        cout<<cnt<<endl;
        
        

        
    }