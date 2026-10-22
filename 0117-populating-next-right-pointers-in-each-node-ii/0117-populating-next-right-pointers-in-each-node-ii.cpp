/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> que;
        if(root==NULL) return root;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            Node* node;
            Node* prenode;
            for(int i=0;i<size;i++)
            {
                if(i==0)
                {
                    node=que.front();
                    que.pop();
                    prenode=node;
                }else
                {
                    node=que.front();
                    que.pop();
                    prenode->next=node;
                    prenode=node;                    
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            node->next=NULL;

        }
        return root;

    }
};