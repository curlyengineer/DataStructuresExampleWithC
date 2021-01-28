#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Stack{
	//top indisi -1 iken yýðýn boþtur 
	int top ;
	//Kapasite belirleme
	unsigned capacity;
	int* array;
};
//Yýðýn yaratma fonksiyonu
struct Stack* createStack(unsigned capacity){
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	if(!stack)
	return NULL;
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc (stack->capacity*sizeof(int));
	 if(!stack->array)
	 return NULL;
	return stack;
}
//Dizi baþ kontrolü
int isEmpty(struct Stack* stack){
	return stack->top==-1;
}
//Yýðýn top deðer gösterme
char peek(struct Stack* stack){
	return stack->array[stack->top];
}
//yýðýndan eleman alma fonksiyonu
char pop (struct Stack* stack){
	if(!isEmpty(stack))
	return stack->array[stack->top--];
	return '$';
}
//Yýðýna eleman ekleme fonksiyonu
void push(struct Stack* stack, char op){
	stack->array[++stack->top]=op;
}

//Eleman operand mý?
int isOperand(char ch){
	return (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
}
//+ - öncelik kontrolü
int Prec(char ch){
	switch(ch){
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		return 2;
		case '^':
		return 3;
	}
	return -1;
}
//Ana fonksiyon
int infixToPostfix(char* exp){
	int i,k;
	struct Stack* stack=createStack(strlen(exp));
	if(!stack)
	return -1;
	for(i=0,k=-1;exp[i];++i)
	{
	if(isOperand(exp[i]))
	exp[++k]=exp[i];
	else
	if(exp[i]=='(')
	push(stack,exp[i]);
	else
	if(exp[i]==')')
	{
		while(!isEmpty(stack)&&peek(stack)!='(')
		exp[++k]=pop(stack);
		if(!isEmpty(stack)&&peek(stack)!='(')
		return -1;
		else 
		pop(stack);
	}
	else
	{
		while(!isEmpty(stack)&&Prec(exp[i])<=Prec(peek(stack)))
		exp[++k]=pop(stack);
		push(stack,exp[i]);
	}
}
while (!isEmpty(stack))
exp[++k]=pop(stack);
exp[++k]='\0';
printf("%s\n",exp);
}

int main(int argc, char *argv[]) {
	char exp[]="H+F*(R^E*G)/(A-B)";
	infixToPostfix(exp);
	return 0;
}
