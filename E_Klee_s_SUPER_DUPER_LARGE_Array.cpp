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
    long long cal(long long left,long long right,long long mid)
    {
        long long sz1=mid-left+1;
        long long sz2=right-mid;
        long long plus=sz1*(left+mid)/2;
        long long minus=sz2*(mid+1+right)/2;
        return plus-minus;
    }
    void compete_solution()
    {
        long long n,k;
        cin>>n>>k;
        
        long long left=k;
        long long right=k+n;
        long long minv=LLONG_MAX;
        while(left<right)
        {
            long long mid=(left+right)/2;
            long long rst=cal(k,k+n-1,mid);
            minv=min(minv,abs(rst));
            if(rst==0)
            {
                cout<<0<<endl;
                return;
            }
            else
            {
                if(rst>0)
                right=mid;
                else
                left=mid+1;
            }
        }
        cout<<minv<<endl;
        
        

        
    }