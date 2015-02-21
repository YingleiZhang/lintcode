/*
	Lintcode: Remove duplicate from sorted list.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given a sorted linked list, delete all duplicates such that each element appear only once.

	Example
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next) return head;
        ListNode * prev = head, * cur = head->next;
        while(cur){
            if(prev->val==cur->val){
                ListNode * tmp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete tmp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
        
    }
};
