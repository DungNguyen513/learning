#include<stdio.h>
#include<stdlib.h>

int DaDuyet[100], DinhTruoc[100];
int ThuTuDuyet[100],nTTD=0;

void KhoiTao_DaDuyet_DinhTruoc(){ //gan 0 cho tat ca DaDuyet 
	for(int i=0; i<100;i++){
		DaDuyet[i]=0;
		DinhTruoc[i]=-1;
	}
}

struct DT{
	int soDinh;
	int a[100][100];
};

void docFile(DT &l){
	char tenfile[18];
	printf("Moi nhap ten file muon mo: ");
	scanf("%s",&tenfile);

	FILE* f= fopen(tenfile,"rt");
	if(f==NULL){
		printf("\nKo mo duoc file!");
	}
	fscanf(f,"%d",&l.soDinh);
	for(int i=0; i<l.soDinh; i++){
		for(int j=0; j<l.soDinh; j++){
			fscanf(f,"%d",&l.a[i][j]);
		}
	}
	fclose(f);
}

void xuatFile(DT l){
	printf("So dinh: %4d\n",l.soDinh);
	for(int i=0; i<l.soDinh; i++){
		for(int j=0; j<l.soDinh; j++){
			printf("%4d",l.a[i][j]);
		}
	printf("\n");
	}
}

void DFS(int S, DT l){	//S: start
	DaDuyet[S]=1; // danh dau dinh S da duyet
	ThuTuDuyet[nTTD++]=S;
	for(int i=0; i<100; i++)
	 if(l.a[S][i] !=0 && DaDuyet[i]==0){
	 	DaDuyet[i]=1; // danh dau i da duyet 
	 	DinhTruoc[i]=S; // dinh truoc dinh i la S
		DFS(i,l);
	 }
}

void LKThuTuDuyet(){
	for(int i=0; i<nTTD; i++)
		printf("%4d",ThuTuDuyet[i]);
}

int Lay1PhanTuTuQUEUE(int Q[],int &nQ){
	int U=Q[0];
	for(int i=0; i<nQ-1; i++)	
		Q[i]=Q[i+1];
	nQ--;
	return U;
}

void BFS(int S, DT l){
	KhoiTao_DaDuyet_DinhTruoc();	
	int Q[100],nQ=0; // khai bao va doi tao QUEUE: hang doi
	DaDuyet[S]=1;
	nTTD=0;  //danh dau S da duyet
	ThuTuDuyet[nTTD++]=S;
	Q[nQ++]=S;	//bo S vao Q va tang so phan tu Q
	int U; // khai bao bien de chua dinh lay tu QUEUE
	while(nQ>0){
		U=Lay1PhanTuTuQUEUE(Q,nQ);	// loi goi ham lay 1 phan tu tu QUEUE	
		for(int i=0; i<l.soDinh; i++)
			if(l.a[U][i] !=0 && DaDuyet[i]==0){
				Q[nQ++]=i;
				DaDuyet[i]=1;
				DinhTruoc[i]=U; // dinh truoc cua i la U
				ThuTuDuyet[nTTD++]=i;
			}
	}
}

int TimSoTPLT(DT l){
	KhoiTao_DaDuyet_DinhTruoc();
	int SoTPLT=0;
	for(int i=0; i<l.soDinh; i++)
		if(DaDuyet[i]==0){
			SoTPLT++;
			DFS(i,l); // dung DFS hoac BFS
		}
	return SoTPLT;
}

void XuatDuongDi(int S, int F){
	int i=F;
	printf("\n%3d",F);
	while(i!=S){
		i=DinhTruoc[i];
		printf(" <-- %d",i);
	}
}

void TimDuongDi(int S, int F, DT l){ // S: start, F: finish
	// tim duong di theo DFS	
	KhoiTao_DaDuyet_DinhTruoc();
	DFS(S,l);
	if(DaDuyet[F]==0){
		printf("\nKhong duong di tu %d den %d theo DFS: ",S,F);
		return;
	}
	XuatDuongDi(S,F);	// loi goi ham
	
	//tim duong di theo BFS
	BFS(S,l);
	printf("\nKhong duong di tu %d den %d theo BFS: ",S,F);
	XuatDuongDi(S,F);
}
int main(){
	DT l;
	docFile(l);
	xuatFile(l);	
	int S,F,c;
	
/*	printf("\nMoi nhap dinh S: ");
	scanf("%d",&S);
*/

	KhoiTao_DaDuyet_DinhTruoc();
	
/*	DFS(S,l);
	printf("\nThu tu duyet theo thuat toan DFS: ");
	LKThuTuDuyet();
	
	BFS(S,l);
	printf("\nThu tu duyet theo thuat toan BFS: ");
	LKThuTuDuyet();
	
	printf("\nSo TPLT cua do DT: %d",TimSoTPLT(l));
	
	printf("\nMoi nhap dinh xuat phat: ");
	scanf("%d",&S);	
	printf("\nMoi nhap dinh ket thuc: ");
	scanf("%d",&F);
	TimDuongDi(S,F,l);
*/
	do{
	printf("\n\n***---------------MENU-------------***");
	printf("\n-Lua chon 1: Duyet do thi theo DFS");
	printf("\n-Lua chon 2: Duyet do thi theo BFS");
	printf("\n-Lua chon 3: Tim So TPLT theo DFS va BFS");
	printf("\n-Lua chon 4: Tim duong di tu 1 dinh den dinh tu chon theo DFS va BFS");
	printf("\n\nMoi nhap lua chon: ");
	scanf("%d",&c);
	switch(c)
		{
			case 1:
				printf("\nMoi nhap dinh S: ");
				scanf("%d",&S);
				KhoiTao_DaDuyet_DinhTruoc();
				DFS(S,l);
				printf("\nThu tu duyet theo thuat toan DFS: ");
				LKThuTuDuyet();
				break;
	
			case 2:
				printf("\nMoi nhap dinh S: ");
				scanf("%d",&S);
				KhoiTao_DaDuyet_DinhTruoc();
				BFS(S,l);
				printf("\nThu tu duyet theo thuat toan BFS: ");
				LKThuTuDuyet();
				break;
			case 3:
				printf("\nSo TPLT cua do DT: %d",TimSoTPLT(l));	
				break;
			case 4:
				printf("\nMoi nhap dinh xuat phat: ");
				scanf("%d",&S);	
				printf("\nMoi nhap dinh ket thuc: ");
				scanf("%d",&F);
				TimDuongDi(S,F,l);	
				break;
			default:
				printf("\nKhong co lua chon ban nhap. Moi nhap lai!!");
		}
		//printf("\nNhan phim bat ky de tiep tuc!! ");
		//fflush(stdin);
		getchar();
	}while(c!=0);
}
