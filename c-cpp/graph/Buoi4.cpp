#include<stdio.h>
#include<stdlib.h>
int daduyet[100];
struct dothi{
	int soDinh;
	int a[100][100];
};
struct canh{
	int v1,v2,ts;
};
void docfile(dothi &g)
{
	char tenfile[18];
	printf("Nhap ten file: ");scanf("%s",&tenfile);
	FILE *f=fopen(tenfile,"rt");
	if (f==NULL)
	{
		printf("k mo dc file!!!");
		return;
	}
	fscanf(f,"%d",&g.soDinh);
	for (int i=0;i<g.soDinh;i++ )
		for (int j=0;j<g.soDinh;j++)
			fscanf(f,"%d",&g.a[i][j]);
			
	fclose(f);
}
void xuatMTK(dothi g)
{
	printf("%4d\n",g.soDinh);
	for (int i=0;i<g.soDinh;i++ )
	{
		for (int j=0;j<g.soDinh;j++)
			printf("%4d",g.a[i][j]);
			
		printf("\n");
	}
}
void DFS(int S,dothi g){
	daduyet[S]=1;
	for(int i=0;i<g.soDinh;i++)
		if(daduyet[i]==0 && g.a[S][i]!=0)
			DFS(i,g);
}

int timSTPLT(dothi g){
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
void prim(dothi g){
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
		ET[nET++]=canhMin;//dua canh min vao ET
		VT[canhMin.v2]=1;//dua dinh thu 2 cua canh do vao VT
	}
	int tongts=0;
	printf("\nPRIM-cay khung co trong so nho nhat: \n");
	for(int i=0;i<nET;i++){
		tongts+=ET[i].ts;
		printf("\t(%d,%d)= %d\n",ET[i].v1,ET[i].v2,ET[i].ts);
	}
	printf("\nPrim tong trong so: %d",tongts);
}
void kruskal(dothi g){
	canh E[200],ET[100];//E la tap hop cac canh cua do thi;ET la tap hop cac canh cua cay khung
	int nE=0,nET=0; //nE la so canh cua do thi(so phan tu cua E);nET la so canh cua cay khung
	//doc cac canh cua E
	for(int i=0;i<g.soDinh-1;i++)
		for(int j=i+1;j<g.soDinh;j++)
			if(g.a[i][j]!=0){
				E[nE].v1=i;
				E[nE].v2=j;
				E[nE].ts=g.a[i][j];
				nE++;
			}
	//sap xep theo trong so tang dan
	canh tam;
	for(int i=0;i<nE-1;i++)
		for(int j=i+1;j<nE;j++)
			if(E[i].ts>E[j].ts){
				tam=E[i];
				E[i]=E[j];
				E[j]=tam;
			}
			//kruskal
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
			printf("\nKruskal-cay khung co trong so nho nhat: \n");
	}
	else
			printf("\nKruskal-Do thi khong LT: \n\nRung gom cac cay khung nho nhat cua cac thanh phan lien thong:\n  ");
	int Tongts=0;

	for(int i=0;i<nET;i++){
		Tongts+=ET[i].ts;
		printf("\t(%d,%d)= %d\n",ET[i].v1,ET[i].v2,ET[i].ts);
	}
	printf("\nPrim tong trong so: %d",Tongts);
}
int main(){
	dothi g;
	docfile(g);
	xuatMTK(g);
	prim(g);
	kruskal(g);
}
