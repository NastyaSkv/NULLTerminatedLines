/*����������� ��������� ������� :
void to_upper(char str[]);	//��������� ������ � ������� �������
void to_lower(char str[]);	//��������� ������ � ������ �������
void shrink(char str[]);	//������� ������ ������� �� �����������
bool is_palindrome(const char str[]);	//���������, �������� �� ������ �����������
bool is_int_number(const char str[]);	//���������, �������� �� ������ ����� ���������� ������
int  to_int_number(char str[]);			//���� ������ �������� ����� ���������� ������, ���������� �� �������� ��������
bool is_bin_number(const char str[]);	//���������, �������� �� ������ �������� ������
int  bin_to_dec(char str[]);			//���� ������ �������� �������� ������, ���������� �� ���������� ��������

bool is_hex_number(const char str[]);	//���������, �������� �� ������ ����������������� ������
int  hex_to_dec(char str[]);			//���� ������ �������� ����������������� ������, ���������� �� ���������� ��������*/

#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int  to_int_number(char str[]);
bool is_bin_number(const char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(const char str[]);

void main()
{
	setlocale(LC_ALL, "");

	const int SIZE = 20;
	char str[SIZE] = {};

	cout << "������� ������: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);

	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	cout << "������: " << (is_palindrome(str) ? "" : "�� ") << "���������" << endl;
	cout << str << endl << "---" << endl;
	cout << "������: " << (is_int_number(str) ? "" : "�� ") << "�������� ����� ���������� ������" << endl;
	if (is_int_number(str))cout << "�������� ��������: " << to_int_number(str) << endl;
	cout << "������: " << (is_bin_number(str) ? "" : "�� ") << "�������� �������� ������" << endl;
	if (is_bin_number(str))cout << "� ���������� �������: " << bin_to_dec(str) << endl;
	cout << "������: " << (is_hex_number(str) ? "" : "�� ") << "�������� ����������������� ������" << endl;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')return(false);
	}
	return(true);
}
int  to_int_number(char str[])
{
	int buffer = 0, rut = 0, des = 1;

	for (int razmer = strlen(str) - 1; razmer >= 0; razmer--, des *= 10)
	{
		buffer = str[razmer] - 48;
		rut += buffer * des;
	}
	return(rut);
}
bool is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')return(false);
	}
	return(true);
}
int  bin_to_dec(char str[])
{
	int buffer = 0;
	int razmer = strlen(str);

	for (int i = 0; str[i]; razmer--, i++)
	{
		int stepen = 1; int itog = 1;
		while (stepen != razmer)
		{
			itog *= 2; stepen++;
		}
		if (str[i] == '1')buffer += itog;
	}
	return(buffer);
}
bool is_hex_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' && str[i] > '9'&& str[i] != 'A')return(false);
	}
	return(true);
}