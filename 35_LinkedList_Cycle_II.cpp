BruteForce-------------->>>>>>>>
    Time -------------->>>> O(N)
    Space ------------->>>> O(N)


        #include<bits/stdc++.h>
        Node *firstNode(Node *head)
        {   
            Node *dummy = head;
            map<Node*,int>mpp;
            while(dummy != NULL)
            {
                if(mpp.count(dummy))
                {
                    return dummy;
                }
                else
                {
                    mpp[dummy]++;
                }
                dummy = dummy -> next;
            }
            return NULL;
        }



Optimal --------------------->>>>>
    Time -------------->>>> O(N)
    Space ---------------->>>> O(1)


        Node *firstNode(Node *head)
        {
            if(head == NULL || head -> next == NULL) return NULL;   
            
            Node *slow = head;
            Node *fast = head;
            
            while(slow != NULL && fast != NULL && fast-> next != NULL)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
                if(fast == slow) break;
            }
            
            Node *entry = head;
            while(entry != NULL && slow != NULL )
            {
                if(slow == entry) return entry;
                slow = slow-> next;
                entry = entry -> next;
            }
            return NULL;
        }
