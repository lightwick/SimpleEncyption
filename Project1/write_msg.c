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
	printf("메세지를 입력하세요:\n");
	fgets(str, MAX_LIMIT, stdin);
	printf("%s",str);
	encrypt(str);
}

void take_keys() //정수형, 실수형, 문자형 키를 받아 저장
{
	printf("정수: ");
	scanf("%d",&int_key);
	printf("실수: ");
	scanf("%lf",&double_key);
	scanf("%*c"); //enter 방지 
	printf("문자: ");
	scanf("%c",&char_key);
	FILE *fp;
	fp = fopen("key.txt","wb");
	fprintf(fp,"%d %lf %c",int_key,double_key,char_key); //저장한 키를 파일에 저장
	fclose(fp);
}

void encrypt(char* msg) //암호화 과정
{
	take_keys();
	double encrypted[MAX_LIMIT]; //msg*double/char+int
	for(int i=0;i<MAX_LIMIT;i++)
	{
		encrypted[i] = msg[i]*double_key/char_key+int_key; //암호화 방식; 문자 * 실수 키 / 문자 키 + 정수 키
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




