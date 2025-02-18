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
        int n,s,m;
        cin>>n>>s>>m;
        vector<vector<int>> nums(n,vector<int>(2));
        for(auto& arr:nums)
        cin>>arr[0]>>arr[1];
        if(s<=nums[0][0])
        {
            cout<<"YES"<<endl;
            return;
        }
        nums.push_back({m,m});
        for(int i=0;i+1<nums.size();++i)
        if(nums[i+1][0]-nums[i][1]>=s)
        {
            //cout<<i<<endl;
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
            return;
        
        

        
    }