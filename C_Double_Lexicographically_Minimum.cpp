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
    void cal(string &s)
    {
        for(int i=0;i<s.size();++i)
        {
            if(s[i]<s[s.size()-i-1])
            {
                reverse(s.begin(),s.end());
                return;
            }
            if(s[i]>s[s.size()-i-1])
            return;
        }
    }
    bool is_smaller(string &a,string &b)
    {
        cal(a);
        cal(b);
        //cout<<"cal"<<a<<" "<<b<<endl;
        for(int i=0;i<a.size();++i)
        {
            if(a[i]<b[i])
            return true;
            if(a[i]>b[i])
            return false;
        }
        return true;
    }
    void compete_solution()
    {
        string s;
        cin>>s;
        vector<int> cache(26,0);
        for(char c:s)
        ++cache[c-'a'];
        int index=-1;//第一个奇数
        for(int i=0;i<cache.size();++i)
            if(cache[i]%2)
            {
                index=i;
                break;
            }
            bool attempt=false;
        string left;
        vector<string> ans;
        for(int i=0;i<cache.size();++i)
        {
            if(cache[i]==0)
            continue;
            for(int j=0;j<cache[i]/2;++j)
            {
                left+=i+'a';
            }
            if(cache[i]%2&&!attempt)
            {
                string ori=left;
                string temp=left;
                for(int j=i+1;j<cache.size();++j)
                {
                    for(int k=0;k<cache[j];++k)
                    temp+=j+'a';
                }
                temp+=i+'a';
                reverse(ori.begin(),ori.end());
                //cout<<temp<<" "<<ori<<endl;
                temp+=ori;
                ans.push_back(temp);
                attempt=true;

            }
        }
        string l=left,r=left;
        if(index!=-1)
        {
            l+=index+'a';
            for(int i=index+1;i<cache.size();++i)
            if(cache[i]%2)
            r+=i+'a';
            reverse(r.begin(),r.end());
            l+=r;
            ans.push_back(l);
        }
        else
        {
            string r=left;
            reverse(r.begin(),r.end());
            ans.push_back(l+r);
        }
        int point=0;
        for(int i=0;i<ans.size();++i)
        if(!is_smaller(ans[point],ans[i]))
        point=i;
        //for(auto s1:ans)
        //cout<<s1<<endl;
        cout<<ans[point]<<endl;
        
    }