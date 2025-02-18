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
    void action(deque<int> &nums)
    {
        int val=nums.back();
        nums.pop_back();
        nums.push_front(val);
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        deque<int> nums(n,0);
        for(int &x:nums)
        cin>>x;
        deque<int> arr=nums;
        for(int num:nums)
        arr.push_back(num);
        int cas=0;
        int cur=0;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]<=arr[i-1])
            ++cur;
            else
            cur=0;
            if(cur>=n-1)
            {
                cas+=2;
                break;
            }
        }        
        cur=0;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]>=arr[i-1])
            ++cur;
            else
            cur=0;
            if(cur>=n-1)
            {
                cas+=1;
                break;
            }
        }

        if(cas==0)
        {
            cout<<-1<<endl;
            return;
        }
        deque<int> temp1=nums;
        sort(temp1.begin(),temp1.end());
        if(temp1[0]==temp1.back())
        {
            cout<<0<<endl;
            return;
        }
        int minv=INT_MAX;
        if(cas&2)//降序
        {
            deque<int> arr1=nums;
            deque<int> arr2=nums;
            int v1=1,v2=1;
            while(arr1.back()>=arr1.front())
            {
                action(arr1);
                ++v1;
            }
            reverse(arr2.begin(),arr2.end());
            while(arr2.back()<=arr2.front())
            {
                action(arr2);
                ++v2;
            }
            minv=min(minv,v1);
            minv=min(minv,v2);
            //cout<<"1111 "<<v1<<" "<<v2<<endl;
        }

        if(cas&1)//升序
        {
            deque<int> arr1=nums;
            deque<int> arr2=nums;
            int v1=0,v2=2;
            while(arr1.back()<=arr1.front())
            {
                action(arr1);
                ++v1;
            }
            reverse(arr2.begin(),arr2.end());
            while(arr2.back()>=arr2.front())
            {
                action(arr2);
                ++v2;
            }
            minv=min(minv,v1);
            minv=min(minv,v2);
            //cout<<"2222 "<<v1<<" "<<v2<<endl;
        }
        cout<<minv<<endl;
        

        
    }