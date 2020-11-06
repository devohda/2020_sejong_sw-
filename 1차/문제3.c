#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int changeWord(char* word) { //단어를 숫자로 바꾸는 함수

	int sum = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		//단어 한 개 숫자로 변환
		int num = word[i] - 'a' + 1;

		//숫자를 더하기
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

	//단어 2개 입력 받기
	scanf("%s%s", word1, word2);

	//첫 번째 단어 숫자로 변환하기
	sum1 = changeWord(word1);

	//두 번째 단어 숫자로 변환하기
	sum2 = changeWord(word2);

	//덧셈 후 출력
	printf("%d\n", sum1 + sum2);

	return 0;
}