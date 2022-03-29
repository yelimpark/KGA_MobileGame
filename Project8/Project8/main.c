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
		if (substr[j] == 0) return &str[i-j];
		
		if (str[i] == substr[j]) { j++; }
		else { j = 0; }
	}

	return NULL;
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

	char str[] = "Poket Monster Sun And Moon Master";
	size_t sz = mystrlen(str);
	printf("길이 : %llu\n", sz);
	printf("길이 : %llu\n", sz);

	const char* res = strchr(str, 'M');
	printf("찾은 위치 : %s\n", res);
	const char* res2 = mystrchr(str, 'M');
	printf("찾은 위치 : %s\n", res2);

	const char* res3 = strrchr(str, 'M');
	printf("찾은 위치 : %s\n", res3);
	const char* res4 = mystrrchr(str, 'M');
	printf("찾은 위치 : %s\n", res4);

	const char* res5 = strstr(str, "Sun");
	printf("찾은 위치 : %s\n", res5);
	const char* res6 = mystrstr(str, "Sun");
	printf("찾은 위치 : %s\n", res6);


}