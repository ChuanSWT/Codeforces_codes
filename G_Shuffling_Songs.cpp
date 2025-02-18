#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void compete_solution();

template <typename T>
void print(const vector<T>& vec) {
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic) {
        compete_solution();
    }
    return 0;
}

class Meth {
public:
    vector<vector<int>> edges;
    vector<int> mask;
    int n;
    int maxv = 0;

    Meth(const vector<unordered_set<int>>& other) : n(other.size()), mask(other.size(), 0), edges(other.size()) {
        for (int i = 0; i < n; ++i) {
            edges[i].assign(other[i].begin(), other[i].end());
        }
    }

    int cal() {

        for (int i = 0; i < n; ++i) {
            fill(mask.begin(), mask.end(), 0);
            mask[i] = 1;
            dfs_helper(1, i);
        }
        return maxv;
    }

    void dfs_helper(int i, int cur) {
        maxv = max(maxv, i);
            //cout<<"hi"<<endl;
        for (const int& x : edges[cur]) {
            if (mask[x] == 0) {
                mask[x] = 1;
                dfs_helper(i + 1, x);
                mask[x] = 0;
            }
        }
    }
};

unordered_map<string, int> make(const vector<vector<string>>& strs) {
    unordered_set<string> st;
    for (const auto& arr : strs) {
        for (const auto& s : arr) {
            st.insert(s);
        }
    }

    unordered_map<string, int> mp;
    int idx = 0;
    for (const auto& s : st) {
        mp[s] = idx++;
    }
    return mp;
}

void compete_solution() {
    int n;
    cin >> n;
    vector<vector<string>> old_songs(n, vector<string>(2, ""));
    for (auto& arr : old_songs) {
        cin >> arr[0] >> arr[1];
    }

    auto mp = make(old_songs);
    vector<vector<int>> songs(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        songs[i][0] = mp[old_songs[i][0]];
        songs[i][1] = mp[old_songs[i][1]];
    }

    unordered_map<int, vector<int>> style;
    unordered_map<int, vector<int>> name;
    vector<unordered_set<int>> edges(n);
    
    for (int i = 0; i < n; ++i) {
        int cur_s = songs[i][0];
        int cur_n = songs[i][1];
        
        for (int x : style[cur_s]) {
            edges[i].insert(x);
            edges[x].insert(i);
        }
        for (int x : name[cur_n]) {
            edges[i].insert(x);
            edges[x].insert(i);
        }
        style[cur_s].push_back(i);
        name[cur_n].push_back(i);
    }

    Meth test(edges);
    int rst = test.cal();
    cout << n - rst << endl;
}
