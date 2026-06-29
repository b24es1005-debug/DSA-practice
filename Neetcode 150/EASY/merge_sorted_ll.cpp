class Solution{
public:
    ListNode* mergeSortedLL(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(0);//dummy is like home //why, bcs it helps in returning the head at last
        ListNode* tail = dummy;//tail is like worker it moves
        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;//tail->next must point towards a node
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
        }
        if(l1) tail->next = l1; //remaining list after insertion
        if(l2) tail->next = l2;
        return dummy->next;
    }
};