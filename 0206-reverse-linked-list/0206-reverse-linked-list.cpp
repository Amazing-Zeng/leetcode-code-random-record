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
   
    ListNode* reverseList(ListNode* head) {
        
        ListNode *pre=nullptr;
        ListNode *cur=head;
        if(cur == NULL) return pre;
         /*双指针写法*/
        while(cur!=nullptr)
        {
            ListNode * temp;
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
            
        }
        return pre;
        /*递归写法*/
        //return ListNode* reverse(cur,pre);
    }
    /**
    ListNode* reverse(ListNode * cur,ListNode* pre)
    {
        if(cur==nullptr) return pre;
        ListNode * temp;
        temp=cur->next;
        cur->next=pre;
        reverse(temp,cur);
    }
    */
};
