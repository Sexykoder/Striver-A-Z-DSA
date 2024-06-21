class Solution {
public:
    bool isvalid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                } 
            }
        }
        
        if(fresh == 0) return 0;  // No fresh oranges, return 0

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int q_size = q.size();
            bool rotted = false;

            for(int i = 0; i < q_size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x1 = p.first;
                int y1 = p.second;

                for(int j = 0; j < 4; j++) {
                    int x = x1 + directions[j][0];
                    int y = y1 + directions[j][1];

                    if(isvalid(x, y, n, m, grid)) {
                        rotted = true;
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }

            if(rotted) {
                time++;
            }
        }

        return (fresh == 0) ? time : -1;
    }
};
