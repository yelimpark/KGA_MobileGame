#include <stdio.h>

//문제 23-2
typedef struct point {
	int xpos;
	int ypos;
} Point;

typedef struct rectangle {
	Point p1;
	Point p2;
} Rectangle;

int Extent(Rectangle* r) {
	return
		((r->p2).xpos - (r->p1).xpos) *
		((r->p2).ypos - (r->p1).ypos)
		;
}

void ShowPoints(Rectangle* r) {
	printf("[%d, %d]\n", (r->p1).xpos, (r->p1).ypos);
	printf("[%d, %d]\n", (r->p2).xpos, (r->p1).ypos);
	printf("[%d, %d]\n", (r->p1).xpos, (r->p2).ypos);
	printf("[%d, %d]\n", (r->p2).xpos, (r->p2).ypos);
}

//열거형 문제
typedef enum _Month {
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec,
	MonthCount
} Month;

//ch34-3
void Write() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "simple.txt", "wt");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp);
	fputs("My name is Yoon \n", fp);

	fclose(fp);
}

void Read() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "simple.txt", "rt");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	char str[30];
	int ch = 0;

	ch = fgetc(fp);
	printf("%c \n", ch);
	ch = fgetc(fp);
	printf("%c \n", ch);

	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fgets(str, sizeof(str), fp);
	printf("%s", str);

	fclose(fp);
}

//문제 24-1
//문제 1

void MyStory() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "mtstory.txt", "wt");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	char name[10] = "0";
	char admissionNum[20] = "0";
	char phoneNum[20] = "0";

	scanf_s("%s", name, (int)(sizeof(name) / sizeof(char)));
	fputs("#이름: ", fp);
	fputs(name, fp);

	scanf_s("%s", admissionNum, (int)(sizeof(admissionNum) / sizeof(char)));
	fputs("\n#주민번호 : ", fp);
	fputs(admissionNum, fp);

	scanf_s("%s", phoneNum, (int)(sizeof(phoneNum) / sizeof(char)));
	fputs("\n#전화번호 : ", fp);
	fputs(phoneNum, fp);

	fclose(fp);
}

//문제 2
void MyStory2() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "mtstory.txt", "at");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	char favFood[20] = "0";
	char hoby[20] = "0";

	scanf_s("%s", favFood, (int)(sizeof(favFood) / sizeof(char)));
	fputs("\n#즐겨먹는 음식 : ", fp);
	fputs(favFood, fp);

	scanf_s("%s", hoby, (int)(sizeof(hoby) / sizeof(char)));
	fputs("\n#취미 : ", fp);
	fputs(hoby, fp);

	fclose(fp);
}

//문제 3
void ShowMyStory() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "mtstory.txt", "rt");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	char buf[20];

	while (fgets(buf, sizeof(buf), fp) != NULL) {
		printf("%s", buf);
	}

	fclose(fp);
}

//문제 24-2
long SizeOfFile(FILE * fp) {
	long cur = ftell(fp);
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, cur, SEEK_SET);
	return size;
}

int main() {
	//Rectangle r = { 0 };
	//do {
	//	printf("enter two cordinate (first, upper left, second bottom-right) : ");
	//	scanf_s("%d %d", &r.p1.xpos, &r.p1.ypos);
	//	scanf_s("%d %d", &r.p2.xpos, &r.p2.ypos);
	//} while (r.p1.xpos > r.p2.xpos || r.p1.ypos > r.p2.ypos);

	//ShowPoints(&r);
	//printf("넓이 : %d\n", Extent(&r));

	//for (Month i = Jan; i < MonthCount; i++) {
	//	printf("%d ", i);
	//}

	//Write();
	//Read();

	//MyStory();
	//MyStory2();
	//ShowMyStory();

	FILE* fp;
	errno_t err = fopen_s(&fp, "mtstory.txt", "rt");
	if (err != 0) {
		puts("파일 오픈 실패!");
		return -1;
	}

	printf("%ld", SizeOfFile(fp));

	return 0;
}