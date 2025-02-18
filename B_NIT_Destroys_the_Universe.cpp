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
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }   
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
        for(int i=0;i<n;++i)
        cin>>nums[i];
        nums.push_back(0);
        int count=0;
        for(int i=1;i<nums.size();++i)
        if(nums[i]==0&&nums[i-1])
        ++count;
        if(count==0)
        cout<<0<<endl;
        else
        if(count>1)
        cout<<2<<endl;
        else
        cout<<1<<endl;
        
    }