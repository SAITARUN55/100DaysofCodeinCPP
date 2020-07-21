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
         ListNode* curr = head;
        if(head == NULL)
        {
            return NULL;
        }
        while(curr->next!= NULL)  //Iterate until linked list is not null
        {
            if(curr->next->val == val)  // If the next element's value equals  'val' . Then Shift currents next to the next of current's next node. And repeat same, checking current with currents next.
            {
                curr->next = curr->next->next;
            }
            else       // otherwise shift current to currents next.
            {
                curr = curr->next;
            }
        }
        if(head->val == val)   // Check if the initial Head ( beginning current) was equal to Val. If so, shift it to next.
        {
            head = head->next;
        }
        return head;
    }
};
