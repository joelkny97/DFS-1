// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix
// Space Complexity: O(m * n) for the queue used in BFS
// Were you able to solve the problem? Yes
// Did you face any challenges while solving the problem? No
class Solution {
public:
    vector<pair<int, int>> dirs;
    int m;
    int n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        if (mat.size() == 0 ){
            return mat;
        }

        dirs = {{-1,0}, {1,0}, {0,-1}, {0,1} }; // U D L R

        m = mat.size();
        n = mat[0].size();

        std::queue<pair<int,int>> q;

        // initialize the queue with all the cells that have value 0
        // and mark all cells with value 1 as -1 to indicate they are unvisited
        // This will help us to only process cells that are initially 0 and to track the distance from the nearest 0
        // This is a BFS approach to find the shortest distance from each cell to the nearest 0
        for (int i=0; i<m; i++){
            for (int j=0; j<n ; j++){
                if (mat[i][j] == 0){
                    q.push({i,j});
                }
                else{
                    mat[i][j] *= -1;
                }
            }
        }

        // BFS to update the distance of each cell to the nearest 0
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            
            // explore all four directions from the current cell
            
            
            for (const auto& d: dirs){
                int nr = curr.first +d.first;
                int nc = curr.second +d.second;
                // if the adjacent cell is within bounds and has not been visited (i.e., has value -1),
                // we update its distance and push it to the queue
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && mat[nr][nc] == -1){
                    
                    q.push({nr, nc});

                    // The distance is updated by adding 1 to the distance of the current cell
                    // This ensures that we are always finding the shortest distance to the nearest 0
                    // This is because we are processing cells in the order of their distance from the nearest 0
                    // and we are only updating cells that have not been visited yet
                    mat[nr][nc] = mat[curr.first][curr.second] + 1;

                }
                
            }
        }

        return mat;
    }

};