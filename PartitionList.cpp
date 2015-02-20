/*
	Lintcode: Unique path.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com
	
	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

	You should preserve the original relative order of the nodes in each of the two partitions.

	For example,
	Given 1->4->3->2->5->2->null and x = 3,
	return 1->2->2->4->3->5->null.
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode leftdummy(-1), *left = &leftdummy;
        ListNode rightdummy(-1), *right =&rightdummy;
        ListNode *cur = head;
        while(cur){
            if(cur->val < x){
                left->next = cur;
                left = left->next;
            }
            else{
                right->next = cur;
                right = right->next;
            }
            cur = cur->next;
        }
        left->next = rightdummy.next;
        right->next=NULL;
        return leftdummy.next;
    }
};



