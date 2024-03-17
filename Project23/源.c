#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a[5], * p;
//	for (int i =a; i <a+ 5; i++)
//	{
//		scanf("%d", p);
//	}
//	for (int j = a; j < a + 5; j++)
//	{
//		printf("%d", j);
//
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[5], * p = NULL, i=0;
//	p = a;
//	for (int i=0;i<5;i++)
//	{
//		scanf("%d", p+i);
//	}
//	for (int j = 0; j < 5; j++)
//	{
//		printf("%d",*(p+j));
//	}
//	return 0;
//}
//#include<stdio.h>
//void Inoutarray(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", (a + i));
//
//	}
//}
//void Outarry(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d", *(a + i));
//	}
//	}
//int main()
//{
//	int a[5];
//	int n = sizeof(a) / sizeof(a[0]);
//	Inoutarray(a, n);
//	Outarry(a, n);
//	return 0;
//}
//#include<stdio.h>
//#define N 4
//
//void InputArray(int p[][N], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &p[i][j]);
//		}
//
//			
//	}
//}
//void OutputArray(int p[][N], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//
//		{
//			printf("%d  ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a[3][4];
//	InputArray(a, 3, 4);
//	OutputArray(a, 3, 4);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int arr[5] = { 0 };
//    for (int i = 0; i < 5; i++)
//    {
//        arr[i] = getchar() + 4;
//    }
//    for (int j = 0; j < 5; j++)
//    {
//        printf("%c", arr[j]);
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    int arr[4] = { 0 };
//    for (int i = 0; i < 4; i++)
//    {
//        int b = a % 10;
//        arr[i] = b;
//        a = a / 10;
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        arr[i] = (arr[i] + 9) % 10;
//    }
//    int c = 0;
//    c = arr[1];
//    arr[1] = arr[2];
//    arr[2] = c;
//
//    for (int j = 3; j >= 0; j--)
//    {
//        printf("%d", arr[j]);
//    }
//
//
//
//    return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
    double d, p;
    double r;
    scanf("%lf,%lf,%lf", &d, &p, &r);
    double m = (log10(p) - log10(p - d * r)) / log10(1 + r);
    printf("%.1f", m);

    return 0;
}
