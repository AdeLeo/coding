/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        struct ListNode *tmp = head;
        //if(p->next == NULL)
        //	return p;

       	vector<int> v;

        stack<struct ListNode *> s;
        while(tmp != NULL)
        {
        	s.push(tmp);
        	tmp = tmp->next;
        }

        while(!s.empty())
        {
        	tmp = s.pop();
        	v.push_back(tmp->val);
        	//cout << tmp->val << endl;
        }


/*
        struct ListNode *q = p->next;
        struct ListNode *tmp;
        for(p = head, q = p->next; q != NULL; )
        {
        	tmp = q->next;
        	q->next = p;
        	p = q;
        	q = tmp;
        }
        head->next = NULL;
        return p;
*/
    }

    return v;
};