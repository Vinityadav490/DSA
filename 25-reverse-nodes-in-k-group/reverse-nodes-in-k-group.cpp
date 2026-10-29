class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        int groups=len/k;
        ListNode*prev=NULL;
        temp=head;
        ListNode*front=head;
        ListNode*newHead=NULL;
        ListNode*gt=NULL;
        while(groups>0){
            ListNode*gs=temp;
            prev=NULL;
            for(int i=0; i<k; i++){
                front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            if(newHead==NULL) newHead=prev;
            if(gt!=NULL) gt->next=prev;
            gt=gs;
            groups--;
        }
        gt->next=temp;
        return newHead;
    }
};