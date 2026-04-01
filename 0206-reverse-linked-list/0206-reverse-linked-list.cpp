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
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        if(v.empty())return {};
        reverse(v.begin(),v.end());
        ListNode* h = new ListNode(v[0]);
        ListNode* cur = h;
        for(int i=1;i<v.size();i++){
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }
        return h;
    }
};