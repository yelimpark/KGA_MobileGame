
#define _CRT_SECURE_NO_WARNINGS

// C ���̺귯���� ������ô�.
// �������� ���� ���̺귯��
// ������ (assertion) : ������ �˻��� �� ����ϴ� ����
#include <assert.h>

// ǥ�� ����� ���̺귯��
#include <stdio.h>

// ���ڿ� �ٷ�� ���̺귯��
#include <string.h>


struct Player
{
	char name[10];
	int hp;
};

// �ý��������� HP�� 0�����϶� ȣ���� �Ǹ� �ȵ�
int Die(struct Player* const player) {
	// �������� DEBUG ��忡���� ����
	// �ݵ�� �����ؾ��ϴ� �����̾�� �� �� ���
	// �̷� ���� �Ͼ�� �ȵȴ�
	assert(player->hp > 0);
	printf("�׾����ϴ�.\n");
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
/// ���ڿ����� ���ڿ��� ã����
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
	//scanf�� bufferoverrun ���ݿ� ����� ���� ����
	//scanf_s("ü�� : %d", &age);
	//sscanf_s("ü�� : 10", "ü�� : %d", &age);

	// ������ 2������ �з��ȴ�.
	// (1) �ؽ�Ʈ ���� : �츮�� ���� �� �ִ� �ؽ�Ʈ�� �̷��� ����.
	// �ؽ�Ʈ������ ���ڵ��� �����ؾ� �Ѵ�.
	// (2) ���̳ʸ� ���� : �������� �̷��� ����. �� �����͸� ���� ���� ����
	// ���̳ʸ� ������ ���� �ڿ� .bim �� ���δ�
	// visual studio ���� ���� ��� ����� �������� ������Ʈ �����̴�.

	// FILE* fp = fopen("temp.txt", "r");
	// fclose(fp);

	//struct Player player2;
	//player2.hp = 0;
	//// �����ϸ鼭 �ʱ�ȭ���� ���� ���ڿ��� strcpy�� �ʱ�ȭ�����
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