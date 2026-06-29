class Solution{
public:
    bool cycledetect(ListNode* head){
        ListNode* s=head;
        ListNode* f=head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s == f) return true;
        }
        return false;
    }
};