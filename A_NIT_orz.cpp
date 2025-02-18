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
    void print(vector<int>)
    {

    }
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
        long long n,z;
        cin>>n>>z;
        vector<long long> nums(n,0);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        long long maxv=0;
        for(int i=0;i<nums.size();++i)
        maxv=max(maxv,nums[i]|z);
        cout<<maxv<<endl;

        
    }