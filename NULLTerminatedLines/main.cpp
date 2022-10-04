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
	//str[] - строковая переменная
	//"Hello" - строковая константа
	cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;
#endif 

#ifdef EXAMPLE_2
	//for(int i = 0; i < 256; i++)cout << i << "\t" << char();
	
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: "; 
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE); //это разделитель
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Длина строки: " << StringLenght(str)<<endl;
	cout << "Длина строки: " << strlen(str)<<endl; //встроенная функция
	cout << "Длина строки в байтах: " << sizeof(str) << endl;
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
	for (; str[i]; i++);  //здесь мы разыменовали последний элемент
	return i;             //а последний элемент 0, а 0 это-False
}

void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		if (str[i] == 'ё') str[i] = 'Ё';*/
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
