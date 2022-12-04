#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define MAXSTACK 1000
#define VOCUC 1000
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
int docmatranke(char tenfile[100],DOTHI &g){
	FILE*f;
	f=fopen(tenfile,"rt");
	if(f==NULL){
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void xuatmatranke(DOTHI g){
	printf("So dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi la \n");
	for(int i=0;i<g.n;i++){
		printf("\t");
		for(int j=0;j<g.n;j++){
			printf("%d",g.a[i][j]);
		}
		printf("\n");
	}
}
int kiemtramatrankehople(DOTHI g){
	for(int i=0;i<g.n;i++){
		if(g.a[i][i]!=0)
			return 0;
	}
	return 1;
}
int kiemtradothivohuong(DOTHI g){
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			if(g.a[i][j]!=g.a[j][i])
			return 0;
		}
	}
	return 1;
}
void ditimcacdinhlienthong(DOTHI g,int nhan[MAX],int i){
	for(int j=0;j<g.n;j++){
		if(g.a[i][j]!=0&&nhan[j]!=nhan[i]){
			nhan[j]=nhan[i];
			ditimcacdinhlienthong(g,nhan,j);
		}
	}
}
void xetlienthong(DOTHI g){
	int nhan[MAX];
	for(int i=0;i<g.n;i++)
		nhan[i]=0;
	int sotplt=0;
	for(int i=0;i<g.n;i++){
		if(nhan[i]==0){
			sotplt++;
			nhan[i]=sotplt;
			ditimcacdinhlienthong(g,nhan,i);
		}
	}
	printf("So thanh phan lien thong la %d\n",sotplt);
	for(int tplt=1;tplt<=sotplt;tplt++){
		printf("Thanh phan lien thong thu %d gom cac dinh:",sotplt);
		for(int j=0;j<g.n;j++){
			if(nhan[j]==tplt)
				printf("%d,",j);
		}
		printf("\n");
	}	
}
struct STACK{
	int array[100];
	int size;
};
void khoitaostack(STACK &stack){
	stack.size=0;
}
void daygiatrivaostack(STACK &stack,int value){
	if(stack.size+1>=100)
		return;
	stack.array[stack.size]=value;
	stack.size++;
}
void timduongdi(int i,DOTHI &g,STACK &stack){
	for(int j=0;j<g.n;j++){
		if(g.a[i][j]!=0){
			g.a[i][j]=g.a[j][i]=0;
			timduongdi(j,g,stack);
		}
	}
	daygiatrivaostack(stack,i);
}
int ktchutrinheuler(DOTHI g){
	int x=0,flag=0;
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			if(g.a[i][j]!=0){
				x=i;
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	DOTHI temp=g;
	STACK stack;
	khoitaostack(stack);
	timduongdi(x,temp,stack);
}
int sau_nut[MAX][MAX];
int L[MAX][MAX];
void floyd(DOTHI g){
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			if(g.a[i][j]>0){
				sau_nut[i][j]=j;
				L[i][j]=g.a[i][j];
			}
			else{
				sau_nut[i][j]=-1;
				L[i][j]=VOCUC;
			}
		}
	}
	for(int k=0;k<g.n;k++){
		for(int i=0;i<g.n;i++){
			for(int j=0;j<g.n;j++){
				if(L[i][j]>L[i][k]+L[k][j]){
					L[i][j]=L[i][k]+L[k][j];
					sau_nut[i][j]=sau_nut[i][k];
				}
			}
		}
	}
	int S,F;
	printf("Nhap vao dinh bat dau: ");
	scanf("%d",&S);
	printf("Nhap vao dinh ket thuc: ");
	scanf("%d",&F);
	if(sau_nut[S][F]==-1){
		printf("Khong co duong di tu dinh %d den dinh %d la: \n",S,F);
	}
	else{
		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n",S,F);
		printf("\t%d",S);
		int u=S;
		while(sau_nut[u][F]!=F){
			u=sau_nut[u][F];
			printf("-->%d",u);
		}
		printf("-->%d",F);
		printf("\n\tVoi tong trong so la %d",L[S][F]);
	}
}
int main(){
	DOTHI g;
	if(docmatranke("D:\\test2.txt",g)==1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		xuatmatranke(g);
		if(kiemtramatrankehople(g)==1)
			printf("Do thi hop le.\n");
		else
			printf("Do thi khong hop le.\n");
		if(kiemtradothivohuong(g)==1)
			printf("Do thi vo huong.\n");
		else
			printf("Do thi co huong.\n");
		xetlienthong(g);
		if(!ktchutrinheuler(g)){
			printf("Khong co chu trinh Euler trong do thi cua ban\n");
		}
		floyd(g);
	}
}
