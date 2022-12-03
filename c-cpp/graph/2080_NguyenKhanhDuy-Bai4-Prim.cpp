#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100

int daduyet[MAX];

struct dothi {
	int soDinh;
	int a[MAX][MAX];
};

struct canh {
	int v1, v2, ts;
};

int DocMaTranKe(char tenfile[], dothi &g) {
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

void XuatMaTranKe(dothi g) {
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

void DFS(int S,dothi g) {
	daduyet[S]=1;
	for(int i=0;i<g.soDinh;i++)
		if(daduyet[i]==0 && g.a[S][i]!=0)
			DFS(i,g);
}

int timSTPLT(dothi g) {
	for(int i=0;i<100;i++)
		daduyet[i]=0;
	int soTPLT=0;
	for(int i=0;i<g.soDinh;i++)
		if(daduyet[i]==0){
			soTPLT++;
			DFS(i,g);
		}
	return soTPLT;
}

void prim(dothi g) {
	if(timSTPLT(g)!=1){
		printf("\nDo thi khong lien thong!!");
		return;
	}
	int VT[100]={0};
	canh ET[100];
	int nET=0;
	VT[0]=1;
	int min;
	canh canhMin;
	while(nET<g.soDinh-1){
		min=1000;
		for(int i=0;i<g.soDinh;i++)
			if(VT[i]==1)
				for(int j=0;j<g.soDinh;j++)
					if(VT[j]==0 && g.a[i][j]!=0 && g.a[i][j]<min){
						canhMin.v1=i;
						canhMin.v2=j;
						canhMin.ts=g.a[i][j];
						min=g.a[i][j];
					}
		ET[nET++]=canhMin;
		VT[canhMin.v2]=1;
	}
	int tongts=0;
	printf("\nCay khung co trong so nho nhat: \n");
	for(int i=0;i<nET;i++){
		tongts+=ET[i].ts;
		printf("(%d, %d) ",ET[i].v1,ET[i].v2);
	}
	printf("\nTong trong so: %d", tongts);
}

int main() {
	dothi g;
	
	// char filepath[] = "test.txt"; // Do thi khong lien thong
	char filepath[] = "test2.txt"; // Do thi lien thong
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de tien hanh thuat toan Prim...\n");
		
		getch();
		
		prim(g);
	}
}

