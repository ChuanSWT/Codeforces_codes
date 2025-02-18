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
    vector<int> make(int n)
    {
        vector<int> ans;
        for(int i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                if(i*i==n)
                {
                    ans.push_back(i);
                }
                else
                {
                ans.push_back(i);
                ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    bool check(vector<int> nums,int k)//分组数据
    {
        if(k==nums.size())
        return true;
        vector<int> temp2;
        for(int i=0;i<k;i++)//相位
        {
            vector<int> temp;
            for(int j=k+i;j<nums.size();j+=k)//数组间
            {
                if(nums[j]-nums[j-k]!=0)
                {
                    temp.push_back(abs(nums[j]-nums[j-k]));
                }
                
            }
            //print(temp);
            for(int i=1;i<temp.size();++i)
            temp[i]=gcd(temp[i],temp[i-1]);
            if(temp.size())
            temp2.push_back(temp.back());
        }
        for(int i=1;i<temp2.size();++i)
            temp2[i]=gcd(temp2[i],temp2[i-1]);
            //cout<<"hi"<<endl;
            if(temp2.empty())
            return true;
        if(temp2.back()!=1)
        {
            //cout<<k<<endl;
        return true;
        }
        else
        return false;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int &x:nums)
        cin>>x;

        vector<int> q=make(n);        
        //print(q);
        int sum=0;
        for(int k:q)
        {
            //cout<<k<<endl;
            sum+=check(nums,k);
        }
        cout<<sum<<endl;
        
    }