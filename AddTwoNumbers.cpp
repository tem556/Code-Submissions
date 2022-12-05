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
#include <cmath>



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        int current_l1 = l1 -> val;
        int current_l2 = l2 -> val; 
        int curr_result = current_l1 + current_l2;
        int carry = curr_result / 10;
            
        ListNode* list_result = new ListNode(curr_result%10);
        ListNode* end_list = list_result;
        
        l1 = l1 -> next;
        l2 = l2 -> next;
        
        while (l1 != NULL && l2 != NULL){
            int current_l1 = l1 -> val;
            int current_l2 = l2 -> val; 
            int curr_result = current_l1 + current_l2 + carry;
            carry = curr_result / 10;
            
            ListNode* newNode = new ListNode(curr_result%10);
            end_list -> next = newNode;
            end_list = end_list -> next;  
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while (l1 != NULL){
            int current_l1 = l1 -> val;
            int curr_result = current_l1 + carry;
            carry = curr_result / 10;
            
            ListNode* newNode = new ListNode(curr_result%10);
            end_list -> next = newNode;
            end_list = end_list -> next;
            l1 = l1 -> next;
        }
        
        while (l2 != NULL){
            int current_l2 = l2 -> val; 
            int curr_result = current_l2 + carry;
            carry = curr_result / 10;
            
            ListNode* newNode = new ListNode(curr_result%10);
            end_list -> next = newNode;
            end_list = end_list -> next;
             
            l2 = l2 -> next;
        }
        
        if (carry != 0){
            ListNode* newNode = new ListNode(carry);
            end_list->next = newNode;
        }
        
        
        return list_result;
    }
};
