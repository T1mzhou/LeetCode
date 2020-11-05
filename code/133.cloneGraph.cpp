class Solution {
public:
    int index = 1;
    map<int,Node*> ref_back;

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node *copy = new Node(node->val);
        ref_back[copy->val] = copy;
        for(Node *i : node->neighbors){
            Node* next = i;
            if (ref_back.find(next->val) == ref_back.end())
                next = cloneGraph(next);
            else{
                copy->neighbors.push_back(ref_back[next->val]);
                continue;
            }
            copy->neighbors.push_back(next);
        }
        return copy;
    }
};
