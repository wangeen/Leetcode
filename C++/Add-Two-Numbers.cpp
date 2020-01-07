/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 特别注意最后的进位，这时候需要新建一个node
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        bool inc = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + inc;
            l1->val = sum % 10;
            if(sum/10){
                inc = 1;
            }else{
                inc = 0;
            }
            if(l1->next == 0){
                if(l2->next == 0 && inc){
                    l1->next = new ListNode(1);
                    return res;
                }
                l1->next = l2->next;
                l1 = l1->next;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + inc;
            l1->val = sum % 10;
            if(sum/10){
                inc = 1;
                if(l1->next == 0){
                    l1->next = new ListNode(1);
                    return res;
                }
            }else{
                inc = 0;
                break;
            }
            l1 = l1->next;
        }
        if(inc){
            l1->next = new ListNode(1);
        }
        return res;
    }
};





