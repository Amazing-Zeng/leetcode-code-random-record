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
    /*双指针写法*/
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            ListNode * temp;
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
            
        }
        return pre;
        
    }
};