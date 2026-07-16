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
    ListNode* rotateRight(ListNode* head, int k) {
        //Sliding window in linked list...
        if(head==NULL || k==0 || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* start=head;
        ListNode* prev=NULL;
        int count=0;
        int m=k;
        while(start!=NULL &&  k--){
            count++;
            prev=start;
            start=start->next;
        }
        if(start==NULL){
            k=m%count;
            if(k==0){
                return head;
            }
            start=head;
            while(start!=NULL &&  k--){
                prev=start;
                start=start->next;
            }
        }
        ListNode* prev1=NULL;
        while(start!=NULL){
            prev1=curr;
            curr=curr->next;
            prev=start;
            start=start->next;
        }
        prev1->next=NULL;
        prev->next=head;
        return curr;
    }
};