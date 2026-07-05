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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return NULL;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev= &dummy;
        ListNode* temp=head;
        while(n>0 && temp!=NULL){
            temp=temp->next;
            n--;
        }
        while(temp){
            prev=prev->next;
            temp=temp->next;
        }
        ListNode* t= prev->next;
        prev->next=prev->next->next;
        delete t;
        return dummy.next;
        
        
    }
};
