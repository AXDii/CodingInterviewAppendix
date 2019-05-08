/***
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
 * 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注
 * 意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * 
 * 解题思路：1.先在每一个节点后面复制当前节点，2.配置新节点的random；3.拆分
 * 
 * */


#include<iostream>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) {
            return NULL;
        }
        RandomListNode *p = pHead;
        //复制节点
        while (p != NULL)
        {
            RandomListNode* r = new RandomListNode(p->label);
            r->next = p->next;
            p->next = r;
            p = r->next;
        }
        //确定指针方向
        p = pHead;
        while (p != NULL)
        {
            RandomListNode* node = p->next;
            if (p->random)
            {
                node->random = p->random->next;
            }
            
            p = node->next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode* tmp;
        p = pHead;
        while (p->next)
        {
            tmp = p->next;
            p->next = tmp->next;
            p = tmp;
        }
        return pCloneHead;
    }
};

int main(){



    system("pause");
    return 0;
}