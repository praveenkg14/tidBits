#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        int product = 1;
        
        vector<int> result(len, 1);
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        
        // Left Multiplier
        for (int i = 1; i < len; i++)
        {
            left[i] = left[i-1] * nums[i-1]; 
        }
        
        // Right Multiplier
        for (int i = len-2; i >= 0; i--)
        {
            right[i] = right[i+1] * nums[i+1]; 
        }
      
        
        for (int i = 0; i < len; i++)
        {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
};

int main ()
{

return 0;
}
