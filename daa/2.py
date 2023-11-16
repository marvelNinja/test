import heapq

# Creating Huffman tree node class
class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq  # frequency of symbol
        self.symbol = symbol  # symbol name (character)
        self.left = left  # node left of the current node
        self.right = right  # node right of the current node
        self.huff = ''  # tree direction (0/1)

    def __lt__(self, nxt):
        return self.freq < nxt.freq

    def print_nodes(self, val=''):
        new_val = val + str(self.huff)

        # If the node is not a leaf node, traverse inside it
        if self.left:
            self.left.print_nodes(new_val)
        if self.right:
            self.right.print_nodes(new_val)

        # If the node is a leaf node, display its Huffman code
        if not self.left and not self.right:
            print(f"{self.symbol} -> {new_val}")

if __name__ == "__main__":
    chars = ['a', 'b', 'c', 'd', 'e', 'f']
    freq = [5, 9, 12, 13, 16, 45]
    nodes = []

    for i in range(len(chars)):
        # Convert characters and frequencies into Huffman tree nodes
        heapq.heappush(nodes, Node(freq[i], chars[i]))

    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)

        left.huff = 0
        right.huff = 1

        # Combine the two smallest nodes to create a new node as their parent
        new_node = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
        heapq.heappush(nodes, new_node)

    root = nodes[0]  # The root of the Huffman Tree
    root.print_nodes()
