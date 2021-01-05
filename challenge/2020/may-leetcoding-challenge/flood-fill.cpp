// DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)     return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int i, int j, int prevColor, int newColor) {
        if(i < 0 or i >= image.size() or j < 0 or j >= image[0].size() or image[i][j] != prevColor)
            return;
        
        image[i][j] = newColor;
        
        dfs(image, i-1, j, prevColor, newColor);
        dfs(image, i, j+1, prevColor, newColor);
        dfs(image, i+1, j, prevColor, newColor);
        dfs(image, i, j-1, prevColor, newColor);
    }
};
