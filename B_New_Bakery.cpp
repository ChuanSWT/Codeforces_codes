    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    using namespace std;
    #define MOD 1000000007
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
    vector<int> cin_vector(int length)
    {
        vector<int> a(length,0);
        for(int i=0;i<length;++i)
        cin>>a[i];
        return a;
    }
    void compete_solution()
    {
        long long n,a,b;//count ori change
        cin>>n>>a>>b;
        if(b<a)
        {
            cout<<n*a<<endl;
        return ;
        }
        long long k=b-a+1;//change num
        long long left=n-k;
        if(left<=0)
        {
            cout<<(b+b-n+1)*n/2<<endl;
            return;
        }
        long long sum=0;
        sum+=left*a;
        sum+=(b+a)*k/2;
        cout<<sum<<endl;
        return;

    }