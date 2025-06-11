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

        ListNode* ptr = head;
        ListNode* curr = NULL;
        int len = 0;
        
        while(ptr)
        {
            ptr = ptr->next;
            len++;
        }
        if(len == 1)
            return NULL;
        ptr = head;
        for(int i = 0; i < len - n; i++)
        {
            curr = ptr;
            ptr = ptr->next;
        }
        if(curr == NULL)
            return head->next;
        curr->next = ptr->next;
        return head;
        
    }
};