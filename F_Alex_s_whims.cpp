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
        vector<long long> nums(m,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        for(int i=0;i<n-1;++i)
        cout<<i+1<<" "<<i+2<<endl;
        int cur=n-1;
        for(int i=0;i<nums.size();++i)
        {
            if(cur!=nums[i])
            cout<<n<<" "<<cur<<" "<<nums[i]<<endl;
            else
            cout<<"-1 -1 -1"<<endl;
            cur=nums[i];
        }
 
        
    }