class Solution {
public:
    ListNode* rec(ListNode* head, int& n) { // Pass n by reference!
        if (!head) return nullptr;

        head->next = rec(head->next, n); // Go deeper in recursion
        n--; // Decrement n AFTER recursion returns

        if (n == 0) { // When we reach the nth node from the end
            return head->next; // Skip the current node
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return rec(head, n); // Pass n by reference so it updates correctly
    }
};
