#include <stdio.h>
#include <stdlib.h>

// Banker's Algorithm
int AvailabilityCheck(int a1[],int a2[],int m){
    int i,count=0;
    for(i=0;i<m;i++){
        if(a1[i]<=a2[i]){
            count++;
        }
    }
    if(count==m){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n,i,m,j;
    printf("Enter the number of Processes: \n");
    scanf("%d",&n);
    printf("Enter Number of Type of Resources: \n");
    scanf("%d",&m);
    int Max[n][m],Available[m],Allocation[n][m],Need[n][m],Sequence[n];
    printf("Please enter The Available Resources: \n");
    for(i=0;i<m;i++){
        scanf("%d",&Available[i]);
    }
    printf("Please enter The Allocation matrix Row wise: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&Allocation[i][j]);
        }
    }
    printf("Please enter The Max matrix Row wise: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&Max[i][j]);
            Need[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(Max[i][j]>Allocation[i][j]){
                Need[i][j]=Max[i][j]-Allocation[i][j];
            }else{
                Need[i][j]=0;
            }
        }
    }
    // safe sequence Generation
    int a=0;
    while(a<n){
        for(i=0;i<n;i++){
        int Buffer[m],x;
        for(j=0;j<m;j++){
            Buffer[j]=Need[i][j];
        }
        x=AvailabilityCheck(Buffer,Available,m);
        if(x==1){
            Sequence[a]=i+1;
            a++;
            for(j=0;j<m;j++){
                Need[i][j]=10000;
                Available[j]=Available[j]+Allocation[i][j];
            }
            
        }
    }   
    }
    printf("\nGenerated Safe Sequence according to Banker's Algorithm:\n\n");
    for(i=0;i<n;i++){
        printf("P%d\t",Sequence[i]);
    }





}
