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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev_l = dummy;
        for(int i=1;i<l;i++){
            prev_l = prev_l->next;
        }

        ListNode* cur = prev_l->next,*nxt = NULL,*prev = NULL;
        for(int i=0;i<r-l+1;i++){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        prev_l->next->next = cur;
        prev_l->next = prev;
        return dummy->next;
    }
};