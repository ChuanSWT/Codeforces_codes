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
    #include<numeric>
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
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])
        return a[0]<b[0];
        
        return a[1]>b[1];
    }
    bool compare2(vector<int>&a,vector<int>&b)
    {
        if(a[1]!=b[1])
        return a[1]>b[1];
        
        return a[0]<b[0];
    }
    bool compare_idx(vector<int>&a,vector<int>&b)
    {
        return a[2]<b[2];
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> query(n,vector<int>(3));
        int index=0;
        for(auto&arr:query)
        {
        cin>>arr[0]>>arr[1];
        arr[2]=index;
        ++index;
        }

        sort(query.begin(),query.end(),compare);
        /*for(auto arr:query)
        {
            for(int x:arr)
            cout<<x<<" ";
            cout<<endl;
        }*/
        set<int> st;
        vector<int> right(n,-1);
        for(int i=0;i<n;++i)
        {
            auto r=st.lower_bound(query[i][1]);
            if(r!=st.end())
                right[query[i][2]]=*r;
            st.insert(query[i][1]);
        }
        sort(query.begin(),query.end(),compare2);
        st.clear();
        /*for(auto arr:query)
        {
            for(int x:arr)
            cout<<x<<" ";
            cout<<endl;
        }*/
        vector<int> left(n,-1);
        for(int i=0;i<query.size();++i)
        {
            auto l=st.lower_bound(-query[i][0]);
            if(l!=st.end())
            {
                //cout<<query[i][2]<<endl;
                left[query[i][2]]=-*l;
            }
            st.insert(-query[i][0]);
        }
        //print(left);
        //print(right);
        vector<int> ans(n,0);
        sort(query.begin(),query.end(),compare_idx);
        for(int i=0;i<ans.size();++i)
        {
            if(left[i]!=-1)
            ans[i]+=query[i][0]-left[i];
            if(right[i]!=-1)
            ans[i]+=right[i]-query[i][1];
        }
        map<vector<int>,int> mp;
        for(auto arr:query)
        {
            ++mp[{arr[0],arr[1]}];
        }
        for(int i=0;i<query.size();++i)
        {
            if(mp[{query[i][0],query[i][1]}]>=2)
            ans[i]=0;
        }
        for(int x:ans)
        cout<<x<<endl;

        
    }