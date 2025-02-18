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
        long long n,k;
        cin>>n>>k;
        long long ori_k=k;
        if(k%2)
        {
            cout<<"No"<<endl;
            return;
        }
        vector<int> nums(n,0);

        for(int i=0;i<nums.size();++i)
        nums[i]=i;
                vector<int> ori=nums;
        vector<int> re_nums=nums;
        reverse(re_nums.begin(),re_nums.end());
        long long maxv=0;
        for(int i=0;i<nums.size();++i)
        maxv+=abs(nums[i]-re_nums[i]);
        if(k>maxv)
        {
            cout<<"No"<<endl;
            return;
        }
        int left=0,right=nums.size()-1;
        while(k&&left<right)
        {
            //cout<<left<<" "<<right<<" "<<k<<endl;
            if(2*(right-left)<=k)
            {
                k-=2*(right-left);
                swap(nums[left],nums[right]);
                ++left;
                --right;
            }
            else
            {
                ++left;
            }
        }
        bool safe=true;
        long long sum=0;
        for(int i=0;i<nums.size();++i)
        {
        sum+=abs(ori[i]-nums[i]);
        //cout<<nums[i]<<" ";
        }
        //cout<<endl;
        if(sum==ori_k)
        {
        cout<<"Yes"<<endl;
        for(int n:nums)
        cout<<n+1<<" ";
        cout<<endl;
        }
        else
        {
        cout<<"No"<<endl;
        return;
        }
    }