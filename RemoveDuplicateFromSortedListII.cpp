/*
	Lintcode: Remove duplicate from sorted list II.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

	Example
	Given 1->2->3->3->4->4->5, return 1->2->5.
	Given 1->1->1->2->3, return 2->3.
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head||!head->next) return NULL;
        ListNode * cur = head;
        ListNode dummy(-1), *prev = &dummy;
        while(cur){
            if(cur->next&&cur->val == cur->next->val){
                while(cur->next&&cur->val == cur->next->val){
                    ListNode * tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
            }
            else{
                prev->next = cur;
                prev = prev->next;
            }
            cur = cur->next;
        }
        prev->next = NULL;
        return dummy.next;
    }
};
