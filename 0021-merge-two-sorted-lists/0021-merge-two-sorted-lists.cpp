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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* DummyNode=new ListNode(-1);
        ListNode* ans=DummyNode;
        ListNode* i=list1;
        ListNode* j=list2;
        while(i!=NULL && j!=NULL){
            if(i->val<j->val){
                DummyNode->next=i;
                DummyNode=DummyNode->next;
                i=i->next;
            }
            else{
                DummyNode->next=j;
                DummyNode=DummyNode->next;
                j=j->next;
            }
        }
        while(i!=NULL){
            DummyNode->next=i;
            DummyNode=DummyNode->next;
            i=i->next;
        }
        while(j!=NULL){
            DummyNode->next=j;
            DummyNode=DummyNode->next;
            j=j->next;
        }
        return ans->next;
        
    }
};