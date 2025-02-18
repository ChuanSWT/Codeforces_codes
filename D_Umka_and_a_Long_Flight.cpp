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
        long long n,x,y;
        cin>>n>>x>>y;
        vector<long long> nums={1,1};
        for(int i=0;i<50;++i)
        nums.push_back(nums.back()+nums[nums.size()-2]);
        // 1 1 2 3 5 8
        for(int i=n+1;i>=2;--i)
        {
            y=min(y,nums[i]-y+1);
            //cout<<y<<endl;
            if(y>nums[i]-nums[i-1])
            {
                cout<<"NO"<<endl;
                return;
            }
            swap(x,y);

        }
        cout<<"YES"<<endl;

        
    }