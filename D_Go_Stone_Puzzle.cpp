#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
using namespace std;

void compete_solution();

int main()
{
    int roundc = 1;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}

class meth
{
public:
    string s;
    string t;
    map<string, int> mp;
    int minv = INT_MAX;

    void move(string &s, int f, int t)
    {
        for (int i = 0; i < 2; ++i)
        {
            s[t + i] = s[f + i];
            s[f + i] = 'X';
        }
    }

    meth(string s1, string t1)
    {
        s = s1 + "XX";
        t = t1 + "XX";
    }

    void bfs()
    {
        queue<pair<string, int>> q;
        q.push({s, 0});
        mp[s] = 0;

        while (!q.empty())
        {
            auto [current, depth] = q.front();
            q.pop();

            if (current == t)
            {
                minv = depth;
                return;
            }

            for (int i = 0; i < current.size() - 1; ++i)
            {
                if (current[i] != 'X' && current[i + 1] != 'X')
                {
                    for (int j = 0; j < current.size() - 1; ++j)
                    {
                        if (current[j] == 'X' && current[j + 1] == 'X' && j != i && j != i + 1)
                        {
                            string next = current;
                            move(next, i, j);
                            if (mp.find(next) == mp.end() || depth + 1 < mp[next])
                            {
                                mp[next] = depth + 1;
                                q.push({next, depth + 1});
                            }
                        }
                    }
                }
            }
        }
    }
};

void compete_solution()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    meth test(s, t);
    test.bfs();
    cout << (test.minv == INT_MAX ? -1 : test.minv) << endl;
}
