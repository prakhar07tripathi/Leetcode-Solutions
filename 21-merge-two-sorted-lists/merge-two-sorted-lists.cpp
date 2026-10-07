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
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* root = new ListNode(-1);
        ListNode* temp = root;
        while(temp1 && temp2){
            if(temp1->val > temp2->val){
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
            else{
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        if(!temp1){
            while(temp2){
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        if(!temp2){
            while(temp1){
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        return root->next;
    }
};