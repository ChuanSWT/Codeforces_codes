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
    bool check(vector<int> nums)
    {
        for(int i=1;i<nums.size();++i)
        if(nums[i]!=nums[i-1])
        return false;
        return true;
    }
    void compete_solution()
    {
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> nums={a,b,c};
        sort(nums.begin(),nums.end());
        int k=0;
        while(k<=3)
        {
            //print(nums);
            if(check(nums))
            {
                cout<<"YES"<<endl;
                return;

            }
            int val=nums.back();
            nums.pop_back();
            nums.push_back(val-nums[0]);
            nums.push_back(nums[0]);
            sort(nums.begin(),nums.end());
            ++k;
        }
        cout<<"NO"<<endl;
        
        

        
    }