/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node]=new Node(node->val);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(auto nei:curr->neighbors){
                if(mp.find(nei)==mp.end()){
                    Node* new_node=new Node(nei->val);
                    mp[nei]=new_node;
                    q.push(nei);
                }
                mp[curr]->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
};