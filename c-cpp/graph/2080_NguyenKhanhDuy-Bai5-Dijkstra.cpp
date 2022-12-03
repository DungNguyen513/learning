#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100
#define VOCUC 1000

struct GRAPH {
	int soDinh;
	int a[MAX][MAX];
};

int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];

int DocMaTranKe(char tenfile[], GRAPH &g) {
	// doc file
	FILE* f;
	f = fopen(tenfile, "rt");
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

void XuatMaTranKe(GRAPH g) {
	printf("So dinh cua do thi la %d\n", g.soDinh);
	
	printf("Ma tran ke cua do thi la:\n");
	for (int i = 0; i < g.soDinh; i++) {
		printf("\t");
		for (int j = 0; j < g.soDinh; j++) {
			printf("%d ", g.a[i][j]);
		}
		printf("\n");
	}
}

int TimDuongDiNhoNhat(GRAPH g) {
	int li = -1;
	float p = VOCUC;
	for (int i = 0; i < g.soDinh; i++) {
		if (ChuaXet[i] == 0 & DoDaiDuongDiToi[i] < p) {
			p = DoDaiDuongDiToi[i];
			li = i;
		}
	}
	return li;
}

int CapNhatDuongDi(int u, GRAPH g) {
	ChuaXet[u] = 1;
	for (int v = 0; v < g.soDinh; v++) {
		if (ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC)
			if (DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v]) {
				DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
				LuuVet[v] = u;
			}
	}
}

void Dijkstra(int S, int F, GRAPH g) {
	int i;
	for (i = 0; i < g.soDinh; i++) {
		ChuaXet[i] = 0;
		DoDaiDuongDiToi[i] = VOCUC;
		LuuVet[i] = -1;
	}
	DoDaiDuongDiToi[S] = 0;
	
	while (ChuaXet[F] == 0) {
		int u = TimDuongDiNhoNhat(g);
		if (u == -1) break;
		CapNhatDuongDi(u, g);
	}
	
	if (ChuaXet[F] == 1) {
		printf("\nDuong di ngan nhat tu dinh %d den dinh %d la: \n\t", S, F);
		i = F;
		printf("%d", F);
		while (LuuVet[i] != S) {
			printf(" <- %d", LuuVet[i]);
			i = LuuVet[i];
		}
		printf(" <- %d\n", LuuVet[i]);
		printf("\tVoi do dai la %d\n", DoDaiDuongDiToi[F]);
	} else {
		printf("\nKhong co duong di tu dinh %d den dinh %d\n", S, F);
	}
}

int main() {
	GRAPH g;
	
	char filepath[] = "./Test1_01.txt";
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de tien hanh thuat toan Dijkstra...\n");
		
		getch();
		
		int S, F;
		printf("Nhap dinh bat dau S: "); scanf("%d", &S);
		printf("Nhap dinh ket thuc F: "); scanf("%d", &F);
		
		Dijkstra(S, F, g);
	}
	
	getch();
}
