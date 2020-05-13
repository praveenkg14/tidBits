class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        int ans = 0;
        vector<vector<int>> r(n+1, vector<int> (m+1, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (text1[i] == text2[j])
                    r[i+1][j+1] = r[i][j] + 1;
                else
                    r[i+1][j+1] = max(r[i+1][j], r[i][j+1]);
                
                if (ans < r[i+1][j+1])
                    ans = r[i+1][j+1];
            }
        }
        return ans;
    }
};