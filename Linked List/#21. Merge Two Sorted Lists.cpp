//Approach 1 - TC-O(N1+N2) & SC-O(N1 +N2)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *result = new ListNode();
        ListNode *dd = result;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                ListNode *dup = new ListNode(l1->val);
                dd->next = dup;
                dd = dup;
                l1 = l1->next;
            }
            else if (l1->val > l2->val)
            {
                ListNode *dup = new ListNode(l2->val);
                dd->next = dup;
                dd = dup;
                l2 = l2->next;
            }
            else
            {
                ListNode *dup = new ListNode(l1->val);
                dd->next = dup;
                dd = dup;
                ListNode *ddup = new ListNode(l2->val);
                dd->next = ddup;
                dd = ddup;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        while (l1 != NULL)
        {
            dd->next = new ListNode(l1->val);
            dd = dd->next;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            dd->next = new ListNode(l2->val);
            dd = dd->next;
            l2 = l2->next;
        }
        return result->next;
    }
};

//Apporach 2 TC-O(N1+N2) SC-O(1)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val > l2->val)
        {
            ListNode *exchng = l1;
            l1 = l2;
            l2 = exchng;
        }
        ListNode *res = l1;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode *temp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;

            ListNode *exchng = l1;
            l1 = l2;
            l2 = exchng;
        }
        return res;
    }
};