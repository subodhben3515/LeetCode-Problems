class Solution {
public:
/*

maintain resultMat with all -1
find 0 in the original mat and fill resultMat with 0
Maintain direction vector
then use bfs to find out all adj mats from current 0 pair
add distance accordingly
*/
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> result(row, vector<int>(col, -1));
        //vector<vector<int>> result[row][col]{-1};

        queue<pair<int,int>> q;

        for(int i =0 ; i < row ; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.emplace(i,j);
                }
            }
        }

        vector<int> directions{-1, 0, 1, 0, -1};

        while(!q.empty())
        {
            auto [currentRow, currentCol] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nextRow = currentRow+directions[i];
                int nextCol = currentCol+directions[i+1];

                if(nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && result[nextRow][nextCol] == -1)
                {
                    result[nextRow][nextCol] = result[currentRow][currentCol]+1;
                    q.emplace(nextRow, nextCol);
                }
            }
        }
        return result;
    }
};
