/* ************************************************************

�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. 
�̶�, ȸ������ ���̰� �����ϴ� ������, 
���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

(�Է�)
ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)
��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. 
���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, 
���̰� 100���� �۰ų� ���� ���ڿ��̴�. �Է��� ������ ������ �־�����.

(���)
ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, 
���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.

EX)
(�Է�)
3
21 Junkyu
21 Dohyun
20 Sunyoung

(���)
20 Sunyoung
21 Junkyu
21 Dohyun
************************************************************ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEMBERS 100000
#define MAX_AGE 200
#define MAX_NAME 100

int members;

int ages[MAX_MEMBERS];
char *names[MAX_MEMBERS];

int temp1[MAX_MEMBERS];
char temp2[MAX_NAME];

void members_input();
void members_output();
void sorting();

int main()
{
    scanf("%d", &members);
    
	if (members > MAX_MEMBERS || members < 1)
		printf("Members error!\n");
    
	members_input();
	sorting();

	printf("\n");

	members_output();
	
    return 0;
}


void members_input()
{
    char name[MAX_MEMBERS];	
	
	for (int i = 0; i < members; i++)
	{
		scanf("%d%s", &ages[i], name);
		names[i] = strdup(name);
	}
} 

void members_output()
{
	for (int i = 0; i < members; i++)
		printf("%d %s\n", ages[i], names[i]);
}

void sorting()
{
		for (int i = 0; i < members-1; i++) {
		for (int j = i+1; j < members; j++) {
			if (ages[i] > ages[j]) {
				temp1[i] = ages[i];
				ages[i] = ages[j];
				ages[j] = temp1[i];

				strcpy(temp2, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp2);
			}			
		} //end for
	} //end for
}
