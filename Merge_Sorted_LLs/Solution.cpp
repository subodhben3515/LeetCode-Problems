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

        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if(list1 == nullptr && list2 != nullptr)
            return list2;
        else if(list1 != nullptr && list2 == nullptr)
            return list1;

        ListNode* mergedList = new ListNode(-1);
        ListNode* mergedHead = mergedList;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list2->val == list1->val)
            {
                //cout << "equal\n" ;
                mergedList->next = new ListNode(list2->val, new ListNode(list2->val));

                list1 = list1->next;
                list2 = list2->next;
            }
            else if(list2->val < list1->val)
            {
                //cout << "less\n";
                mergedList->next = new ListNode(list2->val);

                list2 = list2->next;
            }
            else if(list1->val < list2->val)
            {
                //cout << "less else, comparing with l2Val: " << list2->val << "\n";
                mergedList->next = new ListNode(list1->val);

                list1 = list1->next;                
            }

            if(mergedHead == nullptr)
                mergedHead = mergedList;
                        
            while(mergedList->next != nullptr)
                mergedList = mergedList->next;
                //cout << "list at val: " << mergedList->val << " next: " << mergedList->next << "\n";

        }

         while(list1 != nullptr)
         {
             mergedList->next  = new ListNode(list1->val);
                          mergedList = mergedList->next;

             list1 = list1->next;                
         }
 
          while(list2 != nullptr)
         {
            //cout << "Merging remaining menbers of list2, val: " << list2->val << "\n";
             mergedList->next  = new ListNode(list2->val);
             mergedList = mergedList->next;
             list2 = list2->next;                
         }

        return mergedHead->next;
    }
};

// Optimized

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

        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if(list1 == nullptr && list2 != nullptr)
            return list2;
        else if(list1 != nullptr && list2 == nullptr)
            return list1;

        ListNode* mergedList = new ListNode(-1);
        ListNode* mergedHead = mergedList;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list2->val <= list1->val)
            {
                mergedList->next = list2;
                list2 = list2->next;
            }
            else if(list2->val > list1->val)
            {
                mergedList->next = list1;
                list1 = list1->next;
            }
                mergedList = mergedList->next;

        }

         if(list1 != nullptr)
         {
             mergedList->next  = list1;
         }
         else if(list2 != nullptr)
         {
             mergedList->next  = list2;
         }

        return mergedHead->next;
    }
};
