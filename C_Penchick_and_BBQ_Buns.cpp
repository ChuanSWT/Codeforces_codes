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
        
        vector<int> nums(n,-1);
        //even
        if(n%2==0)
        {
        for(int i=0;i<nums.size();i+=2)
        {
            nums[i]=i+1;
            nums[i+1]=i+1;
        }
        print(nums);
        return;
        }
        //>=26时ok
        if(n<27)
        {
            cout<<-1<<endl;
            return;
        }
        nums[0]=1;
        nums[9]=1;
        nums[25]=1;
        nums[26]=2;
        nums[22]=2;
        nums[23]=3;
        nums[24]=3;
        int cur=1e6-100;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==-1)
            {
                nums[i]=cur;
                nums[i+1]=cur;
                --cur;
            }
        }
        print(nums);
        
        

        
    }