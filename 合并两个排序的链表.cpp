/***
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * 
 * 
 * 解题思路：一个一个进行比较，要注意边界问题
 * 
 * */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *newHead = NULL;
        ListNode *p = NULL;
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        if (p1 == NULL)
        {
            newHead = p2;
            return newHead;
        }
        if (p2 == NULL)
        {
            newHead = p1;
            return newHead;
        }

        if (p1->val < p2->val)
        {
            p = newHead = p1;
            p1 = p1->next;
        }
        else
        {
            p = newHead = p2;
            p2 = p2->next;
        }

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != NULL)
        {
            p->next = p1;
        }
        if (p2 != NULL)
        {
            p->next = p2;
        }

        return newHead;
    }
};

int main()
{
    return 0;
}