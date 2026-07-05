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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        int cnt=0;
        while(temp&& cnt<k){
            temp=temp->next;
            cnt++;
        }
        if(cnt<k)return head;

        int c=k;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(c){
            ListNode* temp2=curr->next;
            curr->next= prev;
            prev=curr;
            curr=temp2;
            c--;
        }
        head->next= reverseKGroup(curr,k);
        return prev;
        
    }
};
