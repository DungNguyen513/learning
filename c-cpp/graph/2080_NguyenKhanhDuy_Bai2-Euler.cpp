
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

void khoiTaoStack(STACK &stack) {
	stack.size = 0;
}

void DayGiaTriVaoStack(STACK &stack, int value) {
	if (stack.size + 1 >= MAX)
		return;

	stack.arr[stack.size] = value;
	stack.size++;
}

void TimDuongDi(int i, GRAPH &g, STACK &stack) {
	for (int j = 0; j < g.soDinh; j++) {
		if (g.a[i][j] != 0) {
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j, g, stack);
		}
	}
	DayGiaTriVaoStack(stack, i);
}

int KiemTraChuTrinhEuler(GRAPH g) {
	int i, j;
	int x = 0;
	int s = 0;
	
	for (i = 0; i < g.soDinh; i++) {
		for (j = 0; j < g.soDinh; j++) {
			if (g.a[i][j] != 0) {
				x = i;
				s = 1;
				break;
			}
		}
		
		if (s == 1)
			break;
	}
	
	GRAPH temp = g;
	
	STACK stack;
	khoiTaoStack(stack);
	TimDuongDi(x, temp, stack);
	
	for (i = 0; i < temp.soDinh; i++) {
		for (j = 0; j < temp.soDinh; j++) {
			if (temp.a[i][j] != 0)
				return 0;
		}
	}
	
	if (stack.arr[stack.size - 1] != stack.arr[0])
		return 0;
	
	printf("\nChu trinh Euler: ");
	for (i = stack.size - 1; i >= 0; i--) {
		printf("%d", stack.arr[i] + i);
	}
	
	return 1;
}

//int KiemTraDuongDiEuler(GRAPH g) {
//	int i, j;
//	int x = 0;
//	
//	GRAPH temp = g;
//	
//	STACK stack;
//	khoiTaoStack(stack);
//	TimDuongDi(x, temp, stack);
//	
//	printf("Duong di Euler: ");
//	return 1;
//}

int main() {
	GRAPH g;
	
	char filepath[] = "./Test1_01.txt";
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de bat dau xet tim chu trinh euler...\n");
		
		getch();
		
		if (!KiemTraChuTrinhEuler(g)) {
			printf("Khong co chu trinh Euler trong do thi cua ban!\n");
//			printf("\nBam 1 phim bat ki de bat dau xet tim duong di euler...\n");
			
			getch();
			
//			if (!KiemTraDuongDiEuler(g)) {
//				printf("Khong co duong di Euler trong do thi cua ban!\n");
//				getch();
//			}
		}
	}
	
	getch();
}

