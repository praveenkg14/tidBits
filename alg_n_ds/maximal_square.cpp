class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> s(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 | j == 0)
                    s[i][j] = (int)matrix[i][j] - 48;
                
                else if ((int)matrix[i][j] == 49)
                {
                    s[i][j] = min(s[i][j-1],min( s[i-1][j], s[i-1][j-1])) + 1; 
                }
                
                else
                    s[i][j] = 0;
                
                if (ans < s[i][j])
                    ans = s[i][j];
            }
        }
        return (ans*ans);
        
    }
};