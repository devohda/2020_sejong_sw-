#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	int N, K;
	scanf("%d %d", &N, &K); //N, K �Է� �ޱ�
	getchar();

	char ox[100][100]; //OX ���� �����ϴ� ����
	for (int i = 0; i < N; i++) //OX�� �̷���� N * K 2���� ��� �Է� �ޱ�
	{
		for (int j = 0; j < K; j++)
		{
			scanf("%c", &ox[i][j]);
		}
		getchar();
	}

	int min = N > K ? K : N; //X������ �����ϴ� �ִ� ��� �밢�� ����.
	int s = 2;
	int max = -1;
	int flag;
	while (s <= min) //2 * 2 ���� min * min���� ���� Ž��
	{
		for (int x = 0; x <= N - s; x++) //���� ���� ����
		{
			for (int y = 0; y <= K - s; y++)
			{

				// ���� ���� ���� s�� X ������ �����ϴ��� Ž��
				flag = 0;
				for (int i = 0; i < s; i++)
				{
					for (int j = 0; j < s; j++)
					{
						if (i == j || j == s - 1 - i)
						{
							if (!(ox[x + i][y + j] == 'X')) {
								flag = 1;
								break;
							}
						}
						else
						{
							if (!(ox[x + i][y + j] == 'O')) {
								flag = 1;
								break;
							}
						}	
					}
					if (flag == 1) break;
				}
				if (flag == 0) break;
			}
			if (flag == 0) break;
		}

		if (flag == 0) max = s;
		s++;

	}

	//��� ���
	printf("%d\n", max);

	return 0;
}