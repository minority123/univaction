#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <locale>
//x3 + x – 3, cos3(x) дихотомиями
float f(float);
float f2(float);
float integral(float(*) (float), float, float, float);

int osn1() {
	float k, p;
	k = integral(f, (float)0.0, (float)1.25, (float)0.001);   //вызов функции интеграла
	p = integral(f2, (float)0.0, (float)3.14, (float)0.001);
	std::cout << k << "\n" << p << " + PIn, n e Z";
	return 0;
}

float integral(float(*func) (float), float a, float b, float e) {    //указатель(ну типо)
	float x = 0;
	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if (func(x) * func(a) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

float f2(float x) {						//первая
	return(pow(cos(x), 3));
}
	
float f(float x) {						//вторая 
	return(pow(x, 3) + x - 3);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Написать функцию fsum с переменным числом параметров, в которой определяется сумма чисел типа int по формуле: S=a1*a2+a2*a3+a3*a4+ . . . .

int fsum(int n, ...);

void osn2() {
	using namespace std;
	cout << fsum(6, 4, 5, 1, 2, 3, 0) << endl;
	cout << fsum(2, 34, 4445) << endl;
	cout << fsum(3, 10, 20, 30) << endl;
}

int fsum(int n, ...)
{
	int* p = &n;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		p++;
		sum += *(p) * *(p + 1);
	}
	return sum;
}
//////////////////////////////////////////////////////////////////////

//Написать функцию as с переменным числом параметров, которая находит сумму чисел типа int по формуле : S = a1 * a2 - a2 * a3 + a3 * a4 - . . . . .

int as(int n, ...);

void dop1() {
	using namespace std;
	cout << as(6, 4, 5, 1, 2, 3, 0) << endl;
	cout << as(2, 34, 4445) << endl;
	cout << as(3, 10, 20, 30) << endl;
}

int as(int n, ...)
{
	int* p = &n;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		p++;
		if (i % 2 != 0)
			sum += *(p) * *(p + 1);
		else
			sum -= *(p) * *(p + 1);
	}
	return sum;
}
////////////////////////////////////////////////////////////////////////////

//Написать функцию fmin с переменным числом параметров, в которой определяется минимальное из чисел типа int. 

int fmin(int n, ...);

void dop2() {
	using namespace std;
	cout << fmin(4, 0, 3, 2, 1) << endl;
	cout << fmin(4, 3, 3, 2, 1) << endl;
	cout << fmin(4, 14, 3, 2, 6) << endl;
}

int fmin(int n, ...) {
	int* p = &n; int a = *(p + 1);
	for (int i = 1; i < n; i++) {
		p++;
		if (a >= *(p + 1))
			a = *(p + 1);
	}
	return a;
}
////////////////////////////////////////////////////////////////////////////////////

// удаляем пробелыыыыы

std::string compr(std::string s, ...);

void dop3() {
	using namespace std;
	string s, sx;
	getline(cin, s);
	getline(cin, sx);
	cout << compr(s);
	cout << compr(sx);
}

std::string compr(std::string s, ...) {
	using namespace std;
	setlocale(LC_ALL, "Rus");
	string s1;
	int i = 0, k = 0;
	string* p = &s;
		while (s[i])
		{
			if (s[i] == ' ') k = 1;
			if (k != 1) s1 += s[i];
			k = 0;
			i++;
		}
		s = s1;
	return s;
}
	


int main() {
	//osn1();
	osn2();
	//dop1();
	//dop2();
	//dop3();
}