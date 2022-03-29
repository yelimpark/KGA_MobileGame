#include <stdio.h>
#include <string.h>

// 정수 배열 저장, 로드
// 1. 정수 추가
// 2. 정수 배열 출력
// 3. 정수 저장
// 4. 정수 로드

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
		printf("1. 추가 2. 출력 3. 저장 4. 로드 0. 종료: ");
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
			printf("다시 입력!\n");
			break;
		}
	}
	printf("끝\n");
}

//도전 4
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

	printf("A로 시작하는 단어의 수 : %d\n", countA);
	printf("P로 시작하는 단어의 수 : %d\n", countP);
}

//도전 5
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

//도전1
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
	printf("저자: ");
	fgets(book->auther, (int)sizeof(book->auther), stdin);
	RemoveBSN(&book->auther);
	printf("제목: ");
	fgets(book->title, (int)sizeof(book->title), stdin);
	RemoveBSN(&book->title);
	printf("페이지수: ");
	scanf_s("%d", &(book->page));
	ClearReadBuffer();
}

void PrintBook(Book book) {
	printf("저자: %s\n", book.auther);
	printf("제목: %s\n", book.title);
	printf("페이지수: %d\n", (book.page));
}

//도전 3

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
	printf("실수 : %f, 허수 : %f\n", cn.real, cn.imaginary);
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
	printf("도서 정보 입력\n");
	for (int i = 0; i < (int)(sizeof(arr) / sizeof(Book)); i++) {
		GetBook(&arr[i]);
	}
	printf("\n도서 정보 출력\n");
	for (int i = 0; i < (int)(sizeof(arr) / sizeof(Book)); i++) {
		PrintBook(arr[i]);
	}

	ComplexNum cn1, cn2, res1, res2;
	printf("복소수 입력1 [실수, 허수] :");
	scanf_s("%f %f", &cn1.real, &cn1.imaginary);
	printf("복소수 입력2 [실수, 허수] :");
	scanf_s("%f %f", &cn2.real, &cn2.imaginary);

	printf("합의 결과 ] ");
	ShowComplexNum(AddComplexNum(cn1, cn2));
	printf("곱의 결과 ] ");
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