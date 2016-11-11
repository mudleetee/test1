#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

typedef enum { false, true } bool;
typedef struct position{
		int row;
		int col;
	}position;

bool used_in_row[9][10];
bool used_in_col[9][10];
bool used_in_block[3][3][10];

void set_used(position pos, int number, bool use){
    used_in_row[pos.row][number] = use; // This number was used in this row.
    used_in_col[pos.col][number] = use; // This number was used in this col.
    used_in_block[pos.row/3][pos.col/3][number] = use; // This number was used in this block 3x3.
}
void init_used(){
	int i, j, k;
	for(i=0; i<9; i++){
		for(j = 0; j<9; j++){
			for(k = 0; k<10; k++){
				position cur_pos = (position){i, j};
				set_used(cur_pos, k , false);
			}
		}
	}

}

void read_input(char file_name[100], int sudoku[9][9], int *count, int ***test){

    FILE *file;
    int i, j, n;
    file = fopen("sudoku2.txt","r");
    // Read test case count
    fscanf(file,"%d", &n);
    *count = n;
    // Allocate memory for test cases
    *test = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++){
        (*test)[i] = (int*)malloc(sizeof(int) * 3);
    }
    // Read test case
    for (i = 0; i < n; i++){
        fscanf(file, "%d%d%d", &((*test)[i][0]), &((*test)[i][1]), &((*test)[i][2]));
    }
    // Read sudoku table and update usage data
    for (i=0; i<9; i++){
        for (j=0; j<9; j++){
            fscanf(file, "%d", &sudoku[i][j]);
            // Mark number as used update usage data
            position cur_pos = (position){i ,j};
            set_used(cur_pos, sudoku[i][j], true);
        }
    }
    fclose(file);
}

bool can_fill(int sudoku[9][9], position pos, int number){
    bool blank;
    bool not_used;
    // "blank" used to check position that you want =0(empty) ? , return 0 if !=0(not empty), return 1 if ==0(empty)
    blank = (sudoku[pos.row][pos.col] == 0);
    printf("row=%d, col=%d, number =%d\n",pos.row, pos.col, number);
    printf("blank=%d",blank);
    //"not_used" will return return 1 (empty) if this number was not used in this row && col && block3x3
    not_used = !used_in_row[pos.row][number] && !used_in_col[pos.col][number] && !used_in_block[pos.row/3][pos.col/3][number];
    printf(" not_used=%d\n", not_used);
    if (blank && not_used){
    	return true;
    }else{
    	return false;	
    }
    
}
int main(int argc, char *argv[]){
    int i,j;
    int count, **test_case;
    int sudoku[9][9];   
    init_used();
    read_input(argv[1], sudoku, &count, &test_case);
    for(i = 0; i < count; i++){
        position pos;
        int number;
        pos.row = test_case[i][0];
        pos.col = test_case[i][1];
        number  = test_case[i][2];
        printf("%d\n", can_fill(sudoku, pos, number));
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
   
    return 0;
}
