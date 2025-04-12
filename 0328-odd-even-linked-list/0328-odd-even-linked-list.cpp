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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode*od = head,*ev = head->next;
        ListNode*ptr = ev;
        while(ev && ev->next){
            od->next = ev->next;
            od = od->next;
            ev->next = ev->next->next;
            ev = ev->next;
        }
        od->next = ptr;
        return head;
    }
};