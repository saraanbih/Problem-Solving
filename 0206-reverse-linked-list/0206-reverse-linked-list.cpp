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
    ListNode* reverseList(ListNode* cur,ListNode*prev = nullptr) {
       if(cur == nullptr) return prev;
       ListNode*nxt = cur->next;
       cur->next = prev;
       return reverseList(nxt,cur);
    }
};
