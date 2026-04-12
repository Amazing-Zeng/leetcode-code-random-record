/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int i=0,j=0;
        ListNode *curA=headA;
        ListNode *curB=headB;
        /* 这样会减少最后一个值的个数*/
        // while(curA!=nullptr&&curA->next!=nullptr)
        // {
        //     curA=curA->next;
        //     i++;
        // }
        while(curA!=nullptr)
        {
            curA=curA->next;
            i++;
        }
        while(curB!=nullptr)
        {
            curB=curB->next;
            j++;
        }
        int base=(i-j)>=0? (i-j):(j-i);
        curA=headA;
        curB=headB;
        if(i>=j)
        {
            while(base--)
            {
                curA=curA->next;
            }
            /*遍历所有点，避免出现最后一个节点不访问*/
           // while(curA!=nullptr&&curA->next!=nullptr)
            while(curA!=nullptr)
            {
                if(curA==curB)
                {
                    return curA;
                }
                curA=curA->next;
                curB=curB->next;
                
            }
            return NULL;
        }
        else 
        {
            while(base--)
            {
                curB=curB->next;
            }
           while(curB!=nullptr)
            {
                if(curB==curA)
                {
                    return curB;
                }
                curB=curB->next;
                curA=curA->next;   
            }
            return NULL;
        }
        return NULL;
    }
};
/*法2*/
        // 让curA为最长链表的头，lenA为其长度
        // if (lenB > lenA) {
        //     swap (lenA, lenB);
        //     swap (curA, curB);
        // }
        // 求长度差
       // int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        // while (gap--) {
        //     curA = curA->next;
        // }
        // 遍历curA 和 curB，遇到相同则直接返回
        // while (curA != NULL) {
        //     if (curA == curB) {
        //         return curA;
        //     }
        //     curA = curA->next;
        //     curB = curB->next;
        // }
        // return NULL;
