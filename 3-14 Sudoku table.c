#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int i,j;
    for(i=0;i<9;i++){
        if (i%3==0){
            printf("+---+---+---+\n");
        }
        for(j=0;j<9;j++){
            if(j%3==0){
                //printf("%c",124);
                printf("|");
            }
            //printf("%c",35);
            printf("#");
            if(j==8){
                //printf("%c",124);
                printf("|");
            }
        }
        //printf("%c",10);
        printf("\n");
        if (i==8){
            printf("+---+---+---+");
        }
    }
    return 0;
}
