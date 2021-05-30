#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

struct content {
	char title[40];
	int price;
	double rate;

};

int main() {
	struct content* arr[100] = { NULL };
	int cnt = 0;
	int i;
	while (cnt < 100) {
		char title[40] = "";
		printf("컨텐츠를 등록합니다.(.입력 시 종료)");
		gets_s(title, sizeof(title));
		if (strcmp(title, ".") == 0) 
			break;
		arr[cnt] = (struct content*)malloc(sizeof(struct content));
		strcpy(arr[cnt]->title, title);
		printf("가격? ");
		scanf_s("%d", &arr[cnt]->price);
		arr[cnt]->rate = 5.0;
		cnt++;
		while (getchar() != '\n') {}
	}
	printf("제목        가격   평점");
	for (i = 0; i < cnt; i++) {
		printf("%-20s %5d %4.1lf\n", arr[i]->title, arr[i]->price, arr[i]->rate);

	}
	for (i = 0; i < cnt; i++) {
		free(arr[i]);
		arr[i] = NULL;
	}
}