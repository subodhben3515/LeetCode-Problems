class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >=image[0].size() || image[sr][sc] != oldColor )
            return;

        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, newColor, oldColor);
        dfs(image, sr-1, sc, newColor, oldColor);
        dfs(image, sr, sc+1, newColor, oldColor);
        dfs(image, sr, sc-1, newColor, oldColor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color)
            return image;

        int oldColor = image[sr][sc];

        dfs(image, sr, sc, color, oldColor);

        return image;

        
    }
};
