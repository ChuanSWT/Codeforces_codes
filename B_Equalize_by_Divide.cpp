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
        vector<int> nums(n,0);
        for(auto &num:nums)
        cin>>num;
        int count=0;
        for(int num:nums)
        count+=(num==1);
        if(count!=0&&count!=n)
        {
            cout<<-1<<endl;
            return;
        }
        vector<vector<int>> ans;
        while(1)
        {
            int index=-1;
            int minv=0x3f3f3f3f;
            bool safe=true;
            for(int i=0;i<nums.size();++i)
            {
                if(i!=0&&nums[i]!=nums[i-1])
                safe=false;
                if(nums[i]<minv)
                {
                    index=i;
                    minv=nums[i];
                }
            }
            if(safe)
            break;
            for(int i=0;i<nums.size();++i)
            if(nums[i]>minv)
            {
            nums[i]=nums[i]/minv+(nums[i]%minv!=0);
            ans.push_back({i+1,index+1});
            break;
            }
        }
        cout<<ans.size()<<endl;
        for(auto arr:ans)
        cout<<arr[0]<<" "<<arr[1]<<endl;
        
    }