#include <stdio.h>

typedef enum{
	Red,
	Yellow,
	Green
}TrafficLight;

int main(){
	TrafficLight state = Red;
	switch(state){
		case Red:
			printf("Stop");
			break;
		case Yellow:
			printf("Ready");
			break;
		case Green:
			printf("Go");
			break;
		default:
			printf("Error");
		
	}
	return 0;
}
