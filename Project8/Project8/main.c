
#define _CRT_SECURE_NO_WARNINGS

// C 라이브러리를 배워봅시다.
// 단정문을 위한 라이브러리
// 단정문 (assertion) : 조건을 검사할 때 사용하는 구문
#include <assert.h>

// 표준 입출력 라이브러리
#include <stdio.h>

// 문자열 다루는 라이브러리
#include <string.h>


struct Player
{
	char name[10];
	int hp;
};

// 시스템적으로 HP가 0이하일땐 호출이 되면 안됨
int Die(struct Player* const player) {
	// 단정문은 DEBUG 모드에서만 동작
	// 반드시 만족해야하는 조건이어야 할 때 사용
	// 이런 일이 일어나면 안된다
	assert(player->hp > 0);
	printf("죽었습니다.\n");
}

size_t mystrlen(const char* str) {
	size_t i;
	for (i = 0; str[i] != 0; i++) {	}
	return i;
}

char* mystrchr(const char* str, char ch) {
	for (char * cp = str; *cp != 0; cp++) {
		if (*cp == ch) return cp;
	}
	return NULL;
}

char* mystrrchr(const char* str, int ch) {
	char* cp = NULL;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == ch) cp = &str[i];
	}
	return cp;
}

/// <summary>
/// 문자열에서 문자열을 찾아줌
/// </summary>
/// <param name="str"></param>
/// <param name="substr"></param>
/// <returns></returns>
char* mystrstr(const char* str, const char* substr) {
	if (*substr == NULL) return str;

	int j = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == substr[j]) { j++; }
		else { j = 0; }

		if (substr[j] == 0) return &str[i - j + 1];
	}

	return NULL;
}

int mystrcmp(const char* str1, const char* str2) {
	int i;
	for (i = 0; str1[i] != 0 && str2[i] != 0; i++) {
		if (str1[i] < str2[i]) return -1;
		else if (str1[i] > str2[i]) return 1;
	}
	if (str1[i] != 0) return 1;
	if (str2[i] != 0) return -1;
	return 0;
};

char* mystrtok(char* str, const char* deli) {
	if (*deli == NULL) return str;

	char* res;
	static char* tmp;

	if (str == NULL) res = tmp;
	else res = str;

	if (res == NULL) return NULL;

	while (1) {
		int isNotDeli = 1;
		for (int j = 0; deli[j] != 0; j++) {
			if (*res == deli[j]) {
				res++;
				isNotDeli = 0;
			}
		}
		if (isNotDeli) break;
	}

	for (int i = 0; res[i] != 0; i++) {
		for (int j = 0; deli[j] != 0; j++) {
			if (res[i] == deli[j]) {
				res[i] = '\0';
				tmp = &res[i + 1];
				return res;
			}
		}

		if (res[i + 1] == 0) tmp = NULL;
	}

	return res;
}

char* mystrtok2(char* str, const char* deli) {
	if (*deli == NULL) return str;

	char* res;
	static char* tmp;

	if (str == NULL) res = tmp;
	else res = str;

	if (res == NULL) return NULL;

	for (int i = 0; res[i] != 0; i++) {
		for (int j = 0; deli[j] != 0; j++) {
			if (res[i] == deli[j]) {
				res[i] = '\0';
				tmp = &res[i + 1];
				return res;
			}
		}

		if (res[i + 1] == 0) {
			tmp = NULL;
		}
	}

	return res;
}

int main() {
	struct Player player;
	player.hp = 0;
	/*Die(&player);*/

	int age = 0;
	//scanf의 bufferoverrun 공격에 취약한 점을 보완
	//scanf_s("체력 : %d", &age);
	//sscanf_s("체력 : 10", "체력 : %d", &age);

	// 파일은 2가지로 분류된다.
	// (1) 텍스트 파일 : 우리가 읽을 수 있는 텍스트로 이뤄진 파일.
	// 텍스트파일은 인코딩에 주의해야 한다.
	// (2) 바이너리 파일 : 이진수로 이뤄진 파일. 헥스 에디터를 통해 편집 가능
	// 바이너리 파일은 보통 뒤에 .bim 을 붙인다
	// visual studio 같은 경우는 상대 경로의 기준점이 프로젝트 파일이다.

	// FILE* fp = fopen("temp.txt", "r");
	// fclose(fp);

	//struct Player player2;
	//player2.hp = 0;
	//// 선언하면서 초기화하지 않은 문자열을 strcpy로 초기화해줬다
	//strcpy(player2.name, "pokemon");

	//const char* str = "Hello";

	//assert(5 == strlen(str));
	//assert(0 == strlen(""));

	//assert(str + 2 == strchr(str, 'l'));
	//assert(NULL == strchr(str, 'a'));

	//assert(str + 3 == strrchr(str, 'l'));
	//assert(NULL == strrchr(str, 'a'));

	//assert(str + 1 == strstr(str, "ell"));
	//assert(str == strstr(str, ""));
	//assert(NULL == strstr(str, "World"));

	//assert(0 > strcmp(str, "Hello!"));
	//assert(0 == strcmp(str, str));
	//assert(0 < strcmp(str, "Hallo"));

	//char str2[] = "A bird came down the walk";
	//assert(0 == strcmp("A", strtok(str2, " ")));
	//assert(0 == strcmp("bird", strtok(NULL, " ")));
	//assert(0 == strcmp("came", strtok(NULL, " ")));
	//assert(0 == strcmp("down", strtok(NULL, " ")));
	//assert(0 == strcmp("the", strtok(NULL, " ")));
	//assert(0 == strcmp("walk", strtok(NULL, " ")));
	//assert(NULL == strtok(NULL, " "));

	//char str3[] = "A,bird camezdown the walk";
	//assert(0 == strcmp("A", strtok(str3, ", z")));
	//assert(0 == strcmp("bird", strtok(NULL, ", z")));
	//assert(0 == strcmp("came", strtok(NULL, ", z")));
	//assert(0 == strcmp("down", strtok(NULL, ", z")));
	//assert(0 == strcmp("the", strtok(NULL, ", z")));
	//assert(0 == strcmp("walk", strtok(NULL, ", z")));
	//assert(NULL == strtok(NULL, ", z"));

	const char* str = "Hello";

	assert(5 == mystrlen(str));
	assert(0 == mystrlen(""));

	assert(str + 2 == mystrchr(str, 'l'));
	assert(NULL == mystrchr(str, 'a'));

	assert(str + 3 == mystrrchr(str, 'l'));
	assert(NULL == mystrrchr(str, 'a'));

	assert(str + 1 == mystrstr(str, "ell"));
	assert(str == mystrstr(str, ""));
	assert(NULL == mystrstr(str, "World"));

	assert(0 > mystrcmp(str, "Hello!"));
	assert(0 == mystrcmp(str, str));
	assert(0 < mystrcmp(str, "Hallo"));

	char str2[] = "A bird came down the walk";
	assert(0 == mystrcmp("A", mystrtok(str2, " ")));
	assert(0 == mystrcmp("bird", mystrtok(NULL, " ")));
	assert(0 == mystrcmp("came", mystrtok(NULL, " ")));
	assert(0 == mystrcmp("down", mystrtok(NULL, " ")));
	assert(0 == mystrcmp("the", mystrtok(NULL, " ")));
	assert(0 == mystrcmp("walk", mystrtok(NULL, " ")));
	assert(NULL == mystrtok(NULL, " "));

	char str3[] = "A,,bird camezdown the walk";
	assert(0 == mystrcmp("A", mystrtok(str3, ", z")));
	assert(0 == mystrcmp("bird", mystrtok(NULL, ", z")));
	assert(0 == mystrcmp("came", mystrtok(NULL, ", z")));
	assert(0 == mystrcmp("down", mystrtok(NULL, ", z")));
	assert(0 == mystrcmp("the", mystrtok(NULL, ", z")));
	assert(0 == mystrcmp("walk", mystrtok(NULL, ", z")));
	assert(NULL == mystrtok(NULL, ", z"));

	return 0;

}