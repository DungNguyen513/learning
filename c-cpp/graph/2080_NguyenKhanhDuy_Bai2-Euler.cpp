#include<stdio.h>
#include<conio.h>
#define inputfile "D:/test3.txt"
#define max 100
typedef struct dt{
	int n;
	int arr[max][max];
}DOTHI;

struct STACK{
	int a[100];
	int size;
};
int DocMaTranKe(char TenFile[100],DOTHI &g)
{
	FILE*f;
	f = fopen(TenFile, "rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}

void XuatMaTranKe(DOTHI g){
	printf("So dinh cua do thi la : %d\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i=0;i<g.n;i++){
		printf("\t");
		for(int j=0 ;j<g.n;j++){
			printf("%d ",g.arr[i][j]);
		}
		printf("\n");
	}
	
}


void KTStack(STACK &stack){
	stack.size=0;
}
void DayGiaTriVaoStack(STACK &stack,int value){
	if(stack.size +1 >=100)
		return ;
	stack.a[stack.size]=value;
	stack.size++;
}
void timduongdi(int i,DOTHI &g,STACK &stack){
	for(int j=0;j<g.n;j++){
		if(g.arr[i][j]=g.arr[j][i]!=0){
			g.arr[i][j]=g.arr[j][i]=0;
			timduongdi(j,g,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
int kiemtraEuler(DOTHI g){
	int i,j;
	int x=0;
	int s=0;
	// tim 1 dinh x
	for (i = 0; i < g.n; i++) { 
		for (j = 0; j < g.n; j++) {
			if (g.arr[i][j] != 0){
				x = i;
				s = 1;
				break;
			}
		}
		if(s==1)
		break;
	}
	//
	DOTHI temp = g;
	STACK stack;
	KTStack(stack);
	timduongdi(x,temp, stack);
	//kt 
	for (i = 0; i < temp.n; i++){ 
		for (j = 0; j < temp.n; j++){ 
			if (temp.arr[i][j] != 0) 
			return 0;
		} 
	}
	if (stack.a[stack.size - 1] != stack.a[0])
		return 0; 
		
	printf("\nChu trinh Euler: ");	
	for(i = stack.size - 1; i >= 0 ; i--) 
		printf("%d ",stack.a[i] + 1); 
	return 1;
}

int kiemtra_duongdiEuler(DOTHI g){
	int i,j;
	int x=0;
	int s=0;
	// tim 1 dinh x
	for (i = 0; i < g.n; i++) { 
		for (j = 0; j < g.n; j++) {
			if (g.arr[i][j] %2 !=0){
				x = i;
				s = 1;
				break;
			}
		}
		if(s==1)
		break;
	}
	DOTHI temp = g;
	STACK stack;
	KTStack(stack);
	timduongdi(x,temp, stack);
	for (i = 0; i < temp.n; i++){ 
		for (j = 0; j < temp.n; j++){ 
			if (temp.arr[i][j] != 0) 
			return 0;
		} 
	}
	if (stack.a[stack.size - 1] == stack.a[0])
		return 0; 
	printf("\nduong di Euler: ");	
	for(i = stack.size - 1; i >= 0 ; i--) 
		printf("%d ",stack.a[i] + 1); 
	return 1;
}
int main(){
	DOTHI g;
	if(DocMaTranKe(inputfile,g)==1){
		printf("da lay thong tin tu do thi thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("\n tim chu trinh euler ... -> enter");
		getch();
		if(!kiemtraEuler(g)){
			printf("\n kh co chu trinh euler trong do thi");
			printf("\n tim duoi di euler ... -> enter");
			getch();
			if(!kiemtra_duongdiEuler(g))
				printf("\n kh co duong di euler trong do thi cua ban");
		}
	}
	getch();
}

