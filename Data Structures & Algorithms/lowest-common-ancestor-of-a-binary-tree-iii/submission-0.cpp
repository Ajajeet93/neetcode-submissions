/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    Node *Root(Node* root){
        if(!root->parent) return root;
        return Root(root->parent);
    }
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root) return NULL;
        if(root == p) return p;
        if(root == q) return q;

        Node *left = lowestCommonAncestor(root->left,p,q);
        Node *right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;
        if(left) return left;
        return right;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *temp = p;
        Node *root = Root(p);
        return lowestCommonAncestor(root,p,q);
    }
};