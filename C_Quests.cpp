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
    template <typename T>
    void print(const std::vector<T>& vec) {
    for (auto element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    }
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }   
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
    void compete_solution()
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int &x:a)
        cin>>x;
        for(int &x:b)
        cin>>x;
        /*for(int i=1;i<a.size();++i)
        {
            a[i]+=a[i-1];
        }*/
        int ans=0;
        int maxjob=0;
        int sum=0;
        for(int i=0;i<k&&i<a.size();++i)
        {
            sum+=a[i];
            maxjob=max(maxjob,b[i]);
            int left=k-i-1;
            ans=max(ans,sum+maxjob*left);
            //cout<<ans<<"test"<<endl;
        }
        cout<<ans<<endl;
        

        
    }