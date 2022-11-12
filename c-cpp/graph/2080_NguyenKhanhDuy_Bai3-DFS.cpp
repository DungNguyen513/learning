
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100

struct STACK {
	int arr[MAX];
	int size;
};

struct GRAPH {
	int soDinh;
	int a[MAX][MAX];
};

int LuuVet[MAX];
int ChuaXet[MAX];

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

void DFS(int v, GRAPH g){
	ChuaXet[v] = 1;
	int u;
	for(u = 0; u < g.soDinh; u++){
		if(g.a[v][u] != 0 && ChuaXet[u] == 0){
			LuuVet[u] = v;
			DFS(u, g);
		}
	}
}

void duyettheoDFS(int S, int F, GRAPH g){
	int i;
	
	DFS(S, g);
	if(ChuaXet[F] == 1){
		printf("Duong di tu dinh %d den dinh %d la: \n\t", S, F);
		i = F;
		printf("%d", F);
	}
	else{
		printf("Khong co duong di tu dinh %d den dinh %d \n", S, F);
	}
}

int main() {
	GRAPH g;
	
	char filepath[] = "./Test1_01.txt";
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de bat dau duyet theo DFS...\n");
		
		getch();
		
		duyettheoDFS(0, 2, g);
	}
	
	getch();
}

