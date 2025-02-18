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
    #include <climits>
    using namespace std;
    void compete_solution();
    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
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
        int n,k;
        cin>>n>>k;
        vector<long long> nums(n,0);
        for(auto &num:nums)
        cin>>num;
        sort(nums.begin(),nums.end());
        int length=n-k;
        long long minv=LLONG_MAX;
        for(int i=0;i<nums.size();++i)
        {
            if(i+length-1<nums.size())
            minv=min(minv,nums[i+length-1]-nums[i]);

        }
    cout<<minv<<endl;
        

    }