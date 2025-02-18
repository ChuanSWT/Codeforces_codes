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
    long long check(long long n,long long a)
    {
        //cout<<n<<" "<<a<<endl;
        long long num=n;
        long long t=n/a;
        num-=t*a;
        return num;
    }
    void compete_solution()
    {

        long long c,a,b;
        cin>>c>>a>>b;

        long long t=gcd(a,b);
        vector<int> nums(c);
        for(int&x:nums)
        cin>>x;
        long long minv=0x3f3f3f3f3f3f;
        deque<long long> dq;
        for(int x:nums)
        {
        dq.push_back(check(x,t));
        }
        sort(dq.begin(),dq.end());
       /* for(int x:dq)
        cout<<x<<endl;*/
        int time=c;
        while((time--)+10)
        {
            long long val=dq.front();
            dq.pop_front();
            val+=t;
            dq.push_back(val);
            minv=min(minv,dq.back()-dq.front());

        }
        cout<<minv<<endl;

        
        

        
    }