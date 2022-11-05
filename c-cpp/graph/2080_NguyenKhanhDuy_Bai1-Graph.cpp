#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100
#define inputfile "D:/test2.txt"

struct GRAPH {
	int soDinh;
	int a[MAX][MAX];
};

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

int KiemTraMaTranKeHopLe(GRAPH g) {
	for (int i = 0; i < g.soDinh; i++) {
		if (g.a[i][i] != 0)
			return 0;
	}
	
	return 1;
}

int KiemTraDoThiVoHuong(GRAPH g) {
	for (int i = 0; i < g.soDinh; i++) {
		for (int j = 0; j < g.soDinh; j++) {
			if (g.a[i][j] != g.a[j][i])
				return 0;
		}
	}
	
	return 1;
}

void DiTimCacDinhLienThong(GRAPH g, int nhan[], int i) {
	for (int j = 0; j < g.soDinh; j++) {
		if (g.a[i][j] != 0 && nhan[j] != nhan[i]) {
			nhan[j] = nhan[i];
			DiTimCacDinhLienThong(g, nhan, j);
		}
	}
}

void XetLienThong(GRAPH g) {
	int Nhan[MAX];
	int i;
	for (i = 0; i < g.soDinh; i++)
		Nhan[i] = 0;
		
	int SoThanhPhanLT = 0;
	for (i = 0; i < g.soDinh; i++) {
		if (Nhan[i] == 0) {
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g, Nhan, i);
		}
	}
	
	printf("So thanh phan lien thong la %d\n", SoThanhPhanLT);
	
	for (i = 1; i <= SoThanhPhanLT; i++) {
		printf("Thanh phan lien thong thu %d gom cac dinh ", i);
		for (int j = 0; j < g.soDinh; j++) {
			if (Nhan[j] == i) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
}

int main() {
	GRAPH g;
	
	if (DocMaTranKe(inputfile, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de tien hanh kiem tra do thi...\n");
		
		getch();
		
		if (KiemTraMaTranKeHopLe(g) == 1)
			printf("Do thi hop le!\n");
		else
			printf("Do thi KHONG hop le!\n");
		
		if (KiemTraDoThiVoHuong(g) == 1)
			printf("Do thi vo huong!\n");
		else
			printf("Do thi KHONG vo huong!\n");
		
		printf("\nBam 1 phim bat ki de bat dau xet tinh lien thong cua do thi...\n");
		
		getch();
		
		XetLienThong(g);
	}
	
	getch();
}
