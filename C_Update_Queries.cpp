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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> ind(m,0);
        for(int i=0;i<m;++i)
        cin>>ind[i];
        string c;
        cin>>c;
        vector<int> mark(n,0);
        for(int num:ind)
        ++mark[num-1];

        vector<char> chars;
        for(char c1:c)
        chars.push_back(c1);
        sort(chars.begin(),chars.end());
        int left=0;
int index=0;
while(index<s.size())
{
    if(mark[index])
    {
    s[index]=chars[left];
    ++index;
    ++left;
    }
    else
    {
    ++index;
    }
}
        cout<<s<<endl;
    }