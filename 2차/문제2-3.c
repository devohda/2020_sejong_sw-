#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//숫자 오른쪽으로 회전
int rotateRight(int n) {
	
	int a = n % 10;
	n /= 10;

	int ten = 1;
	while (n >= ten)
	{
		ten *= 10;
	}
	n += ten * a;
	return n;
}

//숫자 왼쪽으로 회전
int rotateLeft(int n) {

	int ten = 1;
	while (n >= ten)
	{
		ten *= 10;
	}

	ten /= 10;
	int a = n / ten;
	n %= ten;

	n *= 10;
	n += a;

	return n;
}

int main() {

	char str[101];
	int max = 10000000;
	int min = 10000000;
	int minus = 1;
	int rotateR, rotateL;
	gets(str);

	//입력 받은 문자열 돌면서 숫자 만들기
	for (int i = 0; i < strlen(str); i++)
	{
		//상태 초기화
		rotateL = rotateR = 0;
		minus = 1;

		//만약 숫자문자가 나오면 숫자만들기 시작
		if (str[i] >= '0' && str[i] <= '9')
		{
			//음수인지 or 숫자를 회전해야 하는지 검사
			if (i != 0)
			{
				if (str[i - 1] == '-')
				{
					minus = -1;
					if (i > 1)
					{
						if (str[i - 2] == '@')
						{
							rotateR = 1;
						}
						else if (str[i - 2] == '!')
						{
							rotateL = 1;
						}
					}
				}
				else if (str[i - 1] == '@')
				{
					rotateR = 1;
				}
				else if (str[i - 1] == '!')
				{
					rotateL = 1;
				}
			}
			
			//숫자문자로 숫자 만들기
			int num = 0;
			while (str[i] >= '0' && str[i] <= '9' && i < strlen(str))
			{
				num *= 10;
				num += str[i] - '0';
				i++;
			}

			//회전해야 하면 회전시키기
			if (rotateL)
			{
				num = rotateLeft(num);
			}
			else if (rotateR) {
				num = rotateRight(num);
			}

			//음수면 음수 만들기
			num *= minus;

			//처음 만들어진 숫자면 max, min 값 초기화
			if (max == 10000000)
			{
				max = min = num;
			}
			else //아니면 조건에 따라 저장
			{
				if (max < num)
				{
					max = num;
				}
				if (min > num)
				{
					min = num;
				}
			}
			i--;
		}
	}

	//결과 출력
	printf("%d %d\n", max, min);

	return 0;
}