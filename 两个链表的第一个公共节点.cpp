/***
 * 输入两个链表，找出它们的第一个公共结点。
 * 
 * 解题思路：找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
 * （因为2个链表用公共的尾部）
 * 
 * */

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int l1 = 0;
        int l2 = 0;
        while(p1 != NULL) {
            l1++;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            l2++;
            p2 = p2->next;
        }
        //使得l1比l2大
        p1 = pHead1;
        p2 = pHead2;
        ListNode* tmp = p1;
        int tempi = l1;
        if(l1 < l2) {
            p1 = p2;
            p2 = tmp;

            l1 = l2;
            l2 = tempi;
        }

        while(l1-- > l2) {
            //p1走一段路直到长度和p2相等
            p1 = p1->next;
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;

    }
};

int main(){



    system("pause");
    return 0;
}