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
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid;
        vector<int> nums(n*m,0);
        for(int &x:nums) 
        cin>>x;
        map<int,int> mp;
        for(int x:nums)
        ++mp[x];
        for(auto p:mp)
        if(p.second*2>n*m)
        {
            cout<<-1<<endl;
            return;
        }       
        int num=nums.back();
        for(int i=nums.size()-1;i>=1;--i)
        nums[i]=nums[i-1];
        nums[0]=num;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            cout<<nums[i*m+j]<<" ";
            cout<<endl; 
        }
        
        
    }