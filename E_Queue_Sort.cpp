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
        int n;
        cin>>n;
        vector<long long> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        int minv=0x3f3f3f3f;
        int index=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<minv)
            {
                index=i;
                minv=nums[i];
            }
        }
        for(int i=index+1;i<nums.size();++i)
        {
            if(nums[i-1]>nums[i])
            {
                cout<<-1<<endl;
                return;
            }
        }
        cout<<index<<endl;
        
    }