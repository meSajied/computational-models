#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* doubleIt(ListNode*);

int main() {
  ListNode* node = new ListNode(0);
  ListNode* head = node;

  doubleIt(head);
  
  return 0;
}

ListNode* doubleIt(ListNode* node) {
  int num = 0;

  while(node) {
    num += node->val;
    ListNode* tmp = node;

    if(node->next) {
      num *= 10;
      node = node->next;
      delete(tmp);
    }else {
      break;
    }
  }

  num *= 2;

  int tmp = 0;
  stack<int> st;

  while(num >= 0) {
    tmp = num%10;
    num -= tmp;
    num /= 10;

    st.push(tmp);
  }

  ListNode* dummy = new ListNode(0);
  ListNode* temp = dummy;
  ListNode* head;

  while(!st.empty()) {
    dummy->next = new ListNode(st.top());
    st.pop();
    dummy = dummy->next;
  }

  head = temp->next;

  delete(temp);

  return head;
}
