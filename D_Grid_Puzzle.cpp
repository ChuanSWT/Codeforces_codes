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
        vector<int> nums(n,0);
        for(int &x:nums)
        cin>>x;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            //print(nums);
            if(nums[i]==0)
            continue;
            if(nums[i]>=4)
            {
                ++sum;
                continue;
            }
            if(nums[i]==1||nums[i]==2)
            {
                ++sum;
                if(i+1<nums.size())
                {
                    if(nums[i+1]<=2)
                    {
                        nums[i+1]=0;
                        continue;
                    }
                    if(nums[i+1]<=4&&i+2<=nums.size()&&nums[i+2]>=3&&nums[i+2]<=4)
                    {
                        ++sum;
                        nums[i+1]=0;
                        nums[i+2]=2;
                    }
                }
            }
            else//3
            {
                ++sum;
            }
           
        }
        cout<<sum<<endl;

        
    }