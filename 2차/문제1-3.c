#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	int N, K;
	scanf("%d %d", &N, &K); //N, K 입력 받기
	getchar();

	char ox[100][100]; //OX 상태 저장하는 변수
	for (int i = 0; i < N; i++) //OX로 이루어진 N * K 2차원 행렬 입력 받기
	{
		for (int j = 0; j < K; j++)
		{
			scanf("%c", &ox[i][j]);
		}
		getchar();
	}

	int min = N > K ? K : N; //X패턴이 존재하는 최대 행렬 대각선 길이.
	int s = 2;
	int max = -1;
	int flag;
	while (s <= min) //2 * 2 부터 min * min까지 패턴 탐색
	{
		for (int x = 0; x <= N - s; x++) //시작 지점 설정
		{
			for (int y = 0; y <= K - s; y++)
			{

				// 가로 세로 길이 s인 X 패턴이 존재하는지 탐색
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

	//결과 출력
	printf("%d\n", max);

	return 0;
}