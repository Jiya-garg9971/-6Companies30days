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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
       
        ListNode* n=new ListNode(0);
        n->next=head;
        head=n;
         ListNode* temp=head;
        int sum=0;
        
        while(temp!=NULL){
            sum+=temp->val;
            cout<<sum<<" ";
            if(mp.count(sum)){
               // cout<<sum<<" ";                
                ListNode* t=mp[sum]->next;
                int a=sum+t->val;
                while(a!=sum){                  
                    mp.erase(a);
                    t=t->next;
                    a+=t->val;
                }
                mp[sum]->next=temp->next;
                temp=temp->next;
            }
            else{
                mp[sum]=temp;
                temp=temp->next;
            }
          //  temp=temp->next;
        }
        if(sum==0)return NULL;
        return head->next;
    }
};
