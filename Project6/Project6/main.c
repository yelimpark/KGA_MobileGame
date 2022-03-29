#include <stdio.h>
#include <string.h>

// ���� �迭 ����, �ε�
// 1. ���� �߰�
// 2. ���� �迭 ���
// 3. ���� ����
// 4. ���� �ε�

void Add(int array[], int* count, int add);
void Print(int array[], int count);

int Save(const char* path, int array[], int count);
int Load(const char* path, int array[], int* count);

void FileIO() {
	const char* filePath = "save.txt";
	int intArray[1024];
	int intArrayCount = 0;
	int loop = 1;
	while (loop)
	{
		printf("1. �߰� 2. ��� 3. ���� 4. �ε� 0. ����: ");
		int cmd = 0;
		scanf_s("%d", &cmd);

		switch (cmd)
		{
		case 0:
			loop = 0;
			break;
		case 1:
		{
			int number = 0;
			scanf_s("%d", &number);
			Add(intArray, &intArrayCount, number);
		}
		break;
		case 2:
			Print(intArray, intArrayCount);
			break;
		case 3:
			Save(filePath, intArray, intArrayCount);
			break;
		case 4:
			Load(filePath, intArray, &intArrayCount);
			break;
		default:
			printf("�ٽ� �Է�!\n");
			break;
		}
	}
	printf("��\n");
}

//���� 4
void CountWord(const char* path) {
	FILE* stream;
	errno_t err = fopen_s(&stream, path, "rt");
	if (err != 0)
		return 0;

	int countA = 0, countP = 0;
	char buffer[50];
	int ctn;

	while (1) {
		ctn = fscanf_s(stream, "%s", buffer, (int)(sizeof(buffer) / sizeof(char)));
		if (ctn == EOF)
			break;

		if (buffer[0] == 'A') countA++;
		else if (buffer[0] == 'P') countP++;
	}

	fclose(stream);

	printf("A�� �����ϴ� �ܾ��� �� : %d\n", countA);
	printf("P�� �����ϴ� �ܾ��� �� : %d\n", countP);
}

//���� 5
int IsSameText(const char* path1, const char* path2) {
	FILE* stream1, * stream2;
	errno_t err1 = fopen_s(&stream1, path1, "rt");
	errno_t err2 = fopen_s(&stream2, path2, "rt");
	if (err1 != 0 || err2 != 0)
	{
		return 0;
	}

	int ch1, ch2;
	while (1) {
		ch1 = fgetc(stream1);
		ch2 = fgetc(stream2);
		if (ch1 != ch2) {
			return 0;
		}
		if (ch1 == EOF && ch2 == EOF) {
			break;
		}
	}
	return 1;
}

//����1
typedef struct book
{
	char title[50];
	char auther[50];
	int page;
} Book;

void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = 0;
}

void ClearReadBuffer(void) {
	while (getchar() != '\n');
}

void GetBook(Book * book) {
	printf("����: ");
	fgets(book->auther, (int)sizeof(book->auther), stdin);
	RemoveBSN(&book->auther);
	printf("����: ");
	fgets(book->title, (int)sizeof(book->title), stdin);
	RemoveBSN(&book->title);
	printf("��������: ");
	scanf_s("%d", &(book->page));
	ClearReadBuffer();
}

void PrintBook(Book book) {
	printf("����: %s\n", book.auther);
	printf("����: %s\n", book.title);
	printf("��������: %d\n", (book.page));
}

//���� 3

typedef struct complexNum {
	float real;
	float imaginary;
}ComplexNum;

ComplexNum AddComplexNum(ComplexNum cn1, ComplexNum cn2) {
	ComplexNum res = {0};
	res.real = cn1.real + cn2.real;
	res.imaginary = cn1.imaginary + cn2.imaginary;
	return res;
}

ComplexNum MultComplexNum(ComplexNum cn1, ComplexNum cn2) {
	ComplexNum res = { 0 };
	res.real = cn1.real * cn2.real - 
		cn1.imaginary * cn2.imaginary;
	res.imaginary = cn1.imaginary * cn2.real +
		cn1.real * cn2.imaginary;
	return res;
}

void ShowComplexNum(ComplexNum cn) {
	printf("�Ǽ� : %f, ��� : %f\n", cn.real, cn.imaginary);
}

int main(int argc, char *argv[])
{
	//FileIO();
	//CountWord(argv[1]);

	//if (IsSameText(argv[2], argv[3])) {
	//	printf("same\n");
	//}
	//else {
	//	printf("Diffrent\n");
	//}

	Book arr[3] = {0};
	printf("���� ���� �Է�\n");
	for (int i = 0; i < (int)(sizeof(arr) / sizeof(Book)); i++) {
		GetBook(&arr[i]);
	}
	printf("\n���� ���� ���\n");
	for (int i = 0; i < (int)(sizeof(arr) / sizeof(Book)); i++) {
		PrintBook(arr[i]);
	}

	ComplexNum cn1, cn2, res1, res2;
	printf("���Ҽ� �Է�1 [�Ǽ�, ���] :");
	scanf_s("%f %f", &cn1.real, &cn1.imaginary);
	printf("���Ҽ� �Է�2 [�Ǽ�, ���] :");
	scanf_s("%f %f", &cn2.real, &cn2.imaginary);

	printf("���� ��� ] ");
	ShowComplexNum(AddComplexNum(cn1, cn2));
	printf("���� ��� ] ");
	ShowComplexNum(MultComplexNum(cn1, cn2));


	return 0;
}

void Add(int array[], int* count, int add)
{
	array[(*count)++] = add;
}

void Print(int array[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int Save(const char* path, int array[], int count)
{
	FILE* stream;
	errno_t err = fopen_s(&stream, path, "wt");
	if (err != 0)
	{
		return 0;
	}

	fprintf(stream, "%d\n", count);
	for (int i = 0; i < count; i++)
		fprintf(stream, "%d ", array[i]);

	fclose(stream);
	return 1;
}

int Load(const char* path, int array[], int* count)
{
	FILE* stream;
	errno_t err = fopen_s(&stream, path, "rt");
	if (err != 0)
	{
		return 0;
	}

	fscanf_s(stream, "%d", count);
	for (int i = 0; i < *count; i++) {
		fscanf_s(stream, "%d", &array[*count]);
	}

	fclose(stream);
	return 1;
}