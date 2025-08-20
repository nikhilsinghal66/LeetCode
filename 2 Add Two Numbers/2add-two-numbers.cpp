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
    ListNode* make_root(vector<int> ans){
        if(ans.size()==0) return nullptr;
        int n=ans.size();
        ListNode* root=new ListNode(ans[0]);
        ListNode* dummy=root;
        for(int i=1;i<n;i++){
            ListNode* node=new ListNode(ans[i]);
            root->next=node;
            root=root->next;
        }
        return dummy;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        vector<int> ans;
        while(l1!=nullptr || l2!=nullptr){
            int sum=flag;
            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;

            } 
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;

            } 
            flag = sum / 10;
            ans.push_back(sum % 10);
        }
        if(flag>0){
            ans.push_back(flag);

        }
        ListNode* root=make_root(ans);
        return root;
    }
};