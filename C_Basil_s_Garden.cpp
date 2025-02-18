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
        vector<int> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        int maxv=0;
        for(int i=0;i<nums.size();++i)
        maxv=max(maxv,i+nums[i]);
        cout<<maxv<<endl;
        
        
    }