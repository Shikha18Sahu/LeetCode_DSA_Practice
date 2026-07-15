class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Different color
        if (image[r][c] != oldColor)
            return;

        // Fill the color
        image[r][c] = newColor;

        // Visit 4 directions
        dfs(image, r - 1, c, oldColor, newColor); // Up
        dfs(image, r + 1, c, oldColor, newColor); // Down
        dfs(image, r, c - 1, oldColor, newColor); // Left
        dfs(image, r, c + 1, oldColor, newColor); // Right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // If color is already same, no need to do anything
        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};