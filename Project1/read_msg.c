#include <stdio.h>
#define MAX_LIMIT 600

// comment for testing purposes

static int int_key;
static double double_key;
static char char_key;

void decrypt_msg();
void no_key();
void read_with_key();
void start_read();

void start_read() //�б� ����
{
	int response;
	printf("Have key? (Yes=1;No=0)"); //Ű ������ �ִ³� ������ ����
	scanf("%d",&response);
	if(response==1)
	{
		read_with_key();
	}
	else no_key();
}

void read_with_key() //Ű ������ �ִ� ���, Ű ���Ͽ� ����� ������ ���� ��ȣȭ�� ���ڿ� �ص�
{
	FILE *fp;
	fp = fopen("key.txt","rb");
	if (fp != NULL)
	{
		fscanf(fp, "%d%lf %c", &int_key, &double_key, &char_key);
		fclose(fp);
		//printf("\n%d %lf %c",int_key,double_key,char_key);
		decrypt_msg(); // �ص� �Լ�
	}
	else printf("key ������ �����ϴ�!");
}

void no_key() // Ű ������ ���� ���, ���ڿ� �ص��� �ʿ��� ������ ���� �Է�
{
	printf("����: ");
	scanf("%d",&int_key);
	printf("�Ǽ�: ");
	scanf("%lf",&double_key);
	scanf("%*c"); 
	printf("����: ");
	scanf("%c",&char_key);
	decrypt_msg(); // �ص� �Լ�
}

void decrypt_msg()
{
	char msg[MAX_LIMIT];
	FILE *fp;
	fp = fopen("encrypted_message.txt","rb"); 
	for(int i=0;i<MAX_LIMIT;i++)
	{
		double temp,double_msg;
		fscanf(fp,"%lf",&temp); // ���Ͽ��� ���� �о�� ����
		double_msg = (temp-int_key)*char_key/double_key; 
		//����; ��ȣȭ ���: ���� * �Ǽ� Ű / ���� Ű + ���� Ű
		//�̸� �ٽ� ������ ���ؼ� ���� �ݴ�� ����
		char msg = (int)(double_msg+0.5); //������ �ݿø�; ��ȣȭ �� �ص� �������� ���� ���� ������ ����
		printf("%c",msg); // �ص��� ���� ���
	}
	fclose(fp);
}






