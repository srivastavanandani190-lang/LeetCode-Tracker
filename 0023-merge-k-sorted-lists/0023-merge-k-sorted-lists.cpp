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
class Comparator {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // Min Heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
       priority_queue<ListNode*, vector<ListNode*>, Comparator> p;
            for (ListNode* head : lists) {
            if (head)
                p.push(head);
        }
         
        ListNode *root=new ListNode(0);
        ListNode *tail=root;
        ListNode *temp;
         while(!p.empty()){
             temp=p.top();
             p.pop();
             tail->next=temp;
             tail=tail->next;
             if(temp->next){
                 p.push(temp->next);
             }
         }
         
         return root->next;
    }
};