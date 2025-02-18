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
    int cal(int num,int maxv,int k)
    {
        k*=2;
        int x=(maxv-num)/k;
        num+=x*k;
        return num;
    }
    void compete_solution()
    {
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(auto&x:nums)
        cin>>x;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i)
            nums[i]=cal(nums[i],nums.back(),k);
        map<int,int> f;
        for(int x:nums)
        {
            int newX=x+2*k;
            ++f[x];
            --f[x+k];
            ++f[newX];
            --f[newX+k];
        }
        int sum=0;
        int maxv=0;
        int index=-1;
        for(auto &p:f)
        {
            int val=p.second;
            sum+=val;
            maxv=max(maxv,sum);
            if(maxv==n)
            {
                index=p.first;
                break;
            }
        }
        if(index==-1)
        cout<<-1<<endl;
        else
        cout<<index<<endl;

        
    }