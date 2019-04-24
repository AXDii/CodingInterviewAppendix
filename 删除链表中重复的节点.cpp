/***
 * 
 * 在一个排序的链表中，存在重复的结点，
 * 请删除该链表中重复的结点，重复的结点不保留，
 * 返回链表头指针。 例如，链表1->2->3->3->4->4->5 
 * 处理后为 1->2->5
 * 
 * 解题思路：我这个解法有错误，但在这里试了很多次都是正确的，解题思路是通过跳过重复元素
 * 别人正确的代码：法二
 * 
 * */

#include <iostream>
// #include <vector>
// #include<algorithm>
// #include<string>
// #include <stack>
// #include <queue>
// #include <map>
// #include <stdlib.h>
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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        ListNode *p = pHead;    //指向最新的节点
        ListNode *mark = NULL; //指向第一个重复节点
        ListNode *nHead = NULL;
        int count = 1;
        //排除空姐点或只有一个节点的情况
        if (pHead == NULL && pHead->next == NULL)
        {
            cout<<"??"<<endl;
            return pHead;
        }
        while (p != NULL)
        {
            while (p->next != NULL && p->val == p->next->val)
            {
                ListNode* tmp = p->next;
                p ->next = NULL;
                p = tmp;
                count++;
            }
            if (count > 1)
            {
                p = p->next;
                count = 1;
                continue;
            }
            ListNode *tmp = p->next;
            p->next = NULL;

            if (nHead == NULL)
            {
                mark = nHead = p;
            }
            else
            {
                mark->next = p;
                mark = mark->next;
            }
            p = tmp;
        }
        pHead = nHead;
        return pHead;
    }

    //别人AC的代码
    ListNode* deleteDuplication2(ListNode* pHead)
    {
          if(pHead==NULL||pHead->next==NULL) return pHead;
          else
          {
              //新建一个节点，防止头结点要被删除
              ListNode* newHead=new ListNode(-1);
              newHead->next=pHead;
              ListNode* pre=newHead;
              ListNode* p=pHead;
              ListNode* next=NULL;
              while(p!=NULL && p->next!=NULL)
              {
                  next=p->next;
                  if(p->val==next->val)//如果当前节点的值和下一个节点的值相等
                  {
                      while(next!=NULL && next->val==p->val)//向后重复查找
                          next=next->next;
                    pre->next=next;//指针赋值，就相当于删除
                    p=next;
                  }
                  else//如果当前节点和下一个节点值不等，则向后移动一位
                  {
                      pre=p;
                      p=p->next;
                  }
              }
           return newHead->next;//返回头结点的下一个节点
               
          }
    }
};

int main()
{

    ListNode a(2), b(2), c(3), d(3), e(4), f(7), g(5), h(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    Solution s;
    ListNode*tmp = s.deleteDuplication(&a);
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
    system("pause");
    return 0;
}