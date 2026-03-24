 
#include<stdio.h>
#include<string.h>

typedef struct {
	int age, id, marks;
	char class[10];
	char name[15];
} Student;

Student s1;
void data(){
	s1.age = 12;
	s1.id = 3;
	s1.marks = 68;
	strcpy(s1.class, "Year1A");
	strcpy(s1.name, "Elyse");
}
int main(){
	data();
	printf("the name is %s\n", s1.name);
	printf("the marks are %d\n", s1.marks);
	printf("the age is %d\n", s1.age);
	printf("the id is %d\n", s1.id);
	printf("the class is %s\n", s1.class);
	printf("the size of the structure is as below %zu", sizeof(Student));

	return 0;
	}




/*
#include<stdio.h>
#include<string.h>

struct Student{
	int id,age;
	char name[10];
	
};
struct Student s1, s2;

int main(){
	s1.age  = 12;
	s1.id = 1;
	strcpy(s1.name, "Joyeux");
	s2 = s1;
	
	printf("the student name is as follows: %s\n", s2.name);
	return 0;
}
 
 
 
 
#include<stdio.h>

struct Example {
	int i;
	char c;
	double me;
};

int main(){
	printf("The size of the following structure is %zu", sizeof(struct Example));
	return 0;
}

*/





