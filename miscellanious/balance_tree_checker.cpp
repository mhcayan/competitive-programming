#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
	node(int d) {
		data = d;
	}
};

node* create_tree(vector<int> v) {
	queue<node*> ss;
	node *source = new node(v[0]);
	ss.push(source);
	for(int i = 1; i < v.size(); i++) {
		while(!ss.empty()) {
			node *cur = ss.front();
			printf("cur = %d\n", cur->data);
			if(cur->left == NULL) {
				printf("yes left null\n");
				node *dd = new node(v[i]);
				cur->left = dd;
				ss.push(cur->left);
				break;
			} else if(cur->right == NULL) {
				printf("yes right null\n");
				node *dd = new node(v[i]);
				cur->right = dd;
				ss.push(cur->right);
				break;
			} else {
				ss.pop();
			}
		}
	}
	printf("source = %d\n", source->data);
	printf("left = %d\n", (source->left)->data);
	printf("right = %d\n", (source->right)->data);
	return source;
}

void print_tree(node *cur) {
	
	if(cur == NULL) {
		return;
	}
	
	print_tree(cur->left);
	printf("%d\n", cur->data);
	print_tree(cur->right);
	printf("hoho\n");
}

int main() {
	vector<int> v;
	int num_of_nodes;
	int data;
	while(scanf("%d", &num_of_nodes) == 1) {
		
		for(int i = 0; i < num_of_nodes; i++) {
			v.push_back(i+1);
		}
		node *s = create_tree(v);
//		printf("%d\n", s->left->data);
		print_tree(s);
	}
	
	return 0;
}
