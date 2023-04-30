#include <iostream>
using namespace std;

struct Node {
	int v;
	Node *next;
};

int n, m;

int main() {
	cin >> n >> m;
	Node *head = NULL, *tail = NULL;
	for (int i = 1; i <= n; ++i) {
		Node *node = new Node;
		node->v = i;
		tail->next = node;
		if (i == 1)
			head = node;
		tail = node;
	}
	tail->next = head;
	
	
}
