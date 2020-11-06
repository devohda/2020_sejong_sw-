#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//���� ���������� ȸ��
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

//���� �������� ȸ��
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

	//�Է� ���� ���ڿ� ���鼭 ���� �����
	for (int i = 0; i < strlen(str); i++)
	{
		//���� �ʱ�ȭ
		rotateL = rotateR = 0;
		minus = 1;

		//���� ���ڹ��ڰ� ������ ���ڸ���� ����
		if (str[i] >= '0' && str[i] <= '9')
		{
			//�������� or ���ڸ� ȸ���ؾ� �ϴ��� �˻�
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
			
			//���ڹ��ڷ� ���� �����
			int num = 0;
			while (str[i] >= '0' && str[i] <= '9' && i < strlen(str))
			{
				num *= 10;
				num += str[i] - '0';
				i++;
			}

			//ȸ���ؾ� �ϸ� ȸ����Ű��
			if (rotateL)
			{
				num = rotateLeft(num);
			}
			else if (rotateR) {
				num = rotateRight(num);
			}

			//������ ���� �����
			num *= minus;

			//ó�� ������� ���ڸ� max, min �� �ʱ�ȭ
			if (max == 10000000)
			{
				max = min = num;
			}
			else //�ƴϸ� ���ǿ� ���� ����
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

	//��� ���
	printf("%d %d\n", max, min);

	return 0;
}