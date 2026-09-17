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
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head = nullptr;
        if (curr1 == nullptr) return curr2;
        if (curr2 == nullptr) return curr1;
        if (curr1->val<curr2->val){
            head = curr1;
            curr1=curr1->next;
        }
        else{
            head = curr2;
            curr2=curr2->next;
        }
        ListNode* prev = head;
        while(curr1 != nullptr && curr2 != nullptr){
            if (curr1->val<curr2->val){
            prev->next = curr1;
            prev=curr1;//prev = prev->next;
            curr1=curr1->next;
            }
            else{
                prev->next = curr2;
                prev=curr2;
                curr2=curr2->next;
            }
        }
        if (curr1==nullptr){
            prev->next = curr2;
        }
        else{
            prev->next = curr1;
        }
        return head;
    }
};
