#pragma warning(disable:4996)
#include<stdio.h>//all
#include<math.h>//2, 
#include<numeric>//2

using namespace std;

//1. 1~max���� 3�̳� 5�� ������ �������� �ڿ����� �� ���
int foo(int max);//�׳� �����.
int foo1(int max);//���� �� ���� ���
int foo2(int max);//O(1) ���
//2. a�� b�� �ִ������� ���Ѵ�.
int foo3(int a, int b);//���� �׳� Ǭ ��
int foo4(int const a, int const b);//����� ��Ŭ���� �˰���
int foo5(int a, int b);//������� ��Ŭ���� �˰���
int foo6(int a, int b);// c++17 numeric ���� �Լ� �̿�. ������� ��Ŭ����� �����Ǿ�����.



int main()
{
	int a, b;
	scanf("%d %d",&a, &b );


	printf("gcd: %d", foo4(a, b));
	//printf("%d������ ���� %d", max, foo2(max));
	return 0; 
}

int foo(int max)
{
	int sum = 0;
	//å������ �Ʒ��� ���� Ǯ�� cin, cout�� �̿��ߴ�. �׸��� unsigned long long ���� �ߴ�.
	//2������ �ϴ� Ȯ���� �ƴϴϱ� 3���� �Ѵ�
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
	//3�� 5�� ���س����鼭 �ϸ� �� ������ ������?
	for (int i = 3; i <= max; i += 3)
		sum += i;
	for (int i = 5; i <= max; i += 5)
		sum += i;
	//�ߺ� ����
	for (int i = 15; i <= max; i += 15)
		sum -= i;

	

	return sum;
}
int foo2(int max)
{
	//���������� �հ����� �̿��غ���
	//�̹���� �̿��ϸ� O(1) �� ����� �� �ִ�.
	//ù���� 3, ������ max-max%3, ���ǰ����� max/3�� ���������� ����
	int sum3 = (3 + max - max % 3)* (max / 3) / 2;
	//�Ȱ����� 5�� ���ؼ� �Ѵ�.
	int sum5 = (5 + max - max % 5) * (max / 5) / 2;
	//�Ȱ����� 15�� ���ؼ� �Ѵ�.
	int sum15 = (15 + max - max % 15) * (max / 15) / 2;
	
	return sum3 + sum5 - sum15;
}

int foo3(int a, int b)
{


	int gcd = 1;
	int max = a > b ? a/2 : b/2;

	if (a == b) return a;

	//�켱 ����� ���ϴ� �ͺ��� ������ �Ѵ�.
	//����� 1~n/2������ ���� ���� �� �ִ� 
	//�Ҽ��� �Ǻ��Ҷ��� ��Ʈn������ ���ϰ�
	//�ݺ��� �ѹ� ���°� �� �����ϱ� �� �������� �� ū�ű��� �ݺ��ϸ� ���� ������ �ʹ�.

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
	//constexpr�� ������Ÿ�ӿ� Ȯ�εǴ� const��� �� �� �ְڴ�.
	
	return gcd(a, b);
}