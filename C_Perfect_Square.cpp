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
        vector<string> grid(n);
        for(auto &s:grid)
        cin>>s;
        int ans=0;
        for(int x=0;x<grid.size()/2;++x)
        {
            for(int y=0;y<grid[0].size()/2;++y)
            {
                vector<int> nums;
                int x2=y;
                int y2=n-1-x;
                int x3=n-1-x;
                int y3=n-1-y;
                int x4=n-1-y;
                int y4=x;
                nums.push_back(grid[x][y]);
                nums.push_back(grid[x2][y2]);
                nums.push_back(grid[x3][y3]);
                nums.push_back(grid[x4][y4]);
                //print(nums);
                int mx=1;
                for(auto &num:nums)
                mx=max(mx,num);
                for(auto num:nums)
                ans+=mx-num;

            }
        }
cout<<ans<<endl;
        
    }