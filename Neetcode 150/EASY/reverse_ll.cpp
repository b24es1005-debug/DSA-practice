class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;//saving curr->next
            curr->next = prev//reversing the link
            prev = curr;//move prev forward
            curr = next;//move curr forward
        }
        return prev;    
    }
};
