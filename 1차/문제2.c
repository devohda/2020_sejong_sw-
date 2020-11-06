#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	int N; //�¼� ��
	int chair[100][100]; //�߱��� ������ ���� ����
	int W, H; //���� ����

	scanf("%d", &N); //�¼� �� �Է� �ޱ�
	for (int i = 0; i < N; i++) //�¼� ���� ��Ȳ �Է� �ޱ�
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &chair[i][j]);
		}
	}

	scanf("%d%d", &W, &H); //���� ���� �Է� �ޱ�

	int reservation = 0; //������ �ƴ��� Ȯ���ϴ� flag ����
	for (int row = 0; row < N - H + 1; row++) //�¼� ��ü�� ���鼭 ���� �������� Ȯ��
	{
		for (int col = 0; col < N - W + 1; col++)
		{
			reservation = 0; //chair[i][j]�� �������� ���� W, ���� H ���� �¼��� ����ִ��� Ȯ���ϱ�
			for (int h = 1; h <= H; h++)
			{
				for (int w = 1; w <= W; w++)
				{
					if (chair[row + h - 1][col + w - 1] == 1) //���� �ϳ��� ������ �Ǿ� ������ �� �˻��� �ʿ� X
					{
						reservation = 1;
						break;
					}
				}
				if (reservation) break;
			}
			if (!reservation) //���� W, ���� H ���� �¼��� ��� ��� ������ ���簢�� ù ��° �ڸ� ���
			{
				printf("%d %d\n", row + 1, col + 1);
				break;
			}
		}
		if (!reservation) break;//ã������ �� �̻� �˻��� �ʿ� X
	}

	if (reservation) printf("none\n"); //���� W, ���� H ���� �¼��� ������(��� ������ �Ǿ�����) none ���

	return 0;
}