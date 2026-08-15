class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        if (a != nullptr)
            tail->next = a;
        else
            tail->next = b;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if (k == 0)
            return nullptr;

        for (int interval = 1; interval < k; interval *= 2) {

            for (int i = 0; i + interval < k; i += interval * 2) {

                lists[i] = mergeTwoLists(
                    lists[i],
                    lists[i + interval]
                );
            }
        }

        return lists[0];
    }
};