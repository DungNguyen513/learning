#include<stdio.h>

struct Node {
	int info;
	Node *pNext;
};

Node *pHead;

void Init(Node *pHead) {
	pHead = NULL;
}

int IsEmpty(Node *pHead) {
	return (pHead == NULL);
}

Node *CreateNode(int x) {
	Node *p = new Node;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void InsertFirst(Node *&pHead, int x) { 
	Node *p = CreateNode(x);
	if (IsEmpty(pHead) == 1)
		pHead = p;
	else {
		p->pNext = pHead;
		pHead = p;
	}
}

void NhapN(int &n) {
	printf("\nNhap so luong phan tu: ");
	scanf("%d", &n);
}

void nhap(Node *&pHead) {
	int x;
	printf("Nhap x: ", x);
	scanf("%d", &x);
	InsertFirst(pHead, x);
}

void ThemSoNguyen(Node *&pHead,int &x) {
	printf("\nNhap so muon them: ");
	scanf("%d", &x);
	InsertFirst(pHead, x);
}

void Print(Node *pHead) {
	if (IsEmpty(pHead) == 1)
		printf("Danh sach rong");
	else {
		Node *tmp = pHead;
		while (tmp != NULL) {
			printf("%d\t", tmp->info);
			tmp = tmp->pNext;
		}
	}
}

void InsertAfter(Node *pHead, int x) {
	Node *tmp;
	if (pHead != NULL) {
		tmp = CreateNode(x);
		tmp->pNext = pHead->pNext;
		pHead->pNext = tmp;
	}
}

void DeleteFirst(Node *&pHead) {
	Node *p = pHead;
	pHead = pHead->pNext;
	delete p;
}

Node* search(Node *pHead, int x) {
	Node *p = pHead;
	while (p->info != x && p != NULL)
		p = p->pNext;
	return p;
}

void themPTsau(Node *&pHead, int x, int &m) {
	Node *tmp = search(pHead, x);
	if (tmp == NULL)
		printf("\nKhong tim thay vi tri chen");
	else {
		printf("\nTim thay vi tri");
		printf("\nNhap so can chen: ");
		scanf("%d", &m);
		InsertAfter(tmp, m);
	}
}

int DemNode(Node *phead) {
	Node *p = pHead;
	int dem = 0;
	while (p != NULL) {
		dem++;
		p = p->pNext;
	}
	return dem;
}

Node * TimVT(Node *pHead, int k) {
	Node *tmp = pHead;
	int dem = 0;
	while (tmp != NULL) {
		if (dem == k)
			break;
		dem++;
		tmp = tmp->pNext;
	}
	return tmp;
}

void SearchNode(Node *pHead, int k) {
	Node *p = TimVT(pHead, k);
	if (p == NULL)
		printf("\nVi tri thu '%d' khong ton tai", k);
	else {
		printf("\nVi tri thu '%d' la: %d", k, p->info);
	}
}

int SearchMax(Node *pHead) {
	int max = pHead->info;
	Node *tmp = pHead;
	while (tmp != NULL) {
		if (tmp->info > max)
			max = tmp->info;
		tmp = tmp->pNext;
	}
	return max;
}

int SearchMin(Node *pHead) {
	int min = pHead->info;
	Node *tmp = pHead;
	while (tmp != NULL) {
		if (tmp->info < min)
			min = tmp->info;
		tmp = tmp->pNext;
	}
	return min;
}

Node *PreNode(Node *pHead, Node *p) {
	Node *q;
	if (p == pHead)
		return NULL;
	q = pHead;
	while (q != NULL && q->pNext != p)
		q = q->pNext;
	return q;
	
}

void DeleteNode(Node *pHead, int x) {
	Node *tmp = pHead;
	if (pHead->info == x)
		DeleteFirst(pHead);
	else {
		while (tmp->info != x)
			tmp = tmp->pNext;
	}
	if (tmp->info == x) {
		Node *p = PreNode(pHead, tmp);
		p->pNext = tmp->pNext;
		delete tmp;
	}
}

void sort(Node *pHead) {
	for (Node *p1 = pHead; p1 != NULL; p1 = p1->pNext) {
		for (Node *p2 = p1->pNext; p2 != NULL; p2 = p2->pNext) {
			if (p1->info > p2->info) {
				int tmp = p1->info;
				p1->info = p2->info;
				p2->info = tmp;
			}
		}
	}
}

int main() {
	int chon, x;

	Init(pHead);

	do {
		printf("\n1. Nhap danh sach");
		printf("\n2. In danh sach");
		printf("\n3. Nhap them 1 so nguyen");
		printf("\n4. Dem Node");
		printf("\n5. Tim vi tri");
		printf("\n6. Tim Max, Min");
		printf("\n7. Xoa gia tri");
		printf("\n8. Sap xep");
		printf("\n0. Thoat");
		
		printf("\nChon: "); scanf("%d", &chon);
		
		switch (chon) {
			case 1: {
				nhap(pHead);
				break;
			}
			case 2: {
				Print(pHead);
				break;
			}
			case 3: {
				int m, s;
				printf("\nNhap gia tri tim va them: ");
				scanf("%d %d", &s, &m);
				themPTsau(pHead, s, m);
				break;
			}
			case 4: {
				printf("\nCo %d Node", DemNode(pHead));
				break;
			}
			case 5: {
				int k;
				printf("\nNhap vi tri: ");
				scanf("%d", &k);
				SearchNode(pHead, k);
				break;
			}
			case 6: {
				printf("\nMax: %d", SearchMax(pHead));
				printf("\nMin: %d", SearchMin(pHead));
				break;
			}
			case 7: {
				int k;
				printf("\nNhap gia tri can xoa : ");
				scanf("%d", &k);
				DeleteNode(pHead, k);
				printf("\nXoa thanh cong");
				break;
			}
			case 8: {
				sort(pHead);
				printf("\nDanh sach sau khi sap xep: ");
				Print(pHead);
				break;
			}
			default: chon = 0;
		}
	} while (chon != NULL);
}
