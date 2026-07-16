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
        int temp=0;
        ListNode* arr=head;
        while(arr!=NULL){
            temp++;
            arr=arr->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        n=temp-n;
        if(n==0){
            return head->next;
        }
        int count=0;
        while(curr!=NULL){
            if(count==n){
                ListNode* next1=curr->next;
                curr->next=NULL;
                prev->next=next1;
                break;
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};