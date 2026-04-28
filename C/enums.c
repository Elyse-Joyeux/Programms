#include <stdio.h>

typedef enum {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
}WeekDays;

int main(){
	const char* weekdays[] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};
	 
	
	for(int i = 0; i<=Sunday; i++){
		WeekDays day = i;
		printf("%s - Integer Value is %d\n", weekdays[day], day);
		
	}
	
	
	return 0;
}




