/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//  Method 1 (using reccursion)

// class Solution {
// public:
//     void InOrder(TreeNode *root , vector<int>& ans){
//         if(root == NULL) return;
//         InOrder(root->left , ans);
//         ans.push_back(root->val);
//         InOrder(root->right , ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         InOrder(root , ans);
//         return ans;
//     }
// };




// Method 2(iterative manner)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        TreeNode* node = root;
        while(st.size()>0 || node){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();
                v.push_back(temp->val);
                node = temp->right;
            }
        }
        return v;
    }
};