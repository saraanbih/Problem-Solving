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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> values;
        while(head){
            if(!st.count(head->val))
                values.push_back(head->val);
            head = head->next;
        }
        ListNode* ans = new ListNode(values[0],nullptr);
        ListNode* cur = ans;
        for(int i=1;i<values.size();i++){
            cur->next = new ListNode(values[i],nullptr);
            cur = cur->next;
        }
        return ans;
    }
};