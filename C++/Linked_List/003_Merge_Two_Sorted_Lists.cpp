// Merge Two Sorted Lists


/*

https://leetcode.com/problems/merge-two-sorted-lists/

*/




// Iterative



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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode * finalHead = NULL;
        if(list1->val < list2->val){
            finalHead = list1;
            list1 = list1->next;
        }else{
            finalHead = list2;
            list2 = list2->next;
        }
        
        ListNode * tail = finalHead;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
                //tail = list1;
            }else{
                tail->next = list2;
                list2 = list2->next;
                //tail = list2;
            }
            tail = tail->next;
        }
        if(list1){
            tail->next = list1;
        }else{
            tail->next = list2;
        }
        return finalHead;
    }
};






// Using recursion


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode * newHead = NULL;
        if(list1->val < list2->val){
            newHead = list1;
            newHead->next = mergeTwoLists(list1->next, list2);
        }else{
            newHead = list2;
            newHead->next = mergeTwoLists(list1, list2->next);
        }
        return newHead;
    }
};




