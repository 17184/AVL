
#include <iostream>
#include "AVL.h"

//private helpers
int AVL::BF(Node* node) {
	if(!node) {
		return 0;
	}
	int lH = (node -> left != nullptr) ? height(node -> left) : -1;
	int rH = (node -> right != nullptr) ? height(node -> right) : -1;
	return lH - rH;
}

int AVL::height(Node* root) {
	if(!root) {
		return 0;
	}
	return std::max(height(root -> left), height(root -> right)) + 1;
}


AVL::Node* AVL::rotateLeft(Node* z) {
	Node* y = z -> right;
	Node* yLeft = y -> left;
	
	y -> left = z;
	z -> right = yLeft;	

	return y;
}

AVL::Node* AVL::rotateRight(Node* z) {
	Node* y = z -> left;
	Node* yRight = y -> right;
	
	y -> right = z;
	z -> left = yRight;

	return y;
}
AVL::Node* AVL::rotateLeftRight(Node* z) {
	z -> left = rotateLeft(z -> left);
	return rotateRight(z);
}
AVL::Node* AVL::rotateRightLeft(Node* z) {
	z -> right = rotateRight(z -> right);
	return rotateLeft(z);
}

AVL::Node* AVL::insert(Node* node, int k) {
	if(!node) {
		return new Node(k);
	}
	if(k < node -> key) {
		node -> left = insert(node -> left, k);
	}
	else if(k > node -> key) {
		node -> right = insert(node -> right, k);
	}
	else {
		return node;
	}

	int bf = BF(node);

	if(bf > 1) {
	// ll - case
		if(k < node -> left -> key){	
			return rotateRight(node);
		}
		 else if(k > node -> left -> key) {
		//lr case
		 return rotateLeftRight(node);
		}
	}
	//Right side
	if (bf < -1) {
            // Right-Right Case
            if (k > node -> right->key) {
                return rotateLeft(node);
            }
            // Right-Left Case
            else if (k < node->right->key) {
                return rotateRightLeft(node);
            }
        }

        return node;

}


void AVL::inorderTraverse(Node * node) {
	if(node) {
		inorderTraverse(node -> left);
		std::cout << node -> key << " " ;
	inorderTraverse(node -> right);
	}
}

//public
void AVL::insert(int k) {
	root = insert(root, k);
}	
void AVL::inorderTraverse() {
	inorderTraverse(root);
}

int main()
{
	AVL t;
	int val[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
	int size = sizeof(val) / sizeof(val[0]);

	for(int i {}; i < size; ++i) {
		t.insert(val[i]);
	}

	std::cout << "AVl Tree - ";
	t.inorderTraverse();
}

