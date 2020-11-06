#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	char str[101];
	int wordNum = 0;
	char word[100][21];
	gets(str);

	char* p, * q;
	p = q = str;
	for (p = str; *p != '\0'; p++)
	{
		if (*p == ' ')
		{
			*p = '\0';
			strcpy(word[wordNum], q);
			q = p + 1;
			wordNum++;
		}
	}
	strcpy(word[wordNum], q);
	wordNum++;

	char checkWord[21];
	scanf("%s", checkWord);

	int max = 0;
	int maxIndex = 0;

	for (int i = 0; i < wordNum; i++)
	{
		int cnt = 0;
		char shortStr[101];
		char longStr[101];

		if (strlen(word[i]) > strlen(checkWord))
		{
			strcpy(shortStr, checkWord);
			strcpy(longStr, word[i]);
		}
		else
		{
			strcpy(shortStr, word[i]);
			strcpy(longStr, checkWord);
		}

		//1글자~ 두 문자열 중 길이가 짧은 것의 글자수까지 비교
		for (int j = 0; j < strlen(shortStr); j++)
		{
			char* l = longStr;
			while (*(l+j) != '\0')
			{
				char* s = shortStr;
				while (*(s+j) != '\0')
				{
					if (strncmp(l,s, j+1) == 0)
					{
						cnt = j;
					}
					s++;
				}
				l++;
			}
		}
		if (cnt > max)
		{
			max = cnt;
			maxIndex = i;
		}
		else if (cnt == max) {
			if (strcmp(word + maxIndex, word + i) > 0) {
				maxIndex = i;
			}
		}
	}

	printf("%s\n", word[maxIndex]);

	return 0;
}