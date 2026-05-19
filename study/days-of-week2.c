#include <stdio.h>
#include<stdbool.h>

typedef enum {
    SUN,
    MON,
    TUE,
    WED,
    THUR,
    FRI,
    SAT
} Day;

int main(){
    Day current = WED;
    int isWeekDay;

    if(current == SUN || current == SAT){
        isWeekDay = false;
    }
    else{
        isWeekDay = true;
    }

    if(isWeekDay){
        printf("Result: 1\n");
        return 1;
    }else {
        printf("Result: 0\n");
        return 0;
    }

    return 0;
}
