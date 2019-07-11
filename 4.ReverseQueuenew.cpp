#include <stdio.h>
#include <conio.h>

//#define N 5

int Q[100];
int x, Qnumber = 0;
int F,R,N;
char status = 'N';
char ch;

void insertCQ(int y){
    if((R == F+1)|| (R == 1 && F == (N-1))){
        printf("!!!OVER FLOW!!!\n");
        status = 'O';
    }
    else{
        if(R == 1){
            R = N-1;
        }
        else
        {
            R--;
            if(F == N)
                F = (N-1);
        }
        Qnumber++;
        printf("Your are queue number :%d\n",Qnumber);
        Q[R] = y;
        status = 'N';
    }
}
int deleteCQ(){
    int y;
    if(F == N){
        printf("\n!!!UNDER FLOW!!!...\n");
        status = 'U';
    }
    else{
        y = Q[F];
        if(F == R){
            F = N; R = N;
        }
        else{
            if(F == 1)
                F=(N-1);
            else
                F--;
        }
        status = 'N';
        return(y);
    }
}
int DataInQueue(){
    int y = 0;
    if(F != 0 && R != 0){
        if( F >= R)
            y= F-R+1;
        else
            // F<R
            y = ((N-1)-R+1)+F;
    }
    return(y);
}
void ShowAllQueue(){
    int i;
    printf("N :%d\n",N-1);
    printf("Status =%c \n",status);
    printf("Data waiting in queue =%d\n",DataInQueue());
    printf("F = %d | R = %d\n",F,R);
    for(i = 1 ; i < N ; i++){
        printf(" %d : %d |",i,Q[i]);
    }
    printf("\n----------------------------\n");
}

int main(){
    printf("CICULAR QUEUE PROGRAM...\n");
    printf("========================\n");
    printf("scan N: ");
    scanf("%d",&N);
	N +=1;
	F=N,R=N;
    ch = ' ';
    while(ch != 'E'){
        printf("\n[ 1 = insert : 2 = Delete E = Exit ] : ");
        ch = getch();
        switch(ch){
            case'1':	printf("\nInsert Number : ");
                scanf("%d",&x);
                insertCQ(x);
                ShowAllQueue();
                break;
            case'2':	x=deleteCQ();
                printf("\nData from Queue =%d\n",x);
                ShowAllQueue();
                break;
        }
    }
    printf("\n");
    return(0);

}
