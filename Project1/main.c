#include <stdio.h>
#include "startpoint.h"

int main()
{
	int input;
	printf("/*******Group 2 Encryption v_1.0*******/\n");
	printf("Write mode: 1 | Read mode : 2\nWrite number: ");
	scanf("%d",&input);
	scanf("%*c"); //����Ű�� �ԷµǴ� ���� ���� 
	switch(input)
	{
		case 1:
			start_write(); // startpoint.h �� ����� �Լ�
			break;
		case 2:
			start_read(); // startpoint.h �� ����� �Լ�
			break;
	}	
}
