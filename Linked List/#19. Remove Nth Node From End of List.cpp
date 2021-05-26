//TC - O(N) SC - O(1) One pass!

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummie = new ListNode();
        dummie->next = head;
        ListNode *f = dummie;
        ListNode *s = dummie;

        for (int i = 1; i <= n; ++i)
        {
            f = f->next;
        }

        while (f->next != NULL)
        {

            f = f->next;
            s = s->next;
        }

        ListNode *del = s->next;
        s->next = s->next->next;
        delete (del);
        return dummie->next;
    }
};
