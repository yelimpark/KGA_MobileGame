#include <stdio.h>

int lv1p1(void) {
	printf("Hello World!\n");
	return 0;
}

int lv1p2(void) {
	printf("강한친구 대한육군\n강한친구 대한육군\n");
	return 0;
}

int lv1p3(void) {
	printf("\\    /\\\n )  ( ')\n(  /  )\n \\(__)|\n");
	return 0;
}

int lv1p4(void) {
	printf("|\\_/|\n|q p|   /}\n( 0 )\"\"\"\\\n|\" ^ \"`  |\n||_/=\\\\__|\n");
	return 0;
}

int lv1p5(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d", a + b);
	return 0;
}

int lv1p6(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d", a - b);
	return 0;
}

int lv1p7(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d", a * b);
	return 0;
}

int lv1p8(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	if (b == 0)
		return 0;
	printf("%f", (double)a / b);
	return 0;
}

int lv1p9(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	if (b == 0)
		return 0;
	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d\n", a % b);

	return 0;
}

int lv1p10(void) {
	char s1[50];
	scanf_s("%s", &s1, 50);
	printf("%s%s",s1,"\?\?!");
	return 0;
}

int lv1p11(void) {
	int year = 0;
	scanf_s("%d", &year);
	printf("%d", year-543);
	return 0;
}

int lv1p12(void) {
	int a = 0, b = 0, c = 0;
	scanf_s("%d %d %d", &a, &b, &c);
	printf("%d\n", (a + b)%c);
	printf("%d\n", ((a%c)+(b%c))%c);
	printf("%d\n", (a*b)%c);
	printf("%d\n", ((a%c)*(b%c))%c);

	return 0;
}

int lv1p13(void) {
	int a = 0, b = 0;
	int num1 = 0, num2 = 0, num3 = 0;

	scanf_s("%d %d", &a, &b);
	num1 = a * (b % 10);
	num2 = a * ((b/10)%10);
	num3 = a * (b / 100);

	printf("%d\n", num1);
	printf("%d\n", num2);
	printf("%d\n", num3);
	printf("%d\n", num1 + num2*10 + num3*100);

	return 0;
}

int lv2p1(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);

	if (a>b)
		printf(">");
	else if (a < b)
		printf("<");
	else
		printf("==");

	return 0;
}

int lv2p2(void) {
	int score = 0;
	scanf_s("%d", &score);

	if (score >= 90)
		printf("A");
	else if (score >= 80)
		printf("B");
	else if (score >= 70)
		printf("C");
	else if (score >= 60)
		printf("D");
	else
		printf("F");

	return 0;
}

int lv2p3(void) {
	int year = 0;
	scanf_s("%d", &year);

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}

int lv2p4(void) {
	int x = 0, y = 0;
	scanf_s("%d %d", &x, &y);

if (x > 0) {
	if (y > 0) {
		printf("1\n");
	}
	else {
		printf("4\n");
	}
}
else {
	if (y > 0) {
		printf("2\n");
	}
	else {
		printf("3\n");
	}
}

return 0;
}

int lv2p5(void) {
	int h = 0, m = 0;
	scanf_s("%d %d", &h, &m);

	if (m > 45) {
		printf("%d %d", h, m - 45);
	}
	else {
		if (h < 1) {
			printf("%d %d", h + 24 - 1, m + 60 - 45);
		}
		else {
			printf("%d %d", h - 1, m + 60 - 45);
		}
	}

	return 0;
}

int lv2p6(void) {
	int h = 0, m = 0;
	scanf_s("%d %d", &h, &m);
	int t = 0;
	scanf_s("%d", &t);

	if (h + ((m + t) / 60) >= 24) {
		printf("%d %d", h - 24 + ((m + t) / 60), (m + t) % 60);
	}
	else {

		printf("%d %d", h + ((m + t) / 60), (m + t) % 60);
	}

	return 0;
}

int lv2p7(void) {
	int d1 = 0, d2 = 0, d3 = 0;
	scanf_s("%d %d %d", &d1, &d2, &d3);

	if (d1 == d2 && d2 == d3) {
		printf("%d", 10000 + d1 * 1000);
	}
	else if (d1 == d2 || d1 == d3) {
		printf("%d", 1000 + d1 * 100);
	}
	else if (d2 == d3) {
		printf("%d", 1000 + d2 * 100);
	}
	else if (d1 > d2 && d1 > d3) {
		printf("%d", d1 * 100);
	}
	else if (d2 > d3) {
		printf("%d", d2 * 100);
	}
	else {
		printf("%d", d3 * 100);
	}

	return 0;
}

int lv3p1(void) {
	int n = 0;

	scanf_s("%d", &n);
	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", n, i, n * i);
	}

	return 0;
}

int lv3p2(void) {
	int t = 0, a = 0, b = 0;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}

int lv3p3(void) {
	int n = 0, sum = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("%d\n", sum);

	return 0;
}

int lv3p4(void) {
	int t = 0, a = 0, b = 0;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}

int lv3p5(void) {
	int n = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", i);
	}

	return 0;
}

int lv3p6(void) {
	int n = 0;
	scanf_s("%d", &n);

	for (int i = n; i > 0; i--) {
		printf("%d\n", i);
	}

	return 0;
}

int lv3p7(void) {
	int t = 0, a = 0, b = 0;
	scanf_s("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf_s("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}

	return 0;
}

int lv3p8(void) {
	int t = 0, a = 0, b = 0;
	scanf_s("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf_s("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}

	return 0;
}

int lv3p9(void) {
	int n = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

int lv3p10(void) {
	int n = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

int lv3p11(void) {
	int n = 0, x = 0, a = 0;
	scanf_s("%d %d", &n, &x);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		if (a < x)
			printf("%d ", a);
	}

	return 0;
}

int lv4p1(void) {
	int a = 0, b = 0;

	while (1) {
		scanf_s("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		printf("%d\n", a + b);
	}

	return 0;
}

int lv4p2(void) {
	int a = 0, b = 0;

	while (scanf_s("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}

	return 0;
}

int lv4p3(void) {
	int num = 0, new = 0, count=1;

	scanf_s("%d", &num);
	new = ((num % 10) + (num / 10))%10 + (num % 10) * 10;


	while (num != new) {
		new = ((new % 10) + (new / 10))%10 + (new % 10) * 10;
		count++;
	}

	printf("%d", count);

	return 0;
}

int main()
{
	//lv1p1();
	//lv1p2();
	//lv1p3();
	//lv1p4();
	//lv1p5();
	//lv1p6();
	//lv1p7();
	//lv1p8();
	//lv1p9();
	//lv1p10();
	//lv1p11();
	//lv1p12();
	//lv1p13();


	//if
	//lv2p1();
	//lv2p2();
	//lv2p3();
	//lv2p4();
	//lv2p5();
	//lv2p6();
	//lv2p7();

	//for
	//lv3p1();
	//lv3p2();
	//lv3p3();
	//lv3p4();
	//lv3p5();
	//lv3p6();
	//lv3p7();
	//lv3p8();
	//lv3p9();
	//lv3p10();
	//lv3p11();

	//while
	//lv4p1();
	//lv4p2();
	//lv4p3();

	return 0;
}