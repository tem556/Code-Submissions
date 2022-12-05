#include <limits>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Go through the first element in each list and get smallest
        ListNode* res = nullptr; // dummy
        bool remain = true;

        int currMin = std::numeric_limits<int>::max();
        int minIndex = -1;
        ListNode* least = nullptr;  

        for (int i = 0; i < lists.size(); ++i) {
            ListNode* l = lists[i];
            if (l != nullptr) {
                remain = true;
                if (l -> val <= currMin) {
                    currMin = l -> val;
                    least = l;
                    minIndex = i;
                }
            }
        }

        if (least == nullptr) return nullptr; // if empty

        ListNode* temp = least -> next;
        least -> next = res;
        res = least;
        lists[minIndex] = temp;
        ListNode* first = res;

        while (remain) {
            remain = false;
            int currMin = std::numeric_limits<int>::max();
            int minIndex = -1;
            ListNode* least = nullptr; 
            for (int i = 0; i < lists.size(); ++i) {
                ListNode* l = lists[i];
                if (l != nullptr) {
                    remain = true;
                    if (l -> val <= currMin) {
                        currMin = l -> val;
                        least = l;
                        minIndex = i;
                    }
                }
            }
            if (least == nullptr) return first;
            ListNode* temp = least -> next;
            res -> next = least;
            res = res -> next;
            lists[minIndex] = temp;
        }
        return first;
    }
};
