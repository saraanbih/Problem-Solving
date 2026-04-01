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
    void reorderList(ListNode* head) {
        ListNode *fast = head,*slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* cur=slow->next,*prev = NULL,*nxt=NULL;
        slow->next = NULL;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        ListNode* first=head, *second=prev;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};