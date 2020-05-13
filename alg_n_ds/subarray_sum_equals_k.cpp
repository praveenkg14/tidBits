class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int N = nums.size();
        if (N == 0)
            return 0;
        int result = 0;
        
        vector<signed long> sums(N+1, 0);
        sums[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            sums[i] = sums[i-1] + nums[i-1];
        }
        
        for (int i = 0; i < N; i++)
            for (int j = i+1; j <= N; j++)
            {
                if ((sums[j] - sums[i]) == (signed long)k)
                    result++;
            }
        return result;
    }
};