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
        long long n,m,k;
        cin>>n>>m>>k;
        int w;
        cin>>w;
        vector<long long> nums(w);
        for(auto&x:nums)
        cin>>x;
        sort(nums.rbegin(),nums.rend());
        vector<vector<long long>> grid(n,vector<long long> (m,0));
        for(int x=0;x<grid.size();++x)
        {
            for(int y=0;y<grid[0].size();++y)
            {
                int maxx=k;
                if(x+1<k)
                maxx-=k-(x+1);
                if(x+k>grid.size())
                maxx-=x+k-grid.size();
                int maxy=k;
                if(y+1<k)
                maxy-=k-(y+1);
                if(y+k>grid[0].size())
                maxy-=y+k-grid[0].size();
                grid[x][y]=maxx*maxy;
            }
        }
        vector<long long>q;
        for(auto arr:grid)
        {
            for(auto num:arr)
            q.push_back(num);
        }
        sort(q.rbegin(),q.rend());
        //print(q);
        long long ans=0;
        for(int i=0;i<nums.size();++i)
        ans+=q[i]*nums[i];
        cout<<ans<<endl;
        
        

        
    }