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
    using namespace std;
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
    void compete_solution()
    {
        int n,k;
        cin>>n>>k;
        vector<int> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        sort(nums.begin(),nums.end());
        map<int,vector<int>> mp;
        for(int num:nums)
        mp[num%k].push_back(num);
        if(n%2==0)//偶数情况，不能删除
        {
            long long sum=0;
            for(auto p:mp)
            {
                if(p.second.size()%2==1)
                {
                    cout<<-1<<endl;
                    return;
                }
                for(int i=0;i<p.second.size();i+=2)
                sum+=(p.second[i+1]-p.second[i])/k;
            }
            cout<<sum<<endl;
            return;
        }
        else
        {
            int count=0;
            long long sum=0;
            for(auto p:mp)
            {
                vector<int> &arr=p.second;
                //cout<<"!!!"<<arr.size()<<endl;
                if(arr.size()%2==1)
                {
                    if(count>1)
                    {
                    cout<<-1<<endl;
                    return;
                    }
                    ++count;
                    //针对情况
                    if(arr.size()==1)
                    continue;
                    sort(arr.begin(),arr.end());
                    vector<int> dt1=arr;
                    vector<int> dt2=arr;
                    int max1=0,max2=0;
                    for(int i=0;i+1<arr.size();i+=2)
                    {
                        dt1[i]=dt1[i+1]-dt1[i];
                        if(i-2>=0)
                        dt1[i]+=dt1[i-2];
                        //cout<<dt1[i]<<endl;
                        max1=max(max1,dt1[i]);
                    }
                    //cout<<endl;
                    for(int i=1;i+1<arr.size();i+=2)
                    {
                        dt2[i]=dt2[i+1]-dt2[i];
                        
                        if(i-2>=0)
                        dt2[i]+=dt2[i-2];
                        //cout<<dt2[i]<<endl;
                        max2=max(max2,dt2[i]);
                    }
                    long long minv=LLONG_MAX;
                    //int index=0;
                    dt1.pop_back();
                    dt1.pop_back();
                    dt2.pop_back();

                    for(int i=0;i<arr.size();++i)
                    {
                        long long temp=0;
                        if(i%2==0)
                        {
                            temp+=max2;
                            if(i-2>=0)
                            temp+=dt1[i-2];
                            if(i-1>=0)
                            temp-=dt2[i-1];
                        }
                        else
                        {
                            temp+=max2;
                            temp-=dt2[i];
                            if(i-3>=0)
                            temp+=dt1[i-3];
                            temp+=arr[i+1]-arr[i-1];
                            
                        }
                        //cout<<i<<" "<<temp<<endl;
                        if(temp<minv)
                        {
                            //cout<<
                            minv=temp;
                        }
                    }
                    
                    sum+=minv/k;
                    //cout<<sum<<endl;
                }
                else
                {

                    for(int i=0;i<arr.size();i+=2)
                    sum+=(arr[i+1]-arr[i])/k;
                    
                }
            
                //cout<<sum<<endl;
            }
            cout<<sum<<endl;
            return;
        }

return;
        
    }
    /*vector<int> dt(arr.size(),0);
                    dt[0]=arr[1]-arr[0];
                    dt.back()=arr[arr.size()-1]-arr[arr.size()-2];
                    for(int i=1;i<arr.size()-1;++i)
                    {
                        dt[i]=min(arr[i+1]-arr[i],arr[i]-arr[i-1]);
                    }
                    int index=0;
                    long long maxv=0;
                    for(int i=0;i<dt.size();++i)
                    {
                        if(dt[i]>maxv)
                        {
                            maxv=dt[i];
                            index=i;
                        }
                    }
                    vector<int> newArr;
                    
                    for(int i=0;i<arr.size();++i)
                    if(i!=index)
                    newArr.push_back(arr[i]);
                    p.second=newArr;
                    for(int num:dt)
                    cout<<num<<" ";
                    cout<<endl;
                }
                long long temp=0;
                for(int i=0;i<arr.size();i+=2)
                {
                sum+=(arr[i+1]-arr[i])/(long long)k;
                //cout<<arr[i+1]<<" "<<arr[i]<<" "<<sum<<endl;
                }*/