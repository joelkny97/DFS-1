// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the image
// Space Complexity: O(m * n) for the stack space used in DFS
// Were you able to solve the problem? Yes
// Did you face any challenges while solving the problem? No

class Solution {
public:
    vector<pair<int, int>> dirs;
    int m;
    int n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // U D L R

        m = image.size();
        n = image[0].size();

        int oldColor = image[sr][sc];

        // if the color is the same as the old color, we return the image as it is
        if (color == oldColor) return image;
        
        // start the DFS from the given cell
        dfs(image, sr, sc, color, oldColor);

        return image;
        
    }
private:
    void dfs(vector<vector<int>>& image, int row, int col, const int &color, int oldColor){
        // base case if the current cell is out of bounds or if the color is not the same as the old color
        if ( row < 0 || col< 0 || row >=m || col >= n  || image[row][col] != oldColor ){
            return;
        }

        // change color of the current cell to the new color
        image[row][col] = color;
        
        // exlpore all four directions 
        for(const auto& d: dirs){
            
            int nr = row + d.first;
            int nc = col + d.second; 


            // if the new cell is within bounds and has the old color we continue the DFS
            // This ensures we only change the color of connected components and does not start DFS on cells that are already colored
            if (nr >= 0 && nc >= 0 && nr < m && nc < n ){
                if ( image[nr][nc] == oldColor) {

                    dfs(image, nr, nc, color, oldColor);
                }
            }

        }


    }
};