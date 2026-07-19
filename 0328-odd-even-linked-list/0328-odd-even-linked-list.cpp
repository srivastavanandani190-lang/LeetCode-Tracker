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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save the start of the even list to connect later
        
        while (even && even->next) {
            odd->next = even->next;   // Connect current odd node to next odd node
            odd = odd->next;          // Move odd pointer forward
            
            even->next = odd->next;   // Connect current even node to next even node
            even = even->next;        // Move even pointer forward
        }
        
        odd->next = evenHead;         // Attach the even list to the end of the odd list
        return head;
    }
};