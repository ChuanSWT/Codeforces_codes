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
    using namespace std;
    void compete_solution();
    int main()
    {
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> nums(n,0);
        for(int i=0;i<n;++i)
        nums[i]=s[i]-'0';
        if(nums.size()==2)
        {
            cout<<nums[0]*10+nums[1]<<endl;
            return;
        }
        if(nums.size()==3)
        {
            int t1=nums[0]+nums[1]*10+nums[2];
            int t2=nums[0]*10+nums[1]+nums[2];
            int t3=nums[0]*(nums[1]*10+nums[2]);
            int t4=(nums[0]*10+nums[1])*nums[2];
            cout<<min(min(t1,t2),min(t3,t4))<<endl;
            return;
        }
        for(int n1:nums)
        if(n1==0)
        {
            cout<<0<<endl;
            return;
        }
        int sum=0;
        int minv=0x3f3f3f3f;
        int index=-1;
        int nxt=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]<minv)
            {
                index=i;
                minv=nums[i];
                nxt=nums[i+1];
            }
            else
            {
                if(nums[i]==minv&&nums[i+1]>=nxt)
                {
                   index=i;
                minv=nums[i]; 
                nxt=nums[i+1];
                }
            }
        }
        sum+=nums[index]*10+nums[index+1];
        nums[index]=0;
        nums[index+1]=0;
        for(int n1:nums)
        if(n1>1)
        sum+=n1;
        cout<<sum<<endl;
        
    }