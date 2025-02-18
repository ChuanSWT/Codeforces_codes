#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void compete_solution() {
    int n;
    cin >> n;
    
    vector<vector<int>> nums(n, vector<int>(2));
    int total_sum = 0;
    
    for (auto& arr : nums) {
        cin >> arr[1] >> arr[0];
        total_sum += arr[0];
        arr[1]--;  // 将队伍编号调整为 0-based
    }
    
    // 如果不能被3整除，直接返回 -1
    if (total_sum % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    
    int limit = total_sum / 3;
    
    // 初始化 DP 数组, dp[i][j][k] 表示队伍1,2,3任务量为 i, j, k 时需要的最小操作次数
    vector<vector<vector<int>>> dp(limit + 1, vector<vector<int>>(limit + 1, vector<int>(limit + 1, INF)));
    
    dp[0][0][0] = 0;  // 初始状态，三队任务量都为 0，操作次数为 0
    
    // 动态规划，填充 DP 数组
    for (const auto& task : nums) {
        int team_type = task[1];  // 队伍编号
        int task_size = task[0];  // 任务大小
        
        // 从后向前遍历，避免更新时影响之前的状态
        for (int i = limit; i >= 0; --i) {
            for (int j = limit; j >= 0; --j) {
                for (int k = limit; k >= 0; --k) {
                    if (dp[i][j][k] == INF) continue;
                    
                    // 将任务分配给队伍1
                    if (i + task_size <= limit && team_type == 0) {
                        dp[i + task_size][j][k] = min(dp[i + task_size][j][k], dp[i][j][k]);
                    }
                    // 将任务分配给队伍2
                    if (j + task_size <= limit && team_type == 1) {
                        dp[i][j + task_size][k] = min(dp[i][j + task_size][k], dp[i][j][k]);
                    }
                    // 将任务分配给队伍3
                    if (k + task_size <= limit && team_type == 2) {
                        dp[i][j][k + task_size] = min(dp[i][j][k + task_size], dp[i][j][k]);
                    }
                    
                    // 若任务分配给非指定队伍，增加一次操作
                    if (i + task_size <= limit && team_type != 0) {
                        dp[i + task_size][j][k] = min(dp[i + task_size][j][k], dp[i][j][k] + 1);
                    }
                    if (j + task_size <= limit && team_type != 1) {
                        dp[i][j + task_size][k] = min(dp[i][j + task_size][k], dp[i][j][k] + 1);
                    }
                    if (k + task_size <= limit && team_type != 2) {
                        dp[i][j][k + task_size] = min(dp[i][j][k + task_size], dp[i][j][k] + 1);
                    }
                }
            }
        }
    }
    
    int result = dp[limit][limit][limit];
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int roundc = 1;
    for (int ic = 0; ic < roundc; ++ic) {
        compete_solution();
    }
    
    return 0;
}
