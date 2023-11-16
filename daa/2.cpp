#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Creating Huffman tree node class
class Node {
public:
    int freq;      // Frequency of symbol
    char symbol;   // Symbol name (character)
    Node* left;    // Node left of the current node
    Node* right;   // Node right of the current node
    string huff;   // Tree direction (0/1)

    Node(int f, char s, Node* l = nullptr, Node* r = nullptr)
        : freq(f), symbol(s), left(l), right(r) {}

    bool operator<(const Node& other) const {
        return freq > other.freq;
    }

    void printNodes(string val = "") {
        string new_val = val + huff;

        // If the node is not a leaf node, traverse inside it
        if (left != nullptr) {
            left->printNodes(new_val);
        }
        if (right != nullptr) {
            right->printNodes(new_val);
        }

        // If the node is a leaf node, display its Huffman code
        if (left == nullptr && right == nullptr) {
            cout << symbol << " -> " << new_val << endl;
        }
    }
};

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    priority_queue<Node> nodes;

    for (size_t i = 0; i < chars.size(); i++) {
        // Convert characters and frequencies into Huffman tree nodes
        nodes.push(Node(freq[i], chars[i]));
    }

    while (nodes.size() > 1) {
        Node* left = new Node(nodes.top());
        nodes.pop();
        Node* right = new Node(nodes.top());
        nodes.pop();

        left->huff = "0";
        right->huff = "1";

        // Combine the two smallest nodes to create a new node as their parent
        Node* new_node = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);
        nodes.push(*new_node);
    }

    Node root = nodes.top(); // The root of the Huffman Tree
    root.printNodes();

    return 0;
}
