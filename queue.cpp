#include "queue.h"
#include <iostream>
#include <clocale>
#include <ctype.h>
#include <cstring>

using namespace std;
Node *First(int value)
{
	Node *pv = new Node; //выделяем место в ячейке памяти под указатель на первый элемент очереди
	pv->value = val; // записываем значение в информационное поле
	pv-> next = NULL; // зануляем указатель на следующий элемент
	return pv; // возвращаем адрес первого элемента структуры
}

void add(Node **pend, int value)
{
	Node *pv = new Node; //выделяем место в ячейке памяти под указатель на новый элемент очереди
	pv->value = value; // записываем значение в информационное поле
	pv-> next = NULL; 
	(*pend)-> next = pv;
	*pend = pv;
}
void print(Node **pbeg)
{
	Node *tmp = (*pbeg)->next; //выделяем место в ячейке памяти под указатель и присваиваем ему указатель на второй элемент очереди

	printf("%d ", (*pbeg)->value);// печатаем первый элемент очереди
	while (tmp != NULL)//пока указатель на последующий элемент не равен нулю
	{
		printf("%d ", tmp->value); //печатаем значение следующий элемент
		tmp = tmp->next; //переприсваем указатель на указатель следующего элемента
	}
	cout << endl;
}
bool isEmpty(Node *pbeg) //сходная проверка с проверкой на пустоту в стеке
{
	if (pbeg == NULL)
		return false;
	else
		return true;
}
void menu()
{
	setlocale(LC_ALL, "Russian");

	Node *pbeg = NULL;
	Node *pend = NULL;
	{

		char t;
		int first_el;
		int el = 0;
		do
		{
			cout << "***QUEUE***" << endl << endl;
			cout << "1. Добавить первый элемент в очередь\n";
			cout << "2. Добавить новый элемент в очередь\n";
			cout << "3. Удалить первый элемент из очереди\n";
			cout << "4. Распечатать элемент(ы) очереди\n\n";
			cout << "Выберите число и нажмите ENTER\n";
			cin >> t;
			isdigit(t);
			int c;
			c = t - '0';
			if (c >= 0 && c < 5)
			{

				switch (c)
				{
				case 1:
					if (pbeg == NULL)
					{
						cout << "Создайте первый элемент\n\n";
						cin >> first_el;

						pbeg = First(first_el);
						pend = pbeg;
					}
					else
					{
						cout << "Ошибка! Первый элемент существует!\n\n";
						system("pause");
					}
					system("CLS");
					break;

				case 2:
					if (pbeg != NULL) {
						cout << "Напишите новый элемент\n\n";
						cin >> el;
						add(&pend, el);
					}
					else {
						cout << "Ошибка! Нужно добавить первый элемент!\n\n";
						system("pause");
					}
					system("CLS");
					break;
				case 3:
					if (pbeg != NULL) {
						del(&pbeg);
						cout << "Элемент был удален из очереди\n\n";
					}
					else {
						cout << endl;
						cout << "Ошибка! Очередь пуста!\n\n";
					}
					system("pause");
					cout << endl;
					system("cls");
					break;
				case 4:
					cout << "Распечатаная очередь\n\n";
					print(&pbeg);
					cout << endl;
					system("pause");
					cout << endl;
					system("cls");
					break;
				}
			}
			else
			{
				cout << endl;
				cout << "Неверное значение! Введиите число от 1 до 4" << endl << endl;
				system("pause");
				cout << endl;
				system("cls");


			}
		} while (1);


	}
