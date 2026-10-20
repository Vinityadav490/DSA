class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len<=2) return {-1,-1};
        temp=head->next;
        ListNode*temp1=head;
        len=2;
        vector<int>dist;
        while(temp->next!=NULL){
            if(temp->val>temp1->val&&temp->val>temp->next->val){
              dist.push_back(len);
            }
            else if(temp->val<temp1->val&&temp->val<temp->next->val){
                dist.push_back(len);
            }
            temp1=temp;
            temp=temp->next;
            len++;
        }
        if(dist.size()<=1) return {-1,-1};
        int mx=dist[dist.size()-1]-dist[0];
        int mn=INT_MAX;
        for(int i=1; i<dist.size(); i++){
            if(dist[i]-dist[i-1]<mn) mn=dist[i]-dist[i-1];
        }
        return {mn,mx};
    }
};