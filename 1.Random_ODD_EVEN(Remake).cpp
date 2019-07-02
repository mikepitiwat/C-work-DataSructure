#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 999
void printLine();

int data[MAXVALUE];
int numrand=100, num_odd = 0, num_even = 0;
int sum_odd = 0, sum_even = 0, total_data = 0;
int odddata[300];
int evendata[300];

int ranDom(int num, int start, int end) {
    srand(time(NULL));
    for (int i = 0; i <num; ++i) {
        data[i] = rand()%(end-start+1)+start;
        total_data += data[i];
    }
    return num;
}

void odd_even(){
    for (int i = 0; i < numrand; ++i) {
        if (data[i] % 2 != 0) {
            odddata[num_odd] = data[i];
            sum_odd += odddata[num_odd];     // Total odd
            num_odd++;
        } else{
            evendata[num_even] = data[i];
            sum_even += evendata[num_even];  // Total even
            num_even++;
        }
    }
}

void showIntervalData(){
    int start = 0, end = 99;
    for (int i = 0; i < 10; ++i) {
        printf("[%3d-%3d] : ", start, end);
        for (int j = 0; j < numrand; ++j) {
            if (data[j] >= start && data[j] <= end) {
                printf("%d ", data[j]);
            }
        }
        start +=100; end += 100;
        if(i < 9)
            printf("\n");
    }
}

void sortData(){
    int temp;
    for (int i = 0; i < numrand; ++i) {
        for (int j = i+1; j < numrand; ++j) {
            if(data[i]>data[j]){
                temp    = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void showReSult_Odd_Even(char odd_OR_even ){
    if(odd_OR_even == 'o') {
        printf("\nOdd count\t: %d\n", num_odd);
        printf("Odd Sum \t: %d\n", sum_odd);
        printf("Odd Average\t: %.2f\n", (float)sum_odd / num_odd);
    }else if(odd_OR_even == 'e'){
        printf("\nEven count\t: %d\n", num_even);
        printf("Even Sum\t: %d\n", sum_even);
        printf("Even Average\t: %.2f\n", (float)sum_even / num_even);
    } else
        printf("Not found");
}

void disPlay(int datainloop[], int numloop) {
    for (int i = 0; i < numloop; ++i) {
        printf("%d\t", datainloop[i]);
    }
}

int main(){
    printf("MANINPULATE DATA (LAB#01)\n");
    printf("ENTER N:");
    scanf("%d",&numrand);

    ranDom(numrand, 0, 999);
    odd_even();                     // sort odd and even
    printf("RAW DATA :\n");
    disPlay(data,numrand);          // show data random
    printLine();

    printf("ODD DATA :\n");
    disPlay(odddata,num_odd);       // Show data odd
    showReSult_Odd_Even('o');
    printLine();

    printf("EVEN DATA :\n");
    disPlay(evendata,num_even);     // Show data even
    showReSult_Odd_Even('e');
    printLine();

    printf("Total   \t: %d\n", total_data);
    printf("Total Average\t: %.2f", (float) total_data / numrand);
    printLine();
    showIntervalData();
    printLine();

    printf("Sorted Data :\t");
    sortData();                     // Show sort data
    disPlay(data, numrand);
    printLine();
    return 0;
}

void printLine(){
    printf("\n");for (int i = 0; i <120; ++i) printf("-");printf("\n");
}
