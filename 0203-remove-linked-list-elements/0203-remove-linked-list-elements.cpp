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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* DummyNode=new ListNode(0);
        DummyNode->next=head;
        ListNode* cur=DummyNode;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
            {
                cur=cur->next;
            }
        }
        
        head=DummyNode->next;
        //错误：heap-use-after-free  指向最后一个数据，如果free，那么就会造成访问到一块已经被释放的内存
        //delete cur;
        delete DummyNode;
        return head;
    }
};