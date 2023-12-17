#ifndef AVL_H
#define AVL_H
class AVL {
	struct Node {
		int key;
		Node* left;
		Node* right;
		Node(int k) : key(k), left{}, right{} {}
	};
private:
	int BF(Node*);
	int height(Node*);

	Node* rotateLeft(Node*);
	Node* rotateRight(Node*);
	Node* rotateLeftRight(Node*);
	Node* rotateRightLeft(Node*);

	Node* insert(Node* node, int);

	void inorderTraverse(Node*);
 
private:
	Node* root;
public:
	AVL() : root() {}
	void insert(int);
	void inorderTraverse();
};
#endif //AVL_H
