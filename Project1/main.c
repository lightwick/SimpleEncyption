#include <stdio.h>
#include "startpoint.h"

int main()
{
	int input;
	printf("/*******Group 2 Encryption v_1.0*******/\n");
	printf("Write mode: 1 | Read mode : 2\nWrite number: ");
	scanf("%d",&input);
	scanf("%*c"); //엔터키가 입력되는 것을 방지 
	switch(input)
	{
		case 1:
			start_write(); // startpoint.h 에 저장된 함수
			break;
		case 2:
			start_read(); // startpoint.h 에 저장된 함수
			break;
	}	
}
