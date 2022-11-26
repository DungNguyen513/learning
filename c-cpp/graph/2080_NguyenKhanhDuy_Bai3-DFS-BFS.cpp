#include<stdio.h>

#define MAX 100

int daDuyet[MAX], thuTuDuyet[MAX], nTTD = 0;

void khoiTao() {
	nTTD = 0;
	for (int i = 0; i < 100; i++) {
		daDuyet[i] = 0;
	}
}

struct DOTHI {
	int soDinh;
	int a[MAX][MAX];
};

int DocMaTranKe(DOTHI &g) {
	// doc file
	FILE* f;
	f = fopen("./Test1_01.txt", "rt");
	if (f == NULL) {
		printf("Khong mo duoc file!\n");
		return 0;
	}
	
	fscanf(f, "%d", &g.soDinh);
	
	int i, j;
	for (i = 0; i < g.soDinh; i++) {
		for (j = 0; j < g.soDinh; j++) {
			fscanf(f, "%d", &g.a[i][j]);
		}
	}
	
	fclose(f);
	
	return 1;
}

void lietKeThuTuDuyet() {
	for (int i = 0; i < nTTD; i++)
		printf("%d ", thuTuDuyet[i]);
}

void DFS(int S, DOTHI g) {
	daDuyet[S] = 1;
	thuTuDuyet[nTTD++] = S;
	for (int i = 0; i < g.soDinh; i++) {
		if (g.a[S][i] != 0 && daDuyet[i] == 0) {
			daDuyet[i] = 1;
			DFS(i, g);
		}
	}
}

int lay1PTTuHangDoi(int Q[], int &nQ) {
	int U = Q[0];
	for (int i = 0; i < nQ - 1; i++)
		Q[i] = Q[i+1];
	nQ--;
	return U;
}

void BFS(int S, DOTHI g) {
	int Q[MAX], nQ = 0;
	daDuyet[S] = 1;
	thuTuDuyet[nTTD++] = S;
	Q[nQ++] = S;
	int U;
	while (nQ != 0) {
		U = lay1PTTuHangDoi(Q, nQ);
		for (int i = 0; i < g.soDinh; i++) {
			if (g.a[U][i] != 0 && daDuyet[i] == 0) {
				daDuyet[i] = 1;
				thuTuDuyet[nTTD++] = i;
				Q[nQ++] = i;
			}
		}
	}
}

int main() {
	DOTHI g;
	DocMaTranKe(g);
	int S;
	printf("Nhap vao dinh xuat phat: "); scanf("%d", &S);
	
	khoiTao();
	DFS(S, g);
	printf("DFS: ");
	lietKeThuTuDuyet();
	
	khoiTao();
	BFS(S, g);
	printf("\nBFS: ");
	lietKeThuTuDuyet();
}

