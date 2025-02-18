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
        for(int i=0;i<n;++i)
        cin>>nums[i];
        vector<int> vals;
        vector<int> left_sum=nums;
        for(int i=1;i<left_sum.size();++i)
        left_sum[i]=max(left_sum[i],left_sum[i-1]);
        for(int i=1;i<n;++i)
        vals.push_back(left_sum[i]-nums[i]);
        priority_queue<int,vector<int>,greater<>> pq;
        for(int m:vals)
        if(m>0)
        pq.push(m);
        int cur=0;
        long long sum=0;
        while(!pq.empty())
        {
            int sz=pq.size();
            auto p=pq.top();
            pq.pop();
            long long t1=(sz+1);
            t1*=(p-cur);
            sum+=t1;
            cur=p;
        }
        cout<<sum<<endl;
    }