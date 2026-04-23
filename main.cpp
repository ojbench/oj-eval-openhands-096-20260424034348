

#include &lt;vector&gt;
#include &lt;iostream&gt;
#include &lt;unordered_map&gt;
#include &lt;algorithm&gt;
using namespace std;

// Structure to store node information
struct NodeInfo {
    int depth;
    int parent;
    NodeInfo(int d, int p) : depth(d), parent(p) {}
};

class Solution {
public:
    // Build the tree from preorder traversal and store node information
    void buildTree(vector&lt;int&gt;& input, unordered_map&lt;int, NodeInfo&gt;& nodeMap, int& index, int depth, int parent) {
        if (index >= input.size() || input[index] == -1) {
            index++;
            return;
        }
        
        int val = input[index++];
        nodeMap[val] = NodeInfo(depth, parent);
        
        // Recursively build left and right subtrees
        buildTree(input, nodeMap, index, depth + 1, val);
        buildTree(input, nodeMap, index, depth + 1, val);
    }
    
    // Check if two nodes are cousins
    int areCousins(int x, int y, unordered_map&lt;int, NodeInfo&gt;& nodeMap) {
        // Both nodes must exist
        if (nodeMap.find(x) == nodeMap.end() || nodeMap.find(y) == nodeMap.end()) {
            return 0;
        }
        
        NodeInfo infoX = nodeMap[x];
        NodeInfo infoY = nodeMap[y];
        
        // Check if they are at the same depth and have different parents
        return (infoX.depth == infoY.depth && infoX.parent != infoY.parent) ? 1 : 0;
    }
};

int main() {
    Solution solution;
    int q;
    cin >> q;
    
    // Read the queries
    vector&lt;pair&lt;int, int&gt;&gt; queries;
    for (int i = 0; i &lt; q; i++) {
        int x, y;
        cin >> x >> y;
        queries.push_back({x, y});
    }
    
    // Read the preorder traversal
    vector&lt;int&gt; preorder;
    int val;
    while (cin >> val) {
        preorder.push_back(val);
    }
    
    // Build the tree and store node information
    unordered_map&lt;int, NodeInfo&gt; nodeMap;
    int index = 0;
    solution.buildTree(preorder, nodeMap, index, 0, -1);
    
    // Answer the queries
    for (auto& query : queries) {
        cout << solution.areCousins(query.first, query.second, nodeMap) << endl;
    }
    
    return 0;
}

