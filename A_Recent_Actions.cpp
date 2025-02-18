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
        int n,m;
        cin>>n>>m;
        vector<int> nums(m,0);
        for(auto &num:nums)
        cin>>num;
        vector<int> ans(n,-1);
        int index=ans.size()-1;
        set<int> st;
        for(int i=0;i<nums.size();++i)
        {
            int num=nums[i];
            if(index>=0&&st.find(num)==st.end())
            {
                ans[index]=i+1;
                --index;
            }
            st.insert(num);
        }
        for(auto a:ans)
        cout<<a<<" ";cout<<endl;

 
        
    }