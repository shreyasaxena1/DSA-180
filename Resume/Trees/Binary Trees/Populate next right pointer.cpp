class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        Node *node = root;
    
        
        while(node){
                Node *temp = node;
            while(temp){
                if(temp->left){
                    if(temp->right)
                        temp->left->next = temp->right;
                    else
                        temp->left->next = getNextRight(temp);
                }
                if(temp->right)
                    temp->right->next = getNextRight(temp);
                
                temp=temp->next;
            }
            if(node->left)
                node = node->left;
            else if(node->right)
                node=node->right;
            else
                node = getNextRight(node);
                
        }
        return root;
        
    }
    
    Node *getNextRight(Node *node){
        Node *t = node->next;
        while(t!=NULL){
            if(t->left) //first we check for left as it is closer right to node
                return t->left;
            if(t->right)
                return t->right;
            
            t=t->next; //If both are null check for next node at same level
        }
        return NULL;
    }
};
