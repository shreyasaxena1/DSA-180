class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;
        Node *curr = head;
        Node *next = new Node(0);
        //create duplicate
        while (curr)
        {
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        //connect random
        curr = head;
        while (curr)
        {
            curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
            curr = curr->next->next;
        }

        Node *iter = head, *front;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;

        while (iter != NULL)
        {

            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;

            copy = copy->next;
            iter = front;
        }

        return pseudoHead->next;
    }
};