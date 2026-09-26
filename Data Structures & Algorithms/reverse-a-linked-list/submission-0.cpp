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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current  = head;
        ListNode* nxt;
        while(current!=NULL){
            nxt = current->next;
            current->next = prev;
            prev= current;
            if(nxt==NULL) return current;
            current = nxt;
        }
        return head;
    }
};
