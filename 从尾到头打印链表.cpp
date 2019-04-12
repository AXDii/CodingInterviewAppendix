/**输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 * 
 * 解题思路1：最糟糕的方法，vector头插入节点
 * 解题思路2：反转链表，然后再输出
 */

#include<iostream>>
#include<vector>
#include<cstring>

using namespace std;

void stop();

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};


vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> a;
    ListNode* p = head;
    while(p != NULL) {
        a.insert(a.begin(), p->val);
        p = p->next;
    }
    return a;
}

//反转链表
vector<int> printListFromTailToHead2(ListNode* head) {
    vector<int> a;

    ListNode* tmp = new ListNode(0);
    ListNode* p = head;
    ListNode* p2 = tmp;

    while(p != NULL) {
        ListNode *temp = p2->next;
        p2->next = p;
        p = p->next;
        p2->next->next = temp;
    }
    tmp = tmp ->next;
    while(tmp != NULL) {
        a.push_back(tmp->val);
        tmp = tmp->next;
    }
    return a;
}

int main(){

    
    stop();
    return 0;
}

void stop(){
    cout<<endl;
    system("pause");
}