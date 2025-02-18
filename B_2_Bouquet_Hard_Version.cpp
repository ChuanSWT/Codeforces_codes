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
    long long cal(pair<long long, long long> a,pair<long long, long long> b,long long m)
    {
        //a is smaller;
        long long cnta=0;
        long long sum=0;
        long long timea=min(a.second,m/a.first);
        sum+=a.first*timea;
        cnta+=timea;
        a.second-=timea;
        long long timeb=min(b.second,(m-sum)/b.first);
        sum+=b.first*timeb;
        b.second-=timeb;
        long long one=min(cnta,b.second);
        return min(sum+one,m);

    }
    long long cal_alone(pair<long long, long long> a,long long m)
    {
        long long time=min(a.second,m/a.first);
        return a.first*time;

    }
void compete_solution()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> flowers(n, 0); // 每朵花的花瓣数量
    vector<long long> nums(n, 0); // 每种花的剩余个数

    for (auto &x : flowers)
        cin >> x;
    for (auto &x : nums)
        cin >> x;

    vector<pair<long long, long long>> tarr;
    for (int i = 0; i < n; ++i)
        tarr.push_back({flowers[i], nums[i]});

    sort(tarr.begin(), tarr.end());
    long long maxv=0;
    for(int i=1;i<tarr.size();++i)
    {
        if(tarr[i-1].first+1==tarr[i].first)
        maxv=max(maxv,cal(tarr[i-1],tarr[i],m));
        //cout<<cal(tarr[i-1],tarr[i],m)<<endl;
    }
    for(int i=0;i<tarr.size();++i)
    {
        maxv=max(maxv,cal_alone(tarr[i],m));
        //cout<<cal(tarr[i-1],tarr[i],m)<<endl;
    }
    cout<<maxv<<endl;



}

