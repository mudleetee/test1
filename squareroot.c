#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    float sqrt,f,upper,lower;
    FILE *file;
    file = fopen("c_test.txt","r");
    fscanf(file,"%f",&f);
    printf("Your Number : %f\n",f);

    lower=0;
    upper=f;
    sqrt=(lower+upper)/2.0;
    printf("fabs=%f\n",fabs((sqrt*sqrt)-f));
    while(fabs((sqrt*sqrt)-f) > 0.000001){
        if (sqrt*sqrt < f){
            lower=sqrt;
        }
        else{
            upper=sqrt;
        }
        sqrt=(lower+upper)/2.0;
        printf("fabs=%f\n",fabs((sqrt*sqrt)-f));
    }
    printf("Square root of %.2f is %.3f",f,sqrt);
    fclose(file);
    return 0;
}
