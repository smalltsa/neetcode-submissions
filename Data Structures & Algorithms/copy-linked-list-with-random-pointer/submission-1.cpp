class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* cur = head;

        // 第一輪：建立所有新節點
        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        // 第二輪：建立 next / random 關係
        while (cur != nullptr) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];

            cur = cur->next;
        }

        return mp[head];
    }
};