#include <stdio.h>
#define MAX_LIMIT 600

static int int_key;
static double double_key;
static char char_key;

void start_write();
void take_keys();
void write_to_file(double* encrypted);
void encrypt(char* msg);

void start_write()
{
	char str[MAX_LIMIT];
	printf("�޼����� �Է��ϼ���:\n");
	fgets(str, MAX_LIMIT, stdin);
	printf("%s",str);
	encrypt(str);
}

void take_keys() //������, �Ǽ���, ������ Ű�� �޾� ����
{
	printf("����: ");
	scanf("%d",&int_key);
	printf("�Ǽ�: ");
	scanf("%lf",&double_key);
	scanf("%*c"); //enter ���� 
	printf("����: ");
	scanf("%c",&char_key);
	FILE *fp;
	fp = fopen("key.txt","wb");
	fprintf(fp,"%d %lf %c",int_key,double_key,char_key); //������ Ű�� ���Ͽ� ����
	fclose(fp);
}

void encrypt(char* msg) //��ȣȭ ����
{
	take_keys();
	double encrypted[MAX_LIMIT]; //msg*double/char+int
	for(int i=0;i<MAX_LIMIT;i++)
	{
		encrypted[i] = msg[i]*double_key/char_key+int_key; //��ȣȭ ���; ���� * �Ǽ� Ű / ���� Ű + ���� Ű
	}
	write_to_file(encrypted);
}

void write_to_file(double *encrypted)
{
	FILE *fp;
	fp = fopen("encrypted_message.txt","wb");
	for(int i=0;i<MAX_LIMIT;i++)
	{
		fprintf(fp,"%lf ",*(encrypted+i));
	}
	fclose(fp);
}




