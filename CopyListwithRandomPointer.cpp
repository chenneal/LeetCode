/* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<int, int> hash_label;
        map<int, RandomListNode*> hash_p;
        RandomListNode* q;
        RandomListNode* p = head;
        RandomListNode* qhead = new RandomListNode(0);
        q = qhead;
        while (p) {
            q->next = new RandomListNode(p->label);
            if (p->random) {
                hash_label[p->label] = p->random->label;
            }
            hash_p[p->label] = q->next;
            q = q->next;
            p = p->next;
        }
        q = qhead->next;
        while (q) {
            if (hash_label.find(q->label) != hash_label.end()) {
                q->random = hash_p[hash_label[q->label]];
            }
            q = q->next;
        }
        return qhead->next;
    }
};