#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int data[999] = {0};
int ODD[500];
int EVEN[500];
int n;
int x=0,y=0;
int sumodd=0,sumeven=0;
int total=0;
float avg=0;
float avgodd=0.0,avgeven=0.0;
void DataRaw(int n){
    srand(time(NULL));
    for (int i = 1; i < n; i++) {
        data[i]=1+rand()%999;
    }
}
void DispalyData(){
    printf("RAW DATA:\n");
    for(int i =0; i<n; i++){
        printf("%d\t",data[i]);
    }
    printf("\n");
}
void ODD_EVEN_Data(){
    for (int i = 0; i < n; i++) {
        total += data[i];
        if(data[i]%2 != 0){
            ODD[x] = data[i];
            sumodd +=data[i];
            x++;
        }else{
            EVEN[y]=data[i];
            sumeven+=data[i];
            y++;
        }
    }
    avg = total/n;
}
void AVG(){
    avgodd = (float)sumodd/x;
    avgeven = (float)sumeven/y;
}
void DisplayOOD(){
    printf("OOD DATA:\n");
    for(int i =0; i<x; i++){
        printf("%d\t",ODD[i]);
    }
    printf("\n");
    printf("Odd Count\t:%d\n",x);
    printf("Odd sum\t:%d\n",sumodd);
    printf("Odd average\t:%.2f\n",avgodd);
}
void DisplayEVEN(){
    printf("EVEN DATA:\n");
    for(int i =0; i<y; i++){
        printf("%d\t",EVEN[i]);
    }
    printf("\n");
    printf("EVEN Count\t:%d\n",y);
    printf("Even sum\t:%d\n",sumeven);
    printf("Even average\t:%.2f\n",avgeven);
}
void Displaytotal(){
    printf("Total\t:%d\n", total);
    printf("Total Average\t:%f", avg);
}
void min_max(){
    int temp = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            if(data[i] > data[j]){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void Displayminmax(){
    printf("Sorted Data:  ");
    for(int i =0; i<n; i++){
        printf("%d\t",data[i]);
    }
}
void Dispalylevel(){
    printf("[   0-99] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=0 && data[i]<=99){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    
    printf("[100-199] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=100 && data[i]<=199){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[200-299] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=200 && data[i]<=299){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[300-399] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=300 && data[i]<=399){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[400-499] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=400 && data[i]<=499){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[500-599] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=500 && data[i]<=599){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[600-699] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=600 && data[i]<=699){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[700-799] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=700 && data[i]<=799){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[800-899] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=800 && data[i]<=899){
            printf("%d ",data[i]);
        }
    }
    printf("\n");
    printf("[900-999] : ");
    for(int i =0; i<n; i++){
        if(data[i]>=900 && data[i]<=999){
            printf("%d ",data[i]);
        }
    }
    printf("\n");

}

int main(){
    printf("MANINPULATE DATA (LA#01)\n");
    printf("ENTER N:");
    scanf("%d",&n);
    DataRaw(n);
    DispalyData();
    printf("----------------------------------------------------------------------------------------------------\n");
    ODD_EVEN_Data();
    AVG();
    DisplayOOD();
    printf("----------------------------------------------------------------------------------------------------\n");
    DisplayEVEN();
    printf("----------------------------------------------------------------------------------------------------\n");
    Displaytotal();
    printf("\n----------------------------------------------------------------------------------------------------\n");
    min_max();
    Dispalylevel();
    printf("----------------------------------------------------------------------------------------------------\n");
    Displayminmax();

    return 0;
}

