#include<stdio.h>
#include<conio.h>
#define MAX 100
#define VOCUC 1000
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
struct STACK
{
	int a[100];
	int size;
};
int docmatranke(char Tenfile[100],DOTHI &g)
{
	FILE*f;
	f=fopen(Tenfile,"rt");
	if(f==NULL)
	{
		printf("khong mo duoc file \n ");
		return 0;
		
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void xuatmatranke(DOTHI g)
{
	printf("so dinh cua do thi la: %d\n", g.n);
	printf("ma tran ke cua do thi la \n");
	for( int i=0; i<g.n;i++)
	{
		printf("\t");
		for(int j=0; j<g.n;j++)
		{
			printf("%4d",g.a[i][j]);
		}
		printf("\n");
	}
}
int kiemtramatranhople(DOTHI g)
{
	int i,j;
	for(i=0;i<g.n;i++)
	
		if(g.a[i][j]!=0)
		return 0;
	
	return 1;
}
int kiemtradothivohuong(DOTHI g)
{
	int i,j;
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			if(g.a[i][j]!=g.a[j][i])
			return 0;
		}
	}
	return 1;
}
void timcacdinhlienthong(DOTHI g,int nhan[MAX],int i)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0 && nhan[j]!=nhan[i])
		{
			nhan[j]=nhan[i];
			timcacdinhlienthong(g,nhan,j);
		}
	}
}
int xetlienthong(DOTHI g)
{
	int nhan[MAX];
	int i;
	for(i=0;i<g.n;i++)
	
		nhan[i]=0;
		int sothanhphanlt = 0;
	
	for(int i=0;i<g.n;i++)
	{
		if(nhan[i]==0)
		{
			sothanhphanlt++;
			nhan[i]=sothanhphanlt;
			timcacdinhlienthong(g,nhan,i);
		}
	}
	printf("so thanh phan lien thong la: %d\n",sothanhphanlt);
	for(int i=1;i<=sothanhphanlt;i++)
	{
		printf("thanh phan lien thong thu %d gom cac dinh: \n",i);
		for(int j=0;j<g.n;j++)
		{
			if(nhan[j]==i)
			printf("%3d",j);
		}
		
	}
	if (sothanhphanlt==1)
		return 1;
		else
		return 0;
	
}
// tim duong nho nhat 
int luuvet[MAX];
int chuaxet[MAX];
int dodaiduongditoi[MAX];


int timduongdinhonhat(DOTHI g)
{
	int li=-1;
	float p=VOCUC;
	for(int i=0;i<g.n;i++)
	{
		if(chuaxet[i]==0 && dodaiduongditoi[i]<p)
		{
			p=dodaiduongditoi[i];
			li=i;
		}
	}
	return li;
}
void capnhatduongdi(int u, DOTHI g)
{
	chuaxet[u]=1;
	for(int v=0;v<g.n;v++)
	{
		if(chuaxet[v]==0 && g.a[u][v]>0 && g.a[u][v]<VOCUC)
		
			if(dodaiduongditoi[v]>dodaiduongditoi[u]+g.a[u][v])
		{
			dodaiduongditoi[v]=dodaiduongditoi[u]+g.a[u][v];
			luuvet[v]=u;
		}
	}
}
void dijkstra(int s,int f, DOTHI g)
{
	int i;
	for(int i=0;i<g.n;i++)
	{
		chuaxet[i]=0;
		dodaiduongditoi[i]=VOCUC;
		luuvet[i]=-1;
	}
	dodaiduongditoi[s]=0;
	while(chuaxet[f]==0)
	{
		int u=timduongdinhonhat(g);
		if(u==-1)break;
		capnhatduongdi(u,g);
	}
	if (chuaxet[f]==1)
	{
		printf("\n duong di ngan nhat tu dinh %d den dinh %d la: \n\t",s,f);
		i=f;
		printf("%d",f);
		while(luuvet[i]!=s)
		{
			printf("<-%d", luuvet[i]);
			i=luuvet[i];
		}
		printf("<-%d\n",luuvet[i]);
		printf("\t voi do dai la: %d\n ",dodaiduongditoi[f]);
	}
	else
	{
		printf("khong co duong di tu dinh %d den dinh %d\n",s,f);
	}
}
// euler
void khoitaostack(STACK &stack)
{
	stack.size=0;
}
void daygiatrivaostack(STACK &stack, int value)
{
	if(stack.size+1>=100)

	return;
	stack.a[stack.size]=value;
	stack.size++;
}
void timduongdi(int i, DOTHI &g,STACK &stack)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0)
		{
			g.a[i][j]=g.a[j][i]=0;
			timduongdi(j,g,stack);
		}
	}
	daygiatrivaostack(stack,i);
}
int kiemtrachutrinheuler(DOTHI 	g)
{
	int i,j;
	int x=0;
	DOTHI tam=g;
	STACK stack;
	khoitaostack(stack);
	timduongdi(x,tam,stack);
	printf("\n chu trinh euler: ");
	return 1;
}
int main()
{
	DOTHI g;

	
	if(docmatranke("D:\\LTDT\\test3.txt",g)==1)
	{
		printf("da lay thong tin do thi tu file thanh cong: \n\n");
			xuatmatranke(g);
			
			if(kiemtramatranhople(g)==1)
			printf("do thi hop le.\n");
			else
			printf("do thi vo huong.\n");
			if (kiemtradothivohuong(g)==1)
			printf("do thi vo huong .\n");
			else
			printf("do thi co huong.\n");
			
	}
	xetlienthong(g);
	dijkstra(1,2,g);
	
	
	
}
