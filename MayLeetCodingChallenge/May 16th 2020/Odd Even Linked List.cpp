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
    ListNode* oddEvenList(ListNode* head) {
         if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *pre,*curr,*nxt;
        pre=head; curr=head->next; nxt=head->next;
        int c=2;
        while(nxt!=NULL&&nxt->next!=NULL)
        {
            int t=c;
            ListNode *temp1,*temp2;
            temp1=pre;
            while(t--)
            {
                temp1=temp1->next;
            }
            pre->next=temp1;
            temp2=temp1->next;
            temp1->next=curr;
            nxt->next=temp2;
            pre=temp1;
            nxt=nxt->next;
            c++;
        }
        return head;
    }
};
