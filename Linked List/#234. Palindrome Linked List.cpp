// TC - O(N) SC - O(1)

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return true;

        ListNode *s = head;
        ListNode *f = head;

        //Find middle
        while (f->next != NULL && f->next->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }

        ListNode *curr = s->next;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        //Reverse right half of the middle
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        s->next = prev;

        f = head;
        s = s->next;
        //Compare data of left and right half
        while (s)
        {
            if (s->val != f->val)
                return false;
            s = s->next;
            f = f->next;
        }

        return true;
    }
};