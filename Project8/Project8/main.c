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

	char str[] = "Poket Monster Sun And Moon Master";
	size_t sz = mystrlen(str);
	printf("���� : %llu\n", sz);
	printf("���� : %llu\n", sz);

	const char* res = strchr(str, 'M');
	printf("ã�� ��ġ : %s\n", res);
	const char* res2 = mystrchr(str, 'M');
	printf("ã�� ��ġ : %s\n", res2);

	const char* res3 = strrchr(str, 'M');
	printf("ã�� ��ġ : %s\n", res3);
	const char* res4 = mystrrchr(str, 'M');
	printf("ã�� ��ġ : %s\n", res4);

	const char* res5 = strstr(str, "Sun");
	printf("ã�� ��ġ : %s\n", res5);
	const char* res6 = mystrstr(str, "Sun");
	printf("ã�� ��ġ : %s\n", res6);


}