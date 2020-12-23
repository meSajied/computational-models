#include <headers/tree.h>

Tree::in_order_travrsal(TreeNode* node){
    if(node != null){
        Tree::in_order_travrsal(node->left);
        Tree::in_order_travrsal(node->right);
    }
}

Tree::post_order_travrsal(TreeNode node){
    if(node != null){
        Tree::post_order_travrsal(node->left);
        Tree::post_order_travrsal(node->right);
    }
}