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

pTree CreateNode(int x) {
	Node *p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void NhapMang(int M[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Node thu %d: ", i+1);
		scanf("%d", &M[i]);
	}
}

void XuatMang(int M[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", M[i]);
	}
}

void Insert(pTree &root, int x) {
	if (IsEmpty(root) == 1)
		root = CreateNode(x);
	else {
		if(x == root->info)
			return;
		if(x < root->info)
			Insert(root->left, x);
		else
			Insert(root->right, x);
	}
}

void NhapMangVaoCay(pTree &root, int M[], int n) {
	for (int i = 0; i < n; i++) {
		Insert(root, M[i]);
	}
}

void NLR(pTree root) {
	if (root != NULL) {
		printf("%d\t", root->info);
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(pTree root) {
	if (root != NULL) {
		LNR(root->left);
		printf("%d\t", root->info);
		LNR(root->right);
	}
}

void LRN(pTree root){
	if (root != NULL) {
		LRN(root->left);
		LRN(root->right);
		printf("%d\t", root->info);
	}
}

int demNode(pTree root) {
	if (root != NULL) {
		return (1 + demNode(root->left) + demNode(root->right));
	}
	return 0;
}

bool leaf(pTree root) {
	return (root->left == NULL && root->right == NULL);
}

int demLeaf(pTree root) {
	if (root == NULL)
		return 0;
	if (leaf(root) == true) return 1;
	return (demLeaf(root->left) + demLeaf(root->right));
}

int main() {
	pTree root;

	Init(root);

	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int M[n];
	NhapMang(M,n);
	XuatMang(M,n);

	printf("\n\nDang nhap du lieu vao cay...");
	NhapMangVaoCay(root,M,n);

	printf("\n\nNLR: "); NLR(root);
	printf("\nLNR: "); LNR(root);
	printf("\nLRN: "); LRN(root);

	printf("\n\nCo %d node con", demNode(root));
	printf("\nCo %d node la", demLeaf(root));
}
