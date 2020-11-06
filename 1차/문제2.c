#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	int N; //좌석 수
	int chair[100][100]; //야구장 관람석 상태 저장
	int W, H; //예약 범위

	scanf("%d", &N); //좌석 수 입력 받기
	for (int i = 0; i < N; i++) //좌석 예약 상황 입력 받기
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &chair[i][j]);
		}
	}

	scanf("%d%d", &W, &H); //예약 범위 입력 받기

	int reservation = 0; //예약이 됐는지 확인하는 flag 변수
	for (int row = 0; row < N - H + 1; row++) //좌석 전체를 돌면서 예약 가능한지 확인
	{
		for (int col = 0; col < N - W + 1; col++)
		{
			reservation = 0; //chair[i][j]를 시작으로 가로 W, 세로 H 개의 좌석이 비어있는지 확인하기
			for (int h = 1; h <= H; h++)
			{
				for (int w = 1; w <= W; w++)
				{
					if (chair[row + h - 1][col + w - 1] == 1) //만약 하나라도 예약이 되어 있으면 더 검사할 필요 X
					{
						reservation = 1;
						break;
					}
				}
				if (reservation) break;
			}
			if (!reservation) //가로 W, 세로 H 개의 좌석이 모두 비어 있으면 직사각형 첫 번째 자리 출력
			{
				printf("%d %d\n", row + 1, col + 1);
				break;
			}
		}
		if (!reservation) break;//찾았으면 더 이상 검사할 필요 X
	}

	if (reservation) printf("none\n"); //가로 W, 세로 H 개의 좌석이 없으면(모두 예약이 되었으면) none 출력

	return 0;
}