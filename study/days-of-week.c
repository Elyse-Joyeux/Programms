#include <stdio.h>

typedef enum {
    MON,
    TUE,
    WED,
    THUR,
    FRI,
    SAT,
    SUN
} Day;

int main(){
    const char* weekDays[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    for(int i = 0; i<=SUN; i++){
        Day days = i;
        printf("%s Integer value is %d\n", weekDays[days], days);
    }

    return 0;
}