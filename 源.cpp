#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "123456";
	char b[20] = { 0 };
	loop:
	printf("����������:\n");
	scanf("%s", b);
	gets_s(b);
	if(strcmp(a, b) == 0)
	{
		printf("������ȷ����½�ɹ���\n");
	}
	else
	{
		printf("����������������룡\n");
		goto loop;
	}
	int i = 0;
	while ((b[i++] = getchar()) != '\n');
		b[i - 1] = '\0';
	if (strcmp(b, a) == 0)
		printf("������ȷ\n");
	return 0;
}

		����һ�������������������ʽ�����루�������ڴ��У�����1�ĸ���
#include<stdlib.h>

int count_bit_one(int input)
int count_bit_one(unsigned int input) // ֱ��unsigned int
{
	int count = 0;
	while (input)
	{		// �������⣬��inputΪ����ʱ���޷���������
	 -1 100000000000000000000000000001 ԭ
	    111111111111111111111111111110 ��
	    111111111111111111111111111111 ��
	  �����俪ͷ1����Ϊ����λ������Ϊ�޷�������ÿһλ����Ч������Խ��м���
		  ����  ԭ������ͬ
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
		if ((input & 1) == 1) //  input��λ��1�������1��count+1�����������λ��
		{
			count++;	//  ÿ�ζ�Ҫѭ��32��
		}
		input >>= i;//  ������λ��
		input = input >> i;
	}
	return count;
}

int count_bit_one(int input)
{	//  ��򣬸�Ч
	int count = 0;
	while (input)
	{
		input = input & (input - 1);
		count++;
	}
	 n = 1101 13    n - 1=  1100 12  ��λ�� 1100
	 n = 1100       n - 1=  1011	   ��λ�� 1000
	 n = 1000		  n - 1=  0111	   ��λ�� 0000
			ÿ�ΰ�λ�� ���ұߵ� 1 ��ʧ�� �������˼��ΰ�λ�룬���м��� 1
	return count;
}

int main()
{
	int input = 0;
	scanf("%d", &input);
	int count = count_bit_one(input);
	printf("һ����:%d ", count);
	system("pause");//ִ��ϵͳ���� - pause��ͣ ͷ�ļ�stdlib.h(���û���޸����Դ����޷�ֹͣʱд��)
	return 0;
}

			�����������������������Ķ�����λ�ж��ٸ�λ��ͬ
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
		count++;//  ����д��һ������
	}	
	printf("����%d��ͬ", count);
	return 0;
}

			����һ����������ӡ���������λ��ż��λ������λ

void print(int input)
{
	int i = 0;
	printf("����λ:");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (input >> i) & 1);
	}
	printf("\n");
	printf("ż��λ:");
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

			��ƺ����� ָ�� ��ӡ��һ����������ݣ���ʹ���±�

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