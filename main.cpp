#pragma warning(disable:4996)
#include<stdio.h>//all
#include<math.h>//2, 
#include<numeric>//2

using namespace std;

//1. 1~max까지 3이나 5로 나누어 떨어지는 자연수의 합 계산
int foo(int max);//그냥 계산함.
int foo1(int max);//조금 더 빠른 계산
int foo2(int max);//O(1) 계산
//2. a와 b의 최대공약수를 구한다.
int foo3(int a, int b);//내가 그냥 푼 것
int foo4(int const a, int const b);//재귀적 유클리드 알고리즘
int foo5(int a, int b);//비재귀적 유클리드 알고리즘
int foo6(int a, int b);// c++17 numeric 내장 함수 이용. 비재귀적 유클리드로 구현되어있음.



int main()
{
	int a, b;
	scanf("%d %d",&a, &b );


	printf("gcd: %d", foo4(a, b));
	//printf("%d까지의 합은 %d", max, foo2(max));
	return 0; 
}

int foo(int max)
{
	int sum = 0;
	//책에서는 아래와 같이 풀고 cin, cout을 이용했다. 그리고 unsigned long long 으로 했다.
	//2까지는 일단 확실히 아니니까 3부터 한다
	for (int i = 3; i <= max; i++)
	{
		if (i % 3 ==0 || i % 5 ==0)
			sum += i;
	}

	return sum;
	
}
int foo1(int max)
{
	int sum = 0;
	//3씩 5씩 더해나가면서 하면 더 빠르지 않을까?
	for (int i = 3; i <= max; i += 3)
		sum += i;
	for (int i = 5; i <= max; i += 5)
		sum += i;
	//중복 제거
	for (int i = 15; i <= max; i += 15)
		sum -= i;

	

	return sum;
}
int foo2(int max)
{
	//등차수열의 합공식을 이용해보자
	//이방법을 이용하면 O(1) 에 계산할 수 있다.
	//첫항이 3, 끝항이 max-max%3, 항의개수가 max/3인 등차수열의 합은
	int sum3 = (3 + max - max % 3)* (max / 3) / 2;
	//똑같은걸 5에 대해서 한다.
	int sum5 = (5 + max - max % 5) * (max / 5) / 2;
	//똑같은걸 15에 대해서 한다.
	int sum15 = (15 + max - max % 15) * (max / 15) / 2;
	
	return sum3 + sum5 - sum15;
}

int foo3(int a, int b)
{


	int gcd = 1;
	int max = a > b ? a/2 : b/2;

	if (a == b) return a;

	//우선 약수를 구하는 것부터 만들어야 한다.
	//약수는 1~n/2까지만 돌면 구할 수 있다 
	//소수를 판별할때는 루트n까지면 족하가
	//반복을 한번 도는게 더 빠르니까 두 제곱근중 더 큰거까지 반복하면 되지 않을까 싶다.

	for (int i = 1; i <= max; i++)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
			
	}

	return gcd;
}

int foo4(int a, int b)
{
	return b == 0 ? a : foo4(b, a % b);
}

int foo5(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}
int foo6(int a, int b)
{
	//https://docs.microsoft.com/ko-kr/cpp/cpp/constexpr-cpp?view=msvc-160
	//constexpr은 컴파일타임에 확인되는 const라고 할 수 있겠다.
	
	return gcd(a, b);
}