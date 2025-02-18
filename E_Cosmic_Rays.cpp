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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<long long>> nums(n,vector<long long> (2));
        for(auto& arr:nums)
        cin>>arr[0]>>arr[1];
        //最后肯定会由单段最长对应的元素主导
        //算出其它段
        vector<long long> ans(n,0);
        deque<vector<long long>> dq;
        for(int i=0;i<nums.size();++i)
        {

            vector<long long> arr=nums[i];
            if(i==0)
            {
                dq.push_back(arr);
                ans[i]=arr[0];
                continue;
            }
            ans[i]=ans[i-1];
            if(dq.empty())
            {
            dq.push_back(arr);
            ans[i]=max(ans[i],dq.back()[0]);
            continue;
            }
            int time=arr[0];
            int num=arr[1];
            while(!dq.empty()&&time!=0)
            {
                int val=dq.back()[1];
                if(val==num)
                {
                    dq.back()[0]+=time;
                    time=0;
                }
                else
                {
                    if(time>=dq.back()[0])
                    {
                        //time-=dq.back()[0];
                        dq.pop_back();
                    }
                    else
                    {
                        dq.back()[0]-=time;
                        time=0;
                    }
                }
            }
            if(dq.empty()&&time!=0)
            dq.push_back({time,num});
            if(!dq.empty())
            {
                long long x=dq.back()[0];
                //cout<<x<<endl;
            ans[i]=max(ans[i],x);
            }
            else{
                //cout<<"dq is empty!"<<endl;
            }

            ans[i]=max(ans[i],arr[0]);
            
        }
        print(ans);
        

        
    }