#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int StringLenght(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char str[]);
//void is_palindrome(char str[]);

//#define EXAMPLE_1
#define EXAMPLE_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef EXAMPLE_1
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	char str[] = "Hello";
	//str[] - ��������� ����������
	//"Hello" - ��������� ���������
	cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;
#endif 

#ifdef EXAMPLE_2
	//for(int i = 0; i < 256; i++)cout << i << "\t" << char();
	
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "������� ������: "; 
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE); //��� �����������
	SetConsoleCP(866);
	cout << str << endl;
	cout << "����� ������: " << StringLenght(str)<<endl;
	cout << "����� ������: " << strlen(str)<<endl; //���������� �������
	cout << "����� ������ � ������: " << sizeof(str) << endl;
	upper_case(str);
	cout << str << endl;
	lower_case(str);
	cout << str << endl;
	shrink(str);


#endif
}
int StringLenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);  //����� �� ������������ ��������� �������
	return i;             //� ��������� ������� 0, � 0 ���-False
}

void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		if (str[i] == '�') str[i] = '�';*/
		str[i] = toupper(str[i]);
	}
}

void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}

/*void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if(str[])
	}
}*/
