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
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }   
    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }

    void make(vector<int>& nums,int m)
    {
        for(int &n:nums)
        {
            while(n)
            {
            if(n%m)
            break;
            n/=m;
            }
        }
    }
        template <typename T>
        void PRINT(const std::vector<T>& vec) {
    for (auto element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> nums(n,0);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        //PRINT(nums);
        int k;
        cin>>k;
        vector<int> target(k,0);
        for(int i=0;i<k;++i)
        cin>>target[i];
        int sum=0;
        for(int num:nums)
        sum+=num;
        for(int num:target)
        sum-=num;
        if(sum)
        {
            cout<<"No"<<endl;
            return ;
        }
        vector<int> ori_nums=nums;
        vector<int> ori_target=target;
        make(nums,m);
        make(target,m);
        /*for(int num:nums)
        cout<<num<<" ";
        cout<<endl;*/
        int index1=nums.size()-1;
        int index2=target.size()-1;
        while(index1!=-1)
        {
            if(nums[index1]!=target[index2])
            {
                cout<<"No"<<endl;
                return;
            }
            if(ori_nums[index1]>ori_target[index2])
            {
                ori_nums[index1]-=ori_target[index2];
                --index2;
            }
            else
            {
                if(ori_nums[index1]<ori_target[index2])
                {
                ori_target[index2]-=ori_nums[index1];
                --index1;
                }
                else
                {
                    --index1;
                    --index2;
                }

            }
            //return;
        }
        cout<<"Yes"<<endl;
       
        
    }