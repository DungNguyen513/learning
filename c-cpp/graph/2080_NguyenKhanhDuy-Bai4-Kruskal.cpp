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

void kruskal(dothi g) {
	canh E[200],ET[100];
	int nE=0,nET=0;
	for(int i=0;i<g.soDinh-1;i++)
		for(int j=i+1;j<g.soDinh;j++)
			if(g.a[i][j]!=0){
				E[nE].v1=i;
				E[nE].v2=j;
				E[nE].ts=g.a[i][j];
				nE++;
			}
	canh tam;
	for(int i=0;i<nE-1;i++)
		for(int j=i+1;j<nE;j++)
			if(E[i].ts>E[j].ts){
				tam=E[i];
				E[i]=E[j];
				E[j]=tam;
			}
	int nhan[100],giatri;
	for(int i=0;i<g.soDinh;i++)
		nhan[i]=i;
		for(int i=0;i<nE;i++)
			if(nhan[E[i].v1] != nhan[E[i].v2]){
				ET[nET++]=E[i];
				giatri=nhan[E[i].v2];
				for(int k=0;k<g.soDinh;k++)
					if(nhan[k]==giatri)
						nhan[k]=nhan[E[i].v1];
			}
	if(nET==g.soDinh-1){
			printf("\nCay khung co trong so nho nhat: \n");
	}
	else
			printf("\nDo thi khong lien thong: \n\nCac cay khung nho nhat cua cac thanh phan lien thong:\n  ");
	int Tongts=0;

	for(int i=0;i<nET;i++){
		Tongts+=ET[i].ts;
		printf("(%d, %d) ",ET[i].v1,ET[i].v2);
	}
	printf("\nTong trong so: %d", Tongts);
}

int main() {
	dothi g;
	
	// char filepath[] = "test.txt"; // Do thi khong lien thong
	char filepath[] = "test2.txt"; // Do thi lien thong
	
	if (DocMaTranKe(filepath, g) == 1) {
		printf("Da lay thong tin do thi tu file thanh cong!\n\n");
		
		XuatMaTranKe(g);
		
		printf("\nBam 1 phim bat ki de tien hanh thuat toan Kruskal...\n");
		
		getch();
		
		kruskal(g);
	}
}

