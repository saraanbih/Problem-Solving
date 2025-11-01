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
        ListNode* ans = nullptr;
        ListNode* cur = nullptr;
        while(head){
            if(!st.count(head->val)){
                if(ans == nullptr){
                    ans = new ListNode(head->val);
                    cur = ans;
                }
                else{
                    cur->next = new ListNode(head->val,nullptr);
                    cur = cur->next;
                }
            }
            head = head->next;
        }
       
        return ans;
    }
};