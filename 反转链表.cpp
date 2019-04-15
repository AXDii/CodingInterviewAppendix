/***
 * 反转链表，输出新链表的头
 * 
 * 解题思路：创建一个新的头节点，使用头插法重新构建链表
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
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = NULL;
        while (pHead != NULL)
        {
            p = pHead->next;
            pHead->next = head->next;
            head->next = pHead;
            pHead = p;
        }
        return head->next;
    }
};

int main()
{
    return 0;
}