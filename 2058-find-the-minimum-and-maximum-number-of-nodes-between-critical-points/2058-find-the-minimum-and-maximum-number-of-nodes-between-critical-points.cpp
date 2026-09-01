class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //the starting index where we found the critical node we will get max dist by using this by sub the last node found with this first found node
        int currIndex = 1;
        int firstcriticalIndex = 0;
        int lastcriticalIndex = 0;
        int mindist = INT_MAX;
        int maxdist = INT_MIN;
        ListNode* curr = head;
        ListNode* prev = NULL;
        bool found = false;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            //checking if it is a critical point or not and this is the first time i am finding the critical node
            if((prev != NULL) && (nextNode != NULL) &&
           ((curr->val < prev->val) && (curr->val < nextNode->val) || 
            (curr->val > prev->val) && (curr->val > nextNode->val))){
                if(found == false)
                {
                    //then this is the first critical node we found
                    firstcriticalIndex = currIndex;
                    lastcriticalIndex = currIndex;
                    found = true;
                }
                else
                {
                    //if it is not the firstCritical node then we can keep on calculating
                    //the mindist by doing the currCriticalnode  - lastfoundCriticalNode
                    mindist = min(mindist,currIndex - lastcriticalIndex);
                    lastcriticalIndex = currIndex;
                }
            }

            currIndex++;
            prev = curr;
            curr = nextNode;
        }
        
        if(mindist != INT_MAX){
            //by doing the last critical section - the first critical node we found we 
            //will get the maxxdist
            maxdist = max(maxdist,lastcriticalIndex - firstcriticalIndex);
        }

        if(mindist != INT_MAX && maxdist != INT_MIN){
            return {mindist,maxdist};
        }

        return {-1,-1};
    }
};