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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if list is empty or k is 1
        if (!head || k == 1) return head;

        // Step 1: Find the length of the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Step 2: Create a dummy node to simplify head edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        curr = head;

        // Step 3: Process groups of size k
        while (length >= k) {
            ListNode* groupStart = curr;
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;

            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the reversed group back to the main list
            prevGroupEnd->next = prev;
            groupStart->next = curr;

            // Update pointers for the next group
            prevGroupEnd = groupStart;
            length -= k;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};