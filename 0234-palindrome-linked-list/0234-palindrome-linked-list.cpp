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
    ListNode* reverse1(ListNode* slow){
        ListNode* curr=slow;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        ListNode* slow=head;
        ListNode* fast=head;
        //slow and fast pointer...
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        ListNode* curr1=reverse1(slow);
        while(head!=NULL && curr1!=NULL && head->val==curr1->val){
            head=head->next;
            curr1=curr1->next;
        }
        if(head!=NULL && curr1!=NULL  && head->val!=curr1->val){
            return false;
        }
        return true;
    }
};