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
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> nums(n,0);
        for(auto &num:nums)
        cin>>num;
        for(int i=0;i<k;++i)
        cout<<nums[i]<<" ";
        cout<<x<<" ";
        for(int i=k;i<nums.size();++i)
        cout<<nums[i]<<" ";
        cout<<endl;
    


        

    }