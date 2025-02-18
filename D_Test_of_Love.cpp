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
    void compete_solution()
    {
        int n,k,m;
        cin>>n>>k>>m;
        //k jump
        //m swim
        string s;
        cin>>s;
        s+='L';
        vector<string> strs;
        int left=-1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='L')
            {
            string temp;
                for(int j=left+1;j<i;++j)
                temp+=s[j];
            left=i;
            strs.push_back(temp);

            }
        }
        int life=m;
        for(string &str:strs)
        {
            //cout<<str<<endl;
            int index=k-1;

            while(index<str.size())
            {
                //cout<<index<<endl;
                if(str[index]=='C')
                {
                    cout<<"NO"<<endl;
                    return;
                }
                if(life==0)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                ++index;                


                --life;


            }
        }
        cout<<"YES"<<endl;
    }