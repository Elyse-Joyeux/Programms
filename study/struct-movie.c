#include <stdio.h>

typedef struct{
    char title[50];
    int release_year;
}Movie;

int main(){
    Movie movie1 = {"Spiderman Brand New Day", 2026};
    Movie *ptr = NULL;
    ptr = &movie1;

    printf("The movie: %s was released in %d\n", ptr->title, ptr->release_year);
    return 0;
}