/**
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
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }

        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int k = len - n;
        temp = head;
        while (k > 1) {
            temp = temp->next;
            k--;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return head;
    }
};