/** Tested on leetcode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end = head, *kth = head;

        n--;
        while (n--) {end = end->next;}

        if (end->next == NULL) {
            head = head->next;
            delete kth;
            return head;
        }

        while (end->next->next != NULL) {end = end->next; kth = kth->next;}

        end = kth->next;
        kth->next = kth->next->next;
        delete end;

        return head;
    }
};