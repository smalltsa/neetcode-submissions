class Codec {
public:

    void encode(TreeNode* root, string& data) {
        if (!root) {
            data += "#,";
            return;
        }

        data += to_string(root->val) + ",";

        encode(root->left, data);
        encode(root->right, data);
    }

    string serialize(TreeNode* root) {
        string data;
        encode(root, data);
        return data;
    }


    TreeNode* decode(vector<string>& nodes, int& i) {
        if (nodes[i] == "#") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = decode(nodes, i);
        root->right = decode(nodes, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;

        stringstream ss(data);

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int i = 0;

        return decode(nodes, i);
    }
};