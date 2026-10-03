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
        if(list1 == NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val > list2->val){
            ListNode* temp = list2;
            list2 = list1;
            list1 = temp;
        }
        ListNode* head = list1;
        ListNode* last = list1;
        while(list2!=NULL){
            if(list1->next == NULL && list2->val >= list1->val) {
                list1->next = list2;
                break;
            }
            if(list2->val < list1->val){
                ListNode* nxt = list1;
                ListNode* inrt = list2;
                
                list2 = list2->next;
                last->next = inrt;
                last=inrt;
                inrt->next = nxt;
            }
            else{
                last = list1;
                list1 =  list1->next;
                cout<<"last, list1, list2"<<"  "<<last->val<<" "<<list1->val<<" "<<list2->val<<endl;
            }
        }
        return head;
    }
};
