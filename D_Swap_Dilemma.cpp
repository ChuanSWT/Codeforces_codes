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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> a(n,0),b(n,0);
        for(int &num:a)
        cin>>num;
        for(int &num:b)
        cin>>num;
        set<int> st;
        for(int num:a)
        st.insert(num);
        for(int num:b)
        st.erase(num);
        if(!st.empty())
        {
            cout<<"NO"<<endl;
            return;
        }
        map<int,int> mp;
        for(int i=0;i<a.size();++i)
        {
        if(a[i]!=b[i])
        mp[a[i]]=b[i];
        //cout<<a[i]<<" "<<b[i]<<endl;
        }
int uns=0;
        while(!mp.empty())
        {
            vector<int> temp={mp.begin()->first};
            int count=1;
            while(mp[temp.back()]!=temp[0])
            {
                temp.push_back(mp[temp.back()]);
                ++count;
            }
            if(count%2==0)
            {
                uns++;
                //return;
            }
            for(auto num:temp)
            mp.erase(num);
        }
        if(uns%2)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;

 
        
    }