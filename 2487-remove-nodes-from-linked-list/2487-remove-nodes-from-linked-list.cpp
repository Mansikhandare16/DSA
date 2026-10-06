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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*> st;

        while(temp!=NULL){
            while(!st.empty() && st.top()->val < temp->val){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        } 

        vector<ListNode*> arr;

        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin(),arr.end());

        for(int i=0;i<arr.size()-1;i++){
            arr[i]->next=arr[i+1];
            arr.back()->next=NULL;
        }
        return arr[0];
    }
};