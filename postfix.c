/*
 * postfix.c
 *
 *  2020 Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return '\0';
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}


void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}


/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}

}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
char PostfixPeek(){
	//스텍 top의 원소의 우선순위 반환 비어있을시 -1
	if(postfixStackTop == -1)
		return -1;
	return getPriority(postfixStack[postfixStackTop]);
}

void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;//infix:받아온 문자열
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */
	char op;

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0')
	{
		//우선순위 저장
		x=getPriority(*exp);

		//숫자 일경우
		if(x == operand){
			charCat(exp);
		}

		//'('일경우
		else if(x==lparen)
			postfixPush(*exp);

		//')'일 경우
		else if(x==rparen){
			//'('가 나올때 까지 스택에 있는 연사자를 이음
			for(op=postfixPop();op!='(';op=postfixPop()){
				charCat(&op);
			}
		}

		//스택 가장위에 있는 연산자의 우선순위가 현재보다 낮을경우 스택에 넣음
		else if(PostfixPeek()<x){
			postfixPush(*exp);
		}

		//스택 가장위에 있는 연산자의 우선순위가 현재보다 높을 경우 '('나 스택이 끝날때 까지 이음
		else{
			for(op=postfixPop();op!='(' && op!='\0';op=postfixPop()){
				charCat(&op);
			}
			postfixPush(*exp);
		}
		exp++;
	}
	//남은 연산자를 전부 이음
	for(op=postfixPop();op!='\0';op=postfixPop()){
		charCat(&op);
	}
}

void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	int num1, num2;

	//끝까지
	for(int i=0;postfixExp[i]!='\0';i++){

		//숫자일시 int형으로 변환하여 스텍에 저장
		if(getPriority(postfixExp[i])==operand)
			evalPush(postfixExp[i]-'0');

		//연산자일 경우 그에 맞춰서 저장
		else{
			num2=evalPop();
			num1=evalPop();

			switch(postfixExp[i]){
			case '+' : evalPush(num1+num2); break;
			case '-' : evalPush(num1-num2); break;
			case '/' : evalPush(num1/num2); break;
			case '*' : evalPush(num1*num2); break;
			}
		}
	}
	//결과를 입력
	evalResult=evalPop();
}


int main()
{
	char command;

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;


}
