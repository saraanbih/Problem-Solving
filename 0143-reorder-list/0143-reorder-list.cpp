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
    vector<int> solve(vector<int>& v) {
        int i = 0, n = v.size() - 1;
        vector<int> res;
        while (i <= n) {
            res.push_back(v[i]);
            if (i != n) {
                res.push_back(v[n]);
            }
            i++;
            n--;
        }
        return res;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Edge case: empty list or single node

        // Step 1: Store the values of the linked list in a vector
        ListNode* temp = head;
        vector<int> v;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Reorder the values using the solve function
        vector<int> res = solve(v);

        // Step 3: Update the original linked list with the reordered values
        temp = head;
        int index = 0;
        while (temp) {
            temp->val = res[index++];
            temp = temp->next;
        }
    }

};