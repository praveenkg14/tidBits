/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* createNode (int val)
    {
        TreeNode *t = new TreeNode;
        t->val = val;
        t->left = NULL;
        t->right = NULL;
        return (t);
    }
    
    void insertNode (TreeNode **root, int val)
    {
        if (*root == NULL)
            *root = createNode(val);
        else if (val > (*root)->val)
            insertNode(&((*root)->right), val);
        else if (val <= (*root)->val)
            insertNode(&((*root)->left), val);
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int num = preorder.size();
        if (num == 0)
            return 0;
        
        
        // Create BST
        TreeNode* root = NULL;
        int temp;
        for (int i = 0; i < num; i++)
        {
            temp = preorder[i];
            insertNode(&root, temp);
        }

        return root;
        
    }
};