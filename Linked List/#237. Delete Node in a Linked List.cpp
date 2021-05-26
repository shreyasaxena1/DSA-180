//O(1)
//Just copied value of next node to current node and delete next

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *del = node->next;
        node->next = node->next->next;
        delete (del);
    }
};