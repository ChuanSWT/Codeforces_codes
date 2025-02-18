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
    long long cal1(vector<long long> nums,long long max1)
    {
        for(int i=0;i<nums.size();++i)
        if(nums[i]==max1)
        {
        nums.erase(nums.begin()+i);
        break;
        }
        sort(nums.begin(),nums.end());
        if(nums.empty())
        return 0;
        return nums[nums.size()/2-(nums.size()%2==0)];
    }
__int128 cal_step(vector<long long> &a,vector<long long>& b,long long mid)
{
    vector<long long> nums;//可操作数的集合
    int request=(a.size()+1)/2;//需要的
    int niubi=0;//天花板
    for(int i=0;i<a.size();++i)
    {
        if(b[i]==1)
        {
            if(a[i]<mid)
        nums.push_back(a[i]);
            else
            ++niubi;
        }
        else
        {
        if(a[i]<mid)
        --request;
        else
        ++niubi;
        }
    }
    if(request<=0)//累赘太多,垫脚石太高
    return LLONG_MAX;
    __int128 ans=0;
    //从大到小优先
    sort(nums.rbegin(),nums.rend());
    int need=(a.size()-a.size()/2)+(a.size()%2==0);
    need-=niubi;
    for(int i=0;i<need;++i)
    {
        ans+=mid-nums[i];
    }
    if(ans<0)
    return 0;
    return ans;

}
    void compete_solution()
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> a(n),b(n);
        for(auto&x:a)
        cin>>x;
        for(auto&x:b)
        cin>>x;
        //要么找0的最大值，维护中值
        //要么找1的最大值，维护基值
        long long max1=0;
        long long max0=0;
        int cnt1=0;
        for(int i=0;i<a.size();++i)
        {
            if(b[i]==1)
            {
            max1=max(max1,a[i]);
            ++cnt1;
            }
            else
            max0=max(max0,a[i]);
        }
        long long ans1=max1;
        if(cnt1)
        ans1+=k;
        ans1+=cal1(a,max1);
        long long ans2=max0;
        for(int i=0;i<a.size();++i)
        {
            if(a[i]==max0)
            {
                a.erase(a.begin()+i);
                b.erase(b.begin()+i);
                break;
            }
        }

        /*cout<<max1<<" "<<max0<<endl;
        long long ss=cal_step(a,b,12);
        cout<<ss<<endl;*/
        long long left=0,right=LLONG_MAX-10000;
        while(left<right)
        {
            long long mid=(left+right)/2;
            __int128 rst=cal_step(a,b,mid);
            if(rst<=k)
            left=mid+1;
            else
            right=mid;
        }
        int rst=left-1;
        ans2+=rst;
        //cout<<ans1<<" "<<ans2<<endl;
        cout<<max(ans1,ans2)<<endl;

        

        
    }