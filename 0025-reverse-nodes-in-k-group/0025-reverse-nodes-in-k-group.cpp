class Solution {
public:
    // Returns {newHead, newTail, nextGroupStart}
    vector<ListNode*> reverseList(ListNode* start, int k){
        ListNode* prev = NULL;
        ListNode* curr = start;
        while(k--){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // prev = new head
        // start = new tail
        // curr = next group's first node
        return {prev, start, curr};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroup = dummy;
        ListNode* start = head;
        while(start){
            // Check whether k nodes exist
            ListNode* temp = start;
            int count = 0;
            while(temp != NULL && count < k){
                temp = temp->next;
                count++;
            }
            if(count < k)
                break;
            // Reverse k nodes
            vector<ListNode*> ans = reverseList(start, k);
            ListNode* newHead = ans[0];
            ListNode* newTail = ans[1];
            ListNode* nextGroup = ans[2];
            // Connect previous group
            prevGroup->next = newHead;
            // Connect current group to remaining list
            newTail->next = nextGroup;
            // Move pointers
            prevGroup = newTail;
            start = nextGroup;
        }
        return dummy->next;
    }
};