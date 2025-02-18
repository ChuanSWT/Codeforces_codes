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
    #include<numeric>
    #define ll long long
    #define mod 1000000007
    using namespace std;
    
ll qpow(int a,int b,int m)//pow(a,b)%m
{
	ll result = 1;
	ll base = a;
	while(b>0)
	{
		if(b&1==1)
		result=(result*base)%m;
		base=(base*base)%m;
		b>>=1;
	}
	return result;
}
//计算组合数取模
ll comp(ll a,ll b,int p)// num C(a,b)%p
{
	if(a<b)return 0;
	if(a==b)return 1;
	if(b>a-b)b=a-b;
	ll ans=1,ca=1,cb=1;
	for(ll i=0;i<b;i++)
	{
		ca=(ca*(a-i))%p;
		cb=(cb*(b-i))%p;
	}
	ans=(ca*qpow(cb,p-2,mod))%p;
	return ans;
}
ll lucas(ll n,ll m,ll p)
{
	ll ans=1;
	while(n&&m&&ans)
	{
		ans=(ans*comp(n%p,m%p,p))%p;
		n/=p;
		m/=p;
	}
	return ans;

}
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
    //对于当前大小完全为空的矩阵n 还有多少次普通操作可能性 使其变为n-2大小的矩阵
    vector<long long> nums;
    int main()
    {
        for(long long i=0;i<=3e5+100;++i)
        nums.push_back((i*i-i)%mod);
        nums[0]=1;
        for(int i=1;i<nums.size();i+=2)
        nums[i]=0;
        for(int i=2;i<nums.size();i+=2)
        {
        nums[i]*=nums[i-2];
        nums[i]%=mod;
        }
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
    void compete_solution()
    {
        long long n,k;
        cin>>n>>k;
        vector<vector<int>> points(k,vector<int>(2));
        for(auto&arr:points)
        cin>>arr[0]>>arr[1];
        long long normal=0;
        long long sp=0;
        for(auto p:points)
        if(p[0]==p[1])
            ++sp;
        else
            ++normal;
        long long newN=n-normal*2-sp;

        long long ans=0;
        for(int i=newN;i>=0;--i)
        {
            ans+=nums[newN-i]*comp(newN,i,mod);
            ans%=mod;
        }
        for(int i=)
        cout<<ans<<endl;
        
        
        

        
        

        
    }