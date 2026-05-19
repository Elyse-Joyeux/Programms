#include <stdio.h>

typedef struct{
    char title[50];
    int release_year;
}Movie;

void change(Movie movie1){
    movie1.release_year = 2025;
}

int main(){
    Movie movie2;
    movie2.release_year = 2026;
    change(movie2);
    printf("The value returned is %d\n", movie2.release_year);
    return 0;
}