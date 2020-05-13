class Solution {
public:
    
    void recurse (vector<vector<char>>& grid, int M, int N, int m, int n)
    {
        // Look UP - not likely
        if (m)
        {
            if (grid[m-1][n] == 49)
            {
                grid[m-1][n] = grid[m][n];
                recurse(grid, M, N, m-1, n);
            }
        }
        // Look Left
        if (n)
        {
            if (grid[m][n-1] == 49)
            {
                grid[m][n-1] = grid[m][n];
                recurse(grid, M, N, m, n-1);
            }
        }
        // Look Right
        if (n != (N-1))
        {
            if (grid[m][n+1] == 49)
            {
                grid[m][n+1] = grid[m][n];
                recurse(grid, M, N, m, n+1);
            }            
        }
        // Look Down
        if (m != (M-1))
        {
            if (grid[m+1][n] == 49)
            {
                grid[m+1][n] = grid[m][n];
                recurse(grid, M, N, m+1, n);
            }            
        }
    }
        
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (!grid.size())
            return 0;
        int M = grid.size();
        int N = grid[0].size();
        
        int count = 50;
        
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 49)
                {
                    grid[i][j] = count;
                    recurse(grid, M, N, i, j);
                    count++;
                }
            }
        }
        return (count-50);
    }
};