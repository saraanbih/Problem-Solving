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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || k == 0) return head;

        ListNode* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }
        
        temp->next = head;

        k = k % length;
        for (int i = 0; i < length - k; i++) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};