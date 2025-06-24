/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node * ptr = head;
        if(head == NULL) return NULL;
        while(ptr)
        {
            Node* tmp= new Node(ptr->val);
            tmp -> next = ptr -> next;
            ptr -> next = tmp;
            ptr = ptr->next->next;
        }

        ptr = head;

        while(ptr)
        {
            if(ptr->random)
                ptr -> next -> random = ptr -> random -> next;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node * curr = ptr;
        curr = curr -> next;
        Node * ans = curr;
        
        while(ptr and curr)
        {
            ptr->next = curr->next;
            if(curr->next)
                curr->next = ptr->next->next;
            ptr = ptr->next;
            curr = curr->next;
            
        }
        return ans;


      
    }
};