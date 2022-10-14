#include<stdio.h>
#include<string.h>

struct Node {
	int info;
	Node *left;
	Node *right;
};

typedef Node* pTree;

void Init(pTree &root) {
	root = NULL;
}

int IsEmpty(pTree &root) {
	return (root == NULL);
}

pTree CreateNode(int x){
	Node *p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Insert(pTree &root, int x) {
	if (IsEmpty(root) == 1)
		root = CreateNode(x);
	else{
		if (x == root->info)
			return;
		if (x < root->info)
			Insert(root->left, x);
		else
			Insert(root->right, x);
	}
}

void NLR(pTree root) {
	if (root != NULL) {
		printf("%d ", root->info);
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(pTree root) {
	if (root != NULL) {
		LNR(root->left);
		printf("%d ", root->info);
		LNR(root->right);
	}
}

void LRN(pTree root){
	if (root != NULL) {
		LRN(root->left);
		LRN(root->right);
		printf("%d ", root->info);
	}
}

int Remove(pTree &root,int x) {
	if (root == NULL)
		return false;
	if (root->info > x)
		return Remove(root->left, x);
	if (root->info<x)
		return Remove(root->right, x);
	if (root->info == x) {
		pTree p, f, rp;
		p = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else {
			f = p;
			rp = p->right;
			while (rp->left != NULL) {
				f = rp;
				rp = rp->left;
			}
			p->info = rp->info;
			if (f == p)
				f->right = rp->right;
			else
				f->left = rp->right;
			p = rp;
		}
		delete p;
	}
	
	return true;
}

int main() {
	pTree root;

	Init(root);

	int n,chon;
	do {
		printf("\n1. Nhap 1 node vao cay");
		printf("\n2. Xoa 1 node co gia tri");
		printf("\n3. Xuat cac gia tri theo: NLR, LNR, LRN");
		
		printf("\nChon: "); scanf("%d", &chon);

		switch (chon) {
			case 1: {
				int x;
				printf("Nhap x: ");
				scanf("%d", &x);
				Insert(root, x);
				break;
			}
			case 2:{
				int x;
				printf("Nhap gia tri can xoa: ");
				scanf("%d", &x);
				Remove(root, x);
				break;
			}
			case 3:{
				printf("\nNLR: "); NLR(root);
				printf("\nLNR: "); LNR(root);
				printf("\nLRN: "); LRN(root);
				break;
			}
			default: chon = 0;
		}
	} while(chon != NULL);
}
