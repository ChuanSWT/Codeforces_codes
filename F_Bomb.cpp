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
    #include<iomanip>
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
        vector<int> a(n);
        vector<int> b(n);
        for(auto&x:a)
        cin>>x;
        for(auto&x:b)
        cin>>x;
        priority_queue<vector<int>> pq;
        for(int i=0;i<a.size();++i)
        {
            int cnt=a[i]/b[i];
            int left=a[i]-cnt*b[i];
            pq.push({b[i],cnt});
            pq.push({left,1});
        }
        long long ans=0;
        while(pq.size()&&k!=0)
        {
            vector<int> arr=pq.top();
            pq.pop();
            if(k<=arr[1])
            {
                ans+=k*arr[0];
                break;
            }
            else
            {
                ans+=arr[0]*arr[1];
                k-=arr[1];
            }
        }
        cout<<ans<<endl;

        
    }