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
    class trie
{
private:
	struct node
	{
		bool isEnd;
		vector<node*> child;
		node():child(26,nullptr),isEnd(false)
		{
		}
	};
	node* root;
public:
	trie()
	{
		root = new node();
	}
	bool insert(string s)
	{
		node* cur = root;
		for (char c : s)
		{
			if (cur->child[c - 'a'] == nullptr)
				cur->child[c - 'a'] = new node();
			cur = cur->child[c - 'a'];
		}
		if (cur->isEnd)
			return false;
		cur->isEnd = true;
		return true;
	}
    bool insert(string &s,int left,int right)
    {
        node* cur = root;
		for (int i=left;i<right;++i)
		{
            char& c=s[i];
			if (cur->child[c - 'a'] == nullptr)
				cur->child[c - 'a'] = new node();
			cur = cur->child[c - 'a'];
		}
		if (cur->isEnd)
			return false;
		cur->isEnd = true;
		return true;
    }
	bool find(string s)
	{
		node* cur = root;
		for (char c : s)
		{
			if (cur->child[c - 'a'] == nullptr)
				return false;
			cur = cur->child[c - 'a'];
		}
		if (cur->isEnd)
			return true;
		else
			return false;
	}
};
    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc=1;
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        trie *test=new trie();
        string s;
        cin>>s;
        int maxv=0;
        for(int left=0;left<s.size();++left)
        {
            for(int right=left+1;right<=s.size();++right)
            {
                if(test->insert(s,left,right)==false)
                maxv=max(maxv,right-left);
            }   
        }
        cout<<maxv<<endl;
        
        

        
    }
