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
    int getDecimalValue(ListNode* head) {
        string s = "";
        while (head != NULL) {
            s += (head->val + '0'); // Convert int (0 or 1) to char ('0' or '1')
            head = head->next;
        }
        bitset<30> b(s); // Updated to 30 bits to support up to 30 nodes
        int ans = b.to_ulong();
        return ans;
    }
};