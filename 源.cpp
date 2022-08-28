#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "123456";
	char b[20] = { 0 };
	loop:
	printf("请输入密码:\n");
	scanf("%s", b);
	gets_s(b);
	if(strcmp(a, b) == 0)
	{
		printf("密码正确，登陆成功！\n");
	}
	else
	{
		printf("密码错误，请重新输入！\n");
		goto loop;
	}
	int i = 0;
	while ((b[i++] = getchar()) != '\n');
		b[i - 1] = '\0';
	if (strcmp(b, a) == 0)
		printf("密码正确\n");
	return 0;
}

		输入一个数，返回其二进制形式（补码（存在于内存中））里1的个数
#include<stdlib.h>

int count_bit_one(int input)
int count_bit_one(unsigned int input) // 直接unsigned int
{
	int count = 0;
	while (input)
	{		// 存在问题，当input为负数时，无法正常运行
	 -1 100000000000000000000000000001 原
	    111111111111111111111111111110 反
	    111111111111111111111111111111 补
	  ：将其开头1不看为符号位，则其为无符号数，每一位都有效，则可以进行计算
		  正数  原反补相同
		if (input % 2 == 1)
		{
			count++;
		}
		input /= 2;
	}
	return count;
}

int count_bit_one(int input)
{
	int count = 0;
	int i;
	for(i=0;i<32;i++)
	{
		if ((input & 1) == 1) //  input按位与1，如果是1则count+1，否则继续按位与
		{
			count++;	//  每次都要循环32次
		}
		input >>= i;//  继续按位与
		input = input >> i;
	}
	return count;
}

int count_bit_one(int input)
{	//  最精简，高效
	int count = 0;
	while (input)
	{
		input = input & (input - 1);
		count++;
	}
	 n = 1101 13    n - 1=  1100 12  按位与 1100
	 n = 1100       n - 1=  1011	   按位与 1000
	 n = 1000		  n - 1=  0111	   按位与 0000
			每次按位与 最右边的 1 消失， 最后进行了几次按位与，则有几个 1
	return count;
}

int main()
{
	int input = 0;
	scanf("%d", &input);
	int count = count_bit_one(input);
	printf("一共有:%d ", count);
	system("pause");//执行系统命令 - pause暂停 头文件stdlib.h(如果没有修改属性代码无法停止时写入)
	return 0;
}

			输入两个数，求这两个数的二进制位有多少个位不同
int main()
{
	int input1, input2;
	scanf("%d%d", &input1, &input2);
	int num = input1 ^ input2;
	int count = 0;
	  1999 011111001111
	  2000 011111010000
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	while (num)
	{
		num = num & (num - 1);
		count++;//  可以写成一个函数
	}	
	printf("共有%d不同", count);
	return 0;
}

			输入一个整数，打印出其二进制位的偶数位和奇数位

void print(int input)
{
	int i = 0;
	printf("奇数位:");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (input >> i) & 1);
	}
	printf("\n");
	printf("偶数位:");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d", (input >> i) & 1);
	}
}
int main()
{
	int input = 0;
	scanf("%d", &input);
	print(input);
	return 0;
}

			设计函数用 指针 打印出一个数组的内容，不使用下标

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		/*printf("%d ", *arr);
		arr += 1;*/
		printf("%d ", *(arr + i));
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,7,0,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}