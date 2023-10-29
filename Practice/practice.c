#include <stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

unsigned long long power(unsigned long long x , unsigned long long y){
    if(y==0){
        return 1;
    }
    else if(y%2 == 0){
        return power(x, y/2)* power(x,y/2);
    }
    else {
        return x*power(x, y/2)* power(x,y/2);
    }
}


int main(){
   double total_time;
    clock_t start_time,end_time;
    srand(time(0)); // function
    start_time = clock();

    unsigned long long res = power(5, 100000000000000);
    printf("%llu", res);

     end_time = clock();
     total_time = ((double)(end_time - start_time)/CLOCKS_PER_SEC) * pow(10,3); // for mili sec
     
     printf("\n--It took %lf ms--\n",total_time);

    return 0;

}