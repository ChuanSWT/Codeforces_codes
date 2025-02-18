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
        int maxv=0;
        for(int x:nums)
        maxv=max(maxv,x);
        vector<int> ans(n,-1);
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<ans.size();++i)
        {
            ans[i]=nums[i]-maxv;
            //cout<<ans[i]<<endl;
            if(ans[i]==0)
            ans[i]=nums[i]-arr[arr.size()-2];
        }
                
        print(ans);
        

        
    }