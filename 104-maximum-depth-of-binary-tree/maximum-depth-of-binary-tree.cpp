
class Solution {
public:
int level_order(TreeNode* root){
   
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL); // we know that one level is completed
    int level=0;
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL){
           level+=1;
           if(!q.empty())
           q.push(NULL);
        }
        else{
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }

    return level;
}
    int maxDepth(TreeNode* root) {
        // we can do using level order traversal
         if(root==NULL)
       return 0;

       int ans=level_order(root);
       return ans;

    }
};