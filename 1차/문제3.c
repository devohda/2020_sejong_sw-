#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int changeWord(char* word) { //�ܾ ���ڷ� �ٲٴ� �Լ�

	int sum = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		//�ܾ� �� �� ���ڷ� ��ȯ
		int num = word[i] - 'a' + 1;

		//���ڸ� ���ϱ�
		if (num >= 10)
		{
			sum *= 100;
			sum += num;
		}
		else
		{
			sum *= 10;
			sum += num;
		}
	}

	return sum;
}

int main() {


	char word1[101], word2[101];
	int sum1 = 0, sum2 = 0;

	//�ܾ� 2�� �Է� �ޱ�
	scanf("%s%s", word1, word2);

	//ù ��° �ܾ� ���ڷ� ��ȯ�ϱ�
	sum1 = changeWord(word1);

	//�� ��° �ܾ� ���ڷ� ��ȯ�ϱ�
	sum2 = changeWord(word2);

	//���� �� ���
	printf("%d\n", sum1 + sum2);

	return 0;
}