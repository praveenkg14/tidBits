class Solution {
public:
    
    int pathsum(vector<vector<int>>& grid, vector<vector<int>>& visited, int M, int N, int m, int n)
    {
        int dsum = 1000;
        int rsum = 1000;
        
        if (m == (M-1) && n == (N-1))
        {
            visited[m][n] = grid[m][n];
            return (grid[m][n]); 
        }
        
        if (visited[m][n] != 0)
            return (visited[m][n]);
        
        if (n != (N-1))
        {
            rsum = pathsum(grid, visited, M, N, m, n+1);
        }
            
        if (m != (M-1))
        {
            dsum = pathsum(grid, visited, M, N, m+1, n);           
        }  
        
        visited[m][n] = (grid[m][n] + min(rsum, dsum));
        return (visited[m][n]);
    }
            
    int minPathSum(vector<vector<int>>& grid) {
        
        int M = grid.size();
        if(!M)
            return 0;
        int N = grid[0].size();
        
        vector<vector<int>> visited (M, vector<int> (N, 0));
        
        return (pathsum(grid, visited, M, N, 0 , 0));
        
    }
};