/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/* O(1) in time for max_value, pop_front; O(N) in time for push_back with O(1) on average; O(N) in space */
#define NULL 0

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};
struct Node_P{
    Node* val;
    Node_P* next;
    Node_P* prev;
    Node_P(Node* x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MaxQueue {
private:
    Node *head, *tail;
    Node_P *head_p, *tail_p;
public:
    MaxQueue() {
        head = NULL;
        tail = NULL;
        head_p = NULL;
        tail_p = NULL;
    }

    ~MaxQueue() {
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        while(head_p){
            Node_P* temp_p = head_p;
            head_p = head_p->next;
            delete temp_p;
        }
    }

    int max_value() {
        if(head_p) return head_p->val->val;
        return -1;
    }

    void push_back(int value) {
        if(head){
            tail->next = new Node(value);
            tail->next->prev = tail;
            tail = tail->next;

            while(tail_p&&(tail_p->val->val<=value)){
                Node_P* temp_p = tail_p;
                tail_p = tail_p->prev;
                if(tail_p) tail_p->next = NULL;
                delete temp_p;
            }
            if(tail_p){
                tail_p->next = new Node_P(tail);
                tail_p->next->prev = tail_p;
                tail_p = tail_p->next;
            }
            else{
                tail_p = new Node_P(tail);
                head_p = tail_p;
            }
        }
        else{
            head = new Node(value);
            head_p = new Node_P(head);
            tail = head;
            tail_p = head_p;
        }
    }

    int pop_front() {
        if(head){
            if(head==head_p->val){
                Node_P* temp_p = head_p;
                head_p = head_p->next;
                if(head_p)  head_p->prev = NULL;
                else tail_p = NULL;
                delete temp_p;
            }
            int res = head->val;
            Node* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            else tail = NULL;
            delete temp;
            return res;
        }
        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
