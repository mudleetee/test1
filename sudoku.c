#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    FILE *file;
    int i,j;
    int sudoku[9][9];
    // read sudoku table
    file=fopen("sudoku.txt","r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(file,"%d",&sudoku[i][j]);
        }
    }
    for(i=0;i<9;i++){
        if (i%3==0){
            printf("+---+---+---+\n");
        }
        for(j=0;j<9;j++){
            if(j%3==0){
                //printf("%c",124);
                printf("|");
            }
            if (sudoku[i][j] != 0){
                printf("%d",sudoku[i][j]);
            }
            else{
                printf("#");
            }
            //printf("%c",35);
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
    /* test
    for(i=0;i<9;i++){
        printf("\n");
        for(j=0;j<9;j++){
            if (sudoku[i][j] != 0){
                printf("%d",sudoku[i][j]);
            }
            else{
                printf("#");
            }
        }
    }
    */
    return 0;
}
