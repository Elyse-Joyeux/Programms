#include<stdio.h>

struct Student {
	int age, id, marks;
	char class[10];
	char name[15];
};
struct Student s1;
struct Student *ptrSt=&s1;
void inputData();
void outputData();

void inputData(){
	printf("enter your name: \n");
	scanf("%14s", ptrSt->name);
	
	printf("enter your current age: \n");
	scanf("%d", &ptrSt->age);
	
	printf("enter your id: \n");
	scanf("%d", &ptrSt->id);
	
	printf("enter your current class: \n");
	scanf("%9s", ptrSt->class);
	
	printf("enter your marks: \n");
	scanf("%d", &ptrSt->marks);
	
	
}

void outputData(){
	printf("\nThe following are the student's details: \n");
	printf("student's name: %s\n", ptrSt->name);
	printf("student's age: %d\n", ptrSt->age);
	printf("student's id: %d\n", ptrSt->id);
	printf("student's class: %s\n", ptrSt->class);
	printf("student's marks: %d\n", ptrSt->marks);
	
}

int main(){
	inputData();
	outputData();
	return 0;
}
