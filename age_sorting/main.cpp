/* ************************************************************

온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 
이때, 회원들을 나이가 증가하는 순으로, 
나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

(입력)
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 
나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 
길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

(출력)
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 
나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

EX)
(입력)
3
21 Junkyu
21 Dohyun
20 Sunyoung

(출력)
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
