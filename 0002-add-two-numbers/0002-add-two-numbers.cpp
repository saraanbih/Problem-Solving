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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       ListNode*n1 = new ListNode(0);
       ListNode*n2 = n1;
       int c = 0;
       while(l1 || l2 || c){
          int d1 = (l1 != nullptr) ? l1->val : 0;
          int d2 = (l2 != nullptr) ? l2->val : 0;
          int s = d1+d2+c;
          int d = s%10;
          c = s/10;
          n2->next = new ListNode(d);
          n2 = n2->next;
         l1 = (l1 != nullptr) ? l1->next : nullptr;
         l2 = (l2 != nullptr) ? l2->next : nullptr;
       }
       return n1->next;
    }
};