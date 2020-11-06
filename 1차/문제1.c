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

			//chair[row][col]�� �������� ���� W, ���� H ���� �¼��� ����ִ��� Ȯ���ϱ�
			reservation = 0;
			for (int h = 0; h < H; h++)
			{
				for (int w = 0; w < W; w++)
				{
					//���� �ϳ��� ������ �Ǿ� ������ �� �˻��� �ʿ� X
					if (chair[row + h][col + w] == 1)
					{
						reservation = 1;
						break;
					}
				}
				if (reservation) break;
			}


			//���� W, ���� H ���� �¼��� ��� ��� ������ ���簢�� ù ��° �ڸ� ���
			if (!reservation)
			{
				printf("%d %d\n", row + 1, col + 1);
				break;
			}
		}
		if (!reservation) break;//ã������ �� �̻� �˻��� �ʿ� X
	}


	//���� W, ���� H ���� �¼��� ������(��� ������ �Ǿ�����) none ���
	if (reservation) printf("none\n");

	return 0;
}