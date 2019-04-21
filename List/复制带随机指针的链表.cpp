/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 

 

示例：



输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 

提示：

你必须返回给定头的拷贝作为对克隆列表的引用。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( !head )
            return NULL;
        map<Node*, int> pos;
        map<int, int> random_pos;
        vector<Node*> new_list;
        int i = 0;
        for ( Node *tmp = head ; tmp ; tmp = tmp->next ) {
            pos[tmp] = i++;
        }
        i = 0;
        for ( Node *tmp = head ; tmp ; tmp = tmp->next) {
            if ( tmp->random == NULL )
                random_pos[i++] = -1;
            else
                random_pos[i++] = pos[tmp->random];
        }
        for ( Node *tmp = head ; tmp ; tmp = tmp->next ) {
            Node *new_node = new Node(tmp->val, NULL, NULL);
            new_list.push_back(new_node);
        }
        for ( int i = 0 ; i < new_list.size() ; i++ ) {
            if ( random_pos[i] != -1 )
                new_list[i]->random = new_list[random_pos[i]];
            if ( i != new_list.size() - 1 )
                new_list[i]->next = new_list[i+1];
        }
        return new_list.front();
    }
};
