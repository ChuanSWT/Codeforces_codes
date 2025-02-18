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
    long long cal_damage(long long time,vector<long long> &damage,vector<long long>&cd)
    {
        if(time==0)
        return 0;
        long long sum=0;
        --time;
        for(long long d:damage)
        sum+=d;
        for(int i=0;i<cd.size();++i)
        {
            sum+=damage[i]*(time/cd[i]);
        }
        //cout<<time+1<<" "<<sum<<endl;
        return sum;
    }
    void compete_solution()
    {
        long long h,n;
        cin>>h>>n;
        vector<long long> damage,cd;
        for(int i=0;i<n;++i)
        {
            long long d;
            cin>>d;
            damage.push_back(d);
        }
        for(int i=0;i<n;++i)
        {
            long long d;
            cin>>d;
            cd.push_back(d);
        }
        long long left=0;
        long long right=4e10;
        while(left<right)
        {
            long long mid=left+(right-left)/(long long)2;
            if(cal_damage(mid,damage,cd)<h)
            left=mid+1;
            else
            right=mid;
        }
        cout<<left<<endl;
    }