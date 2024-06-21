class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<int>>& image, int initial_colour, int new_colour) {

        int n = image.size();
        int m = image[0].size();

        visited[row][col] = 1;
        queue<pair<int, int>> q;

        q.push({row, col});
        image[row][col] = new_colour;

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto dir : directions) {

                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == initial_colour &&
                    !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    image[nrow][ncol] = new_colour;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int colour) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int initial_colour = image[sr][sc];

        bfs(sr, sc, visited, image, initial_colour, colour);

        return image;
    }
};