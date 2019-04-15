/***输入一个链表，输出该链表中倒数第k个结点。
 * 
 * 解题思路：要十分注意边界问题，判断头节点是否为NULL或沿着头节点走下去是是否会出现问题
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {

        if (pListHead == NULL || k <= 0)
        {
            return NULL;
        }
        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;
        for (int i = 1; i < k; i++)
        {
            if (p1->next != NULL)
            {
                p1 = p1->next;
            }
            else
            {
                return NULL;
            }
        }
        while (p1->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};

int main()
{

    ListNode *head = new ListNode(0);
    ListNode *p = new ListNode(1);
    head->next = p;
    for (int i = 2; i <= 9; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    p->next = NULL;
    Solution s;
    cout << s.FindKthToTail(head, 1)->val << endl;
    system("pause");
}