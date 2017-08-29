#include <stdio.h>

int inarray [] ={1, 2, 0, 5, -3, -25, 8, 13, -4, 3, 5, -4, 9};
int sum = 5;


int main()
{
    int firstval[200]; //ol' histogram, can hold +-100
    int size, i, j, length, maxl, jindex;
    
    size=sizeof(inarray)/sizeof(int);
    //convert inarray to cum-sum
    printf("Original inarray:");
    for(i=0;i<size;i++){
        printf(" %d", inarray[i]);
        if(i!=0) inarray[i]+=inarray[i-1];
    }
    printf("\ncum-sum  inarray:");
    for(i=0;i<size;i++) printf(" %d", inarray[i]);
    printf("\n");
    
    //build firstval - where index is the value+100, and the firstval[index] holds the inarray index when that value first occurred. -999 indicates no value
    for(i=0;i<200;i++) firstval[i]=-999;
    for(i=0;i<size;i++) if(firstval[inarray[i]+100]==-999) firstval[inarray[i]+100]=i;
    
    // print the firstval[]
    printf("firstval:");
    for(i=0;i<200;i++) if(firstval[i]!=-999) printf(" [%d]%d", i-100, firstval[i]);
    printf("\n");
    
    //actual problem compute
    maxl=0; length=0; jindex=0;
    for(j=0;j<size;j++){
        i=firstval[inarray[j]-sum+100];
        if(i!=-999) length=j-i;
        if(length>maxl){
            maxl=length;
            jindex=j;
        }
    }
    printf("The max lenght of numbers whose Sum=%d, is %d, and ends at j-index %d with value of %d\n", sum, maxl, jindex, inarray[jindex]);

    return 0;
}
