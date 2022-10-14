#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MaxStack 100

struct stack {
	int top;
	float nodes[MaxStack];
};

void Init(stack &s) {
	s.top = -1;
}

int Isempty(stack &s) {
	return(s.top == -1);
}

int IsFull(stack s) {
	return(s.top == MaxStack - 1);
}

void Push(stack &S, float item) {
	if (S.top == (MaxStack - 1)) {
		printf("\nStack is full");
	} else {
		S.top = S.top + 1;
		S.nodes[S.top] = item;
	}
}

float Pop(stack &S) {
	float ret = -1;
	if (S.top == -1)
		printf("\nStack is empty");
	else {
		ret = S.nodes[S.top];
		S.top = S.top-1;
	}
	return ret;
}

int top(stack S) {
	return (S.nodes[S.top]);
}

int Precedence(char x) {
	if(x == '(') return 0;
	if(x == '+' || x == '-') return 1;
	if(x == '*' || x== '/' || x == '%')	return 2;
	return 3;
}

void InfixtoPostfix(char infix[], char postfix[]) {
	stack S;
	char x, token;
	int i = 0, j = 0;
	Init(S);
	for (i = 0; infix[i] != '\0'; i++) {
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else
			if (token == '(')
				Push(S,'(');
			else{
				if (token == ')')
					while ((x = Pop(S)) != '(')
						postfix[j++] = x;
				else {
					while (Precedence(token) <= Precedence(top(S)) && !Isempty(S)) {
						x = Pop(S);
						postfix[j++] = x;
					}
					Push(S,token);
				}
			}
	}

	while (!Isempty(S)) {
		x = Pop(S);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}

char operation(int a, int b, char d){
	float so;
	switch(d){
		case '+': so=a+b; break;
		case '-': so=a-b; break;
		case '*': so=a*b; break;
		case '/': so=a/b; break;
	}
	return int(so)+'0';
}

float Value_hauto(char *Postfix){
	char d;
	int n,a,b;
	char result ;
	char *p;
	p=&Postfix[0];
	n=strlen(Postfix);
	stack s;
	Init(s);
	for(int i=0;i<n;i++){
		d=Postfix[i];
		if(isdigit(d))
			Push(s,d);
		else{
			b=Pop(s)-'0';
			a=Pop(s)-'0';
			result =operation(a,b,d);
			Push(s,result);
		}
	}
	return Pop(s)-'0';
}

int main(){
	char A[MaxStack],B[MaxStack];
	printf("Nhap bieu thuc trung to: ");
	gets(A);
	InfixtoPostfix(A, B);
	printf("\nHau to: %s", B);
	printf("\nGia tri hau to: %.2f", Value_hauto(B));
}
