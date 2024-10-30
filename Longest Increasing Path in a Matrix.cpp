using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        int longestPath = 0;

       
        function<int(int, int)> dfs = [&](int row, int col) {
            if (memo[row][col] != -1) return memo[row][col];

            int maxLength = 1;  // Minimum path length starting from this cell
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            for (auto& [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    matrix[newRow][newCol] > matrix[row][col]) {
                    maxLength = max(maxLength, 1 + dfs(newRow, newCol));
                }
            }

            return memo[row][col] = maxLength;
        };

        // Iterate over all cells to find the longest path
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                longestPath = max(longestPath, dfs(r, c));
            }
        }

        return longestPath;
    }
};
