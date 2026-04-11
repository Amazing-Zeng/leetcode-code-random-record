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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode * cur=dummyHead;
        // 要分清楚是奇数还是偶，有顺序！！！
        while(cur->next!=nullptr&&cur->next->next!=nullptr)
        {
            ListNode * temp1;
            ListNode * temp2;
            temp1=cur->next;
            temp2=temp1->next->next; 
            cur->next=cur->next->next;  // 步骤一
            cur->next->next=temp1;   // 步骤二
            temp1->next=temp2;   // 步骤三
            cur=temp1;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;   
    }
};