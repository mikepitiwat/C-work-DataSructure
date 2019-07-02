#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define l 1
#define u 5
#define l1 1
#define u1 3
#define l2 1
#define u2 4
#define l3 1
#define u3 5

int *BA3,*AD,*p;
int i, j, k;

void printLine();
void Choose_cutting();

void Create3DArray(){//Plane Row Column
    int element, c ,total_mem;
    element = (u1-l1+1)*(u2-l2+1)*(u3-l3+1);
    c = sizeof(*BA3);
    total_mem = element*c;
    BA3 = (int*)malloc(total_mem);
}

void funcselectA3D(int select, int i, int j, int k, int x){
    switch (select){
        case 1:
            // PRC
            p = BA3+((i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3));
            AD = p;
            *p = x ;

            break;
        case 2:
            // PCR
            p = BA3+((i-l1)*(u2-l2+1)*(u3-l3+1)+(k-l3)*(u2-l2+1)+(j-l2));
            AD = p;
            *p = x ;
            break;
        case 3:
            // RPC
            p = BA3+((j-l2)*(u1-l1+1)*(u3-l3+1)+(i-l1)*(u3-l3+1)+(k-l3));
            AD = p;
            *p = x ;
            break;
        case 4:
            // RCP
            p = BA3+((j-l2)*(u1-l1+1)*(u3-l3+1)+(k-l3)*(u1-l1+1)+(i-l1));
            AD = p;
            *p = x ;
            break;
        case 5:
            // CPR
            p = BA3+((k-l3)*(u1-l1+1)*(u2-l2+1)+(i-l1)*(u2-l2+1)+(j-l2));
            AD = p;
            *p = x ;
            break;
        case 6:
            // CRP
            p = BA3+((k-l3)*(u1-l1+1)*(u2-l2+1)+(j-l2)*(u1-l1+1)+(i-l1));
            AD = p;
            *p = x ;
            break;
    }
}

int main(){
    int s;
    Choose_cutting();
    printf("select : ");
    scanf("%d",&s);
    Create3DArray();
    printf("\nBase Adress BA3 = %d\n\n", BA3);

    int num1 = 5;
    i = 2, j = 2, k = 2;
    funcselectA3D(s,i,j,k,num1);
    printf("num 1 = %d\n", num1);
    printf("Adress num1 = (BA3+%d byte)\n", (AD - BA3) * sizeof(int));
    printf("adress num1 %d\n", AD);
    printLine();

    int num2 = 4;
    i = 1, j = 3, k = 2;
    funcselectA3D(s,i,j,k,num2);
    printf("num 2 = %d\n", num2);
    printf("Adress num2 = (BA3+%d byte)\n", (AD - BA3) * sizeof(int));
    printf("adress num2 %d\n", AD);
    printLine();


    int num_sum = num1+num2;
    i = 2, j = 1, k = 3;
    funcselectA3D(s,i,j,k,num_sum);
    printf("num_sum = %d\n", num_sum);
    printf("Adress num_sum = (BA3+%d byte)\n", (AD - BA3) * sizeof(int));
    printf("adress num_sum %d\n", AD);
    printLine();

}

void printLine(){
    for (int i = 0; i <100; ++i) printf("-"); printf("\n");
}
void Choose_cutting(){
    printf("Choose_cutting >>>\n");
    printf("\t1.(PRC) Plane  -> Row    -> Column\n");
    printf("\t2.(PCR) Plane  -> Column -> Row\n");
    printf("\t3.(RPC) Row    -> Plane  -> Column\n");
    printf("\t4.(RCP) Row    -> Column -> Plane\n");
    printf("\t5.(CPR) Column -> Plane  -> Row\n");
    printf("\t6.(CRP) Column -> Row    -> Plane\n");
}


