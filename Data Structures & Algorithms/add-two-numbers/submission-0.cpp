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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp=&dummy;
        long long carry=0;
        while(l1 || l2){
            long long v1= (l1)? l1->val:0;
            long long v2= (l2)? l2->val:0;
            long long sum=v1+v2+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            l1=l1? l1->next:NULL;
            l2=l2? l2->next:NULL;
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return dummy.next;
        
    }
};
