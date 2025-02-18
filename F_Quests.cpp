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
    long long cal(vector<long long> &nums,int k,int days)
    {
        long long times=days/(k+1);
        long long left=days%(k+1);
        long long sum=0;
        sum+=nums[k]*times;
        if(left!=0)
        sum+=nums[left-1];
        return sum;
    }
    void compete_solution()
    {
        long long n,c,d;
        cin>>n>>c>>d;
        vector<long long> nums(max(d,n)+10,0);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        long long s1=0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<min(d,(long long)nums.size());++i)
        s1+=nums[i];
        if(s1>=c)
        {
            cout<<"Infinity"<<endl;
            return ;
        }
        s1=0;
        for(int i=0;i<d;++i)
        s1+=nums[0];
        if(s1<c)
        {
            cout<<"Impossible"<<endl;
            return ;
        }
        for(int i=1;i<nums.size();++i)
        nums[i]+=nums[i-1];
        //最优决策
        //k=0，一直执行第一个
        //k=1，12121212
        //k=2，123123123
        long long left=0,right=d;
        while(left<right)
        {
            long long  mid=(left+right)/2;
            if(cal(nums,mid,d)>=c)
            left=mid+1;
            else
            right=mid;
        }
        cout<<right-1<<endl;

        

        
    }