#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100
#define VOCUC 1000

struct GRAPH {
	int soDinh;
	int a[MAX][MAX];
};

int Sau_Nut[MAX][MAX];
int L[MAX][MAX];

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

void Floyd(GRAPH g) {
	int i, j;
	for (i = 0; i < g.soDinh; i++) {
		for (j = 0; j < g.soDinh; j++) {
			if (g.a[i][j] > 0) {
				Sau_Nut[i][j] = j;
				L[i][j] = g.a[i][j];
			} else {
				Sau_Nut[i][j] = -1;
				L[i][j] = VOCUC;
			}
		}
	}
	
	for (int k = 0; k < g.soDinh; k++) {
		for (i = 0; i < g.soDinh; i++) {
			for (j = 0; j < g.soDinh; j++) {
				if (L[i][j] > L[i][k] + L[k][j]) {
					L[i][j] = L[i][k] + L[k][j];
					Sau_Nut[i][j] = Sau_Nut[i][k];
				}
			}
		}
	}
	
	int S, F;
	printf("Nhap dinh bat dau S: "); scanf("%d", &S);
	printf("Nhap dinh ket thuc F: "); scanf("%d", &F);
	if (Sau_Nut[S][F] == -1) {
		printf("Khong co duong di tu dinh %d den dinh %d la: \n", S, F);
	} else {
		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n", S, F);
		printf("\t%d", S);
		int u = S;
		while (Sau_Nut[u][F] != F) {
			u = Sau_Nut[u][F];
			printf(" --> %d", u);
		}
		printf(" --> %d", F);
		printf("\n\tVoi tong trong so la: %d", L[S][F]);
	}
}

int main() {
	GRAPH g;
	
	char filepath[] = "./Test1_01.txt";
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de tien hanh thuat toan Floyd...\n");
		
		getch();
		
		Floyd(g);
	}
	
	getch();
}
