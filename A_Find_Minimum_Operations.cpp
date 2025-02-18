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
            int roundc=1;
            cin >> roundc;
            for (int ic = 0; ic < roundc; ++ic)
            {
                compete_solution();
            }
            return 0;
        }
        long long fid(long long n,long long k)
        {
            long long cur=k;
            while(cur*k<=n)
            {
                cur*=k;
            }
            return cur;
        }
        void compete_solution()
        {
            long long n,k;
            cin>>n>>k;
            if(k==1)
            {
                cout<<n<<endl;
                return;
            }
            int cnt=0;
            while(n)
            {
                if(n<k)
                {
                cnt+=n;
                break;
                }
                n-=fid(n,k);
                ++cnt;
            }
            cout<<cnt<<endl;
            
            

            
        }