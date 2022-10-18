/*реализовать следующие функции :
void to_upper(char str[]);	//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void shrink(char str[]);	//Удаляет лишние пробелы из предложения
bool is_palindrome(const char str[]);	//Проверяет, является ли строка палиндромом
bool is_int_number(const char str[]);	//Проверяет, является ли строка целым десятичным числом
int  to_int_number(char str[]);			//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(const char str[]);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);			//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(const char str[]);	//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char str[]);			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение*/

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
int  hex_to_dec(char str[]);

void main()
{
	setlocale(LC_ALL, "");

	const int SIZE = 20;
	char str[SIZE] = {};

	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);

	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	cout << "Строка: " << (is_palindrome(str) ? "" : "НЕ ") << "палиндром" << endl;
	cout << str << endl << "---" << endl;
	cout << "Строка: " << (is_int_number(str) ? "" : "НЕ ") << "является целым десятичным числом" << endl;
	if (is_int_number(str))cout << "Числовое значение: " << to_int_number(str) << endl;
	cout << "Строка: " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	if (is_bin_number(str))cout << "В десятичной системе: " << bin_to_dec(str) << endl;
	cout << "Строка: " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцатиричным числом" << endl;
	if (is_hex_number(str))cout << "В десятичной системе: " << hex_to_dec(str) << endl;
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
		int itog = 1;
		for (int stepen = 1; stepen != razmer; stepen++)itog *= 2;
		
		if (str[i] == '1')buffer += itog;
	}
	return(buffer);
}
bool is_hex_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9' && str[i] != 'a' && str[i] !='A' && str[i] != 'b' && str[i] != 'B' && str[i] != 'c' && str[i] != 'C' &&
			str[i] != 'd' && str[i] != 'D' && str[i] != 'e' && str[i] != 'E' && str[i] != 'f' && str[i] != 'F')return(false);
		//if ((str[i] < '0' || str[i] > '9') && ((str[i] - 55) < 10 || (str[i] - 55) > 15))return(false);
		//else if((str[i]-55)<10 || (str[i] - 55) > 15)return(false);
	}
	return(true);
}
int  hex_to_dec(char str[])
{
	int buffer = 0;
	int razmer = strlen(str);

	for (int i = 0; str[i]; razmer--, i++)
	{
		int itog = 1;
		for (int stepen = 1; stepen != razmer; stepen++)itog *= 16;
		
		if (str[i] >= '0' && str[i] <= '9')
		{
			buffer += (str[i] - 48) * itog;
		}
		else if (str[i] >= 65 && str[i] <= 70)
		{
			buffer += (str[i] - 55) * itog;
		}
		else if (str[i] >= 97 && str[i] <= 102)
		{
			buffer += (str[i] - 87) * itog;
		}
	}
	return(buffer);
}