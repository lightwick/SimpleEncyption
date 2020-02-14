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

void start_read() //읽기 시작
{
	int response;
	printf("Have key? (Yes=1;No=0)"); //키 파일이 있는냐 없느냐 응답
	scanf("%d",&response);
	if(response==1)
	{
		read_with_key();
	}
	else no_key();
}

void read_with_key() //키 파일이 있는 경우, 키 파일에 저장된 값들을 통해 암호화된 문자열 해독
{
	FILE *fp;
	fp = fopen("key.txt","rb");
	if (fp != NULL)
	{
		fscanf(fp, "%d%lf %c", &int_key, &double_key, &char_key);
		fclose(fp);
		//printf("\n%d %lf %c",int_key,double_key,char_key);
		decrypt_msg(); // 해독 함수
	}
	else printf("key 파일이 없습니다!");
}

void no_key() // 키 파일이 없는 경우, 문자열 해독에 필요한 값들을 직접 입력
{
	printf("정수: ");
	scanf("%d",&int_key);
	printf("실수: ");
	scanf("%lf",&double_key);
	scanf("%*c"); 
	printf("문자: ");
	scanf("%c",&char_key);
	decrypt_msg(); // 해독 함수
}

void decrypt_msg()
{
	char msg[MAX_LIMIT];
	FILE *fp;
	fp = fopen("encrypted_message.txt","rb"); 
	for(int i=0;i<MAX_LIMIT;i++)
	{
		double temp,double_msg;
		fscanf(fp,"%lf",&temp); // 파일에서 부터 읽어내는 과정
		double_msg = (temp-int_key)*char_key/double_key; 
		//참고; 암호화 방식: 문자 * 실수 키 / 문자 키 + 정수 키
		//이를 다시 돌리기 위해서 공식 반대로 적용
		char msg = (int)(double_msg+0.5); //정수로 반올림; 암호화 및 해독 과정에서 생긴 작은 오차값 제거
		printf("%c",msg); // 해독한 문자 출력
	}
	fclose(fp);
}






