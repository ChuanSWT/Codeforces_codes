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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int check(vector<int> odd,vector<int> even)
    {
        long long ans=0;
        for(int x:odd)
        ans+=x;
        for(int x:even)
        ans+=x;
        int max1=0;
        for(auto x:odd)
        max1=max(max1,x);
        int max2=0;
        for(auto x:even)
        max2=max(max2,x);
        //cout<<max1<<endl;
        //cout<<max2<<endl;
        ans-=max1;
        ans-=max2;
        return ans;


    }
    void vminus(vector<int> &a,vector<int>&b)
    {
        for(int i=0;i<a.size();++i)
        a[i]-=b[i];
    }
    void vplus(vector<int> &a,vector<int>&b)
    {
        for(int i=0;i<a.size();++i)
        a[i]+=b[i];
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1)
        {
            cout<<1<<endl;
            return;
        }
        vector<vector<int>> pre_sum(s.size(),vector<int>(26,0));
        ++pre_sum[0][s[0]-'a'];
        ++pre_sum[1][s[1]-'a'];
        for(int i=2;i<s.size();++i)
        {
            for(int j=0;j<26;++j)
            pre_sum[i][j]+=pre_sum[i-2][j];
            ++pre_sum[i][s[i]-'a'];
        }

        if(s.size()%2==0)
        {
            /*for(auto x:pre_sum[pre_sum.size()-2])
            cout<<x<<" ";
            cout<<endl;*/
            cout<<check(pre_sum.back(),pre_sum[pre_sum.size()-2])<<endl;
            return;
        }
        //奇数情况
        //下标从0开始
        int minv=0x3f3f3f3f;
        for(int i=0;i<s.size();++i)
        {
            vector<int> zero_back=pre_sum.back();
            vector<int> one_back=pre_sum[pre_sum.size()-2];
            vector<int> zero(26,0);
            vector<int> one(26,0);
                

            if(i>0)
            {
                if(i&1)
                zero=pre_sum[i-1];
                else
                zero=pre_sum[i-2];
            }
            if(i>1)
            {
                if(i&1)
                one=pre_sum[i-2];
                else
                one=pre_sum[i-1];
            }
                //print(zero);
                //print(one);
            vminus(zero_back,zero);
            vplus(zero_back,one);
            vminus(one_back,one);
            vplus(one_back,zero);
            if(i%2==0)
            --zero_back[s[i]-'a'];
            else
            --one_back[s[i]-'a'];
            //print(zero_back);
            //    print(one_back);
            //cout<<check(zero_back,one_back)<<" ";

            minv=min(minv,check(zero_back,one_back));

        }
        //cout<<endl;
        cout<<minv+1<<endl;
        //cout<<1000<<endl;
    }