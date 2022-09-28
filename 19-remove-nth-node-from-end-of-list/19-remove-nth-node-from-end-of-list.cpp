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
        ListNode* first=head;
        ListNode* second=head;
        ListNode* third=head;
        while(n--){
            first=first->next;
        }
        if(first==NULL){
            head=head->next;
            return head;
        }
        second=second->next;
        while(first->next!=NULL){
            first=first->next;
            second=second->next;
            third=third->next;
        }
        third->next=second->next;
        second->next=NULL;
        return head;
    }
};