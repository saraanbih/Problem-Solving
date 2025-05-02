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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(head->next == nullptr || head == nullptr) return head;
        ListNode * pre = head,*curr = head->next;
        while(curr)
        {
            int NewVal = gcd(pre->val,curr->val);
            ListNode * NewNode = new ListNode(NewVal);
            pre->next = NewNode;
            NewNode->next = curr;
            pre = curr;
            curr = curr->next;
        }
        
        return head;
        
    }
};