// 4 ms, faster than 99.19% of C++

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                break;
        }

        if (fast != slow)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};