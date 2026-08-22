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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        
        // find the length of the ll
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        // join last node to 1st node
        temp->next=head;

        // reach len-k node to find the new head
        k=k%len;
        k=len-k;
        while(k!=0){
            temp=temp->next;
            k--;
        }
        // point to null and assign correct head
        head=temp->next;
        temp->next=NULL;

        return head;
    }
};