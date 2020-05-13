class Solution {
public:
    bool checkValidString(string s) {
        
        if (!s.length())
            return true;
        
        int len = s.length();
        
        vector<int> v;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '*')
                v.push_back(0);
            if (s[i] == '(')
                v.push_back(-1);
            if (s[i] == ')')
                v.push_back(1);
        }
        
        vector<int> lsum, rsum;
        lsum.push_back(0);
        for (int i = 1; i < len; i++)
            lsum.push_back(lsum[i-1] + v[i-1]);
        
        rsum.push_back(0);
        for (int i = 1; i < len; i++)
            rsum.push_back(rsum[i-1] + v[len-i]);
        
        int c = 0;
        for (int i = 0; i < len; i++)
        {
            if (v[i] == 0)
            {
                if (lsum[i] + rsum[len-i-1] + c> 0)
                {
                    v[i] = -1;
                    c = c - 1;
                }
                if (lsum[i] + rsum[len-i-1] + c < 0)
                {
                    v[i] = 1;
                    c = c + 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum = sum + v[i];
            if (sum > 0)
                return false;
        }
        
        if (sum == 0)
            return true;
        else
            return false;
             
        /*
        vector<char> x;
        x.push_back(s[0]);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '*' | s[i] == '(')
                x.push_back(s[i]);
            if (s[i] == ')')
            {
                if (x.back() == '*' | x.back() == '(')
                    x.pop_back();
                else
                    return false;
            }
        }
        if (!x.size())
            return true;
        else
            return false;
        */
        
    }
};