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
    #include<fstream>
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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        
        return 0;
    }
    void compete_solution()
    {
        freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
        int n;
        cin>>n;
        n*=2;
        vector<pair<int,int>> nums(n,make_pair(0,0));
        for(pair<int,int> &p:nums)
        cin>>p.first;
        for(int i=0;i<nums.size();++i)
        nums[i].second=i+1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        if(nums[i].first!=nums[i-1].first)
        {
            cout<<-1<<endl;
            return;
        }
        for(int i=1;i<nums.size();i+=2)
        {
            cout<<nums[i].second<<" "<<nums[i-1].second<<endl;
        }

        

        
    }