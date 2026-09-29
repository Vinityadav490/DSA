class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode*temp1=head;
        ListNode*temp2=head->next;
        while(temp2!=NULL){
            int n=gcd(temp1->val,temp2->val);
            ListNode*GCD=new ListNode(n);
            temp1->next=GCD;
            GCD->next=temp2;
            temp1=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};