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
        int n;
        cin>>n;
        vector<int> nums=cin_vector(n);
        int a1=nums.back();
        int max1=-1;
        int index=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(max1<nums[i])
            {
                max1=nums[i];
                index=i;
            }
        }
        if(index+1!=nums.size())
        cout<<max1+a1<<endl;
        else
        {
            int mm=max1;
            max1=-1;
            index=-1;
            for(int i=0;i<nums.size()-1;++i)
            {
                if(max1<nums[i])
            {
                max1=nums[i];
                index=i;
            }
            }
            cout<<max1+mm<<endl;
        }
        /*
        for(int i=0;i<nums.size();++i)
        
        for(int i=0;i<nums.size();++i)
        {
            vector<int> t1,t2;
            for(int j=0;j)
        }*/

    }