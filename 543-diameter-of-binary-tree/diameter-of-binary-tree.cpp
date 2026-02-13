
class Solution {
public:
    pair<int,int> diameter(TreeNode* root){
        if(root == NULL)
            return {0,0};

        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);

        int left_diam = left.first;
        int right_diam = right.first;

        int curr_height = 1 + max(left.second, right.second);

        int curr_diam = max(left.second + right.second,
                       max(left_diam, right_diam));

        return {curr_diam, curr_height};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};
