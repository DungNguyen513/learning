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

void NhapMang(int M[],int n) {
	for (int i = 0; i < n; i++) {
		printf("Node thu %d: ", i+1);
		scanf("%d", &M[i]);
	}
}

void XuatMang(int M[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", M[i]);
	}
}

void Insert(pTree &root,int x) {
	if(IsEmpty(root) == 1)
		root = CreateNode(x);
	else{
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

void LNR(pTree root) {
	if (root != NULL) {
		LNR(root->left);
		printf("%d ", root->info);
		LNR(root->right);
	}
}

void RNL(pTree root) {
	if (root != NULL) {
		RNL(root->right);
		printf("%d ", root->info);
		RNL(root->left);
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

int  checkBST_True(pTree root) {
	int tong = demNode(root);
	int l = demLeaf(root);
	return (tong == (2*l)-1);
}

int max(int a, int b){
	return a > b ? a : b;
}

int height(pTree root) {
	if (root == NULL)
		return 0;
	else
		return (1 + max(height(root->left), height(root->right)));
}

pTree SearchFather(pTree root, int x) {
	pTree p = root;
	pTree tmp = NULL;
	while (p != NULL) {
		if(p->info == x)
			return tmp;
		tmp = p;
		if(p->info > x)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}

int SearchMin(pTree root) {
	if (root->left == NULL)
		return root->info;
	else
		return SearchMin(root->left);
}

int SearchMax(pTree root) {
	if (root->right == NULL)
		return root->info;
	else
		return SearchMax(root->right);
}

int demGiua(pTree root) {
	return (demNode(root) - 1 - demLeaf(root));
}

int sum(pTree root) {
	if (root != NULL) {
		int a = sum(root->left);
		int b = sum(root->right);
		return (root->info + a + b);
	}
	return 0;
}

int main() {
	pTree root;

	Init(root);

	int n, x;
	printf("Nhap so luong phan tu: "); scanf("%d", &n);
	int M[n];

	NhapMang(M, n);
	XuatMang(M, n);

	printf("\n\nDang nhap du lieu vao cay...");
	NhapMangVaoCay(root, M, n);

	printf("\n\nDanh sach giam dan: "); RNL(root);
	printf("\nDanh sach tang dan: "); LNR(root);

  	int s = checkBST_True(root);
  	if(s == 1)
  		printf("\n\nDay la cay nhi phan");
  	else
  		printf("\n\nDay khong phai cay nhi phan");
	
	printf("\n\nNhap gia tri node can tim: ");
	scanf("%d", &x);
	pTree tmp = SearchFather(root, x);
	printf("Nut cha cua '%d' la: %d", x, tmp->info);

	printf("\n\nCo %d la tren cay", demLeaf(root));
	printf("\nCo %d nut giua cay", demGiua(root));
	printf("\nKich thuoc cua cay: %d", demNode(root));

  	printf("\n\nChieu cao cua cay: %d", height(root));

	printf("\nMax: %d", SearchMax(root));
	printf("\nMin: %d", SearchMin(root));

	printf("\n\nTong cua cay: %d", sum(root));
}
