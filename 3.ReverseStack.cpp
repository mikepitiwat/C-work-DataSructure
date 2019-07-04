#include <stdio.h>
#include <conio.h>
#define MaxStack 6

int stack[MaxStack];
int x;
int SP = MaxStack;
char status ='N';
char ch;

void push(int x){
    if(SP == 1)
    {
        printf("!!! OVER FLOW!!!\n");
        status = 'O';
    }
    else
    {
        SP = SP-1;
        stack[SP] = x;
    }
}
int pop(){
    int x;
    if(SP != (MaxStack-1)){
        x=stack[SP];
        SP++;

        return(x);
    }
    else
    {
        printf("\n!!!UNDER FLOW!!!\n");
        status = 'U';
    }
}
void ShowAllStack(){
    int i;
    printf("N : %d\n",MaxStack-1);
    printf("Status :%c\n",status);
    printf("SP :%d\n",SP);
    for( i = 1 ; i < MaxStack ; i++ ){
        printf(" %d : %d |",i,stack[i]);
    }
    printf("\n----------------------\n");
}
int main(){
    printf("STACK PROGRAM...\n");
    printf("================\n");
    while(status == 'N'){
        printf("[ 1=Push : 2=Pop ] : ");
        ch=getch();
        switch(ch){
            case'1':	printf("\nEnter Number : ");
                scanf( "%d",&x );
                push(x);
                ShowAllStack();
                break;
            case'2':	x=pop();
                printf("\nData : %d\n",x);
                ShowAllStack();
                break;
        }
    }
    printf("\n");
    return (0);
}
