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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,i});
            }
        }
        ListNode dummy(-1);
        ListNode* temp=&dummy;
        while(!pq.empty()){
            auto [val, i]=pq.top();
            pq.pop();
            temp->next=new ListNode(val);
            temp=temp->next;
            lists[i]=lists[i]->next;
            if(lists[i]){
                pq.push({lists[i]->val,i});
            }

        }
        return dummy.next;
        
    }
};
