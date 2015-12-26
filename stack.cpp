#include "stack.h"
#include <iostream>

using namespace std;

node* first(int value)
{
	node *top = new node;//выделяем место в ячейке памяти под указатель на первый элемент
 	top->value = value;  //записываем значение в информационное поле
 	top->prev = 0;       //зануляем ссылку на предыдущий элемент
 	return top;          // возвращаем адрес на первый элемент
}
void push(node **top, int value)
{
	node *pv = new node;//выделяем место в ячейке памяти 
	pv->value = value;  //записываем значение в информационное поле
 	pv->prev = *top;    //меняем указатель на предыдущий элемент
    *top = pv;          //определение новой вершины
}
void pop(node **top)
{
	node *pv = *top; //выделяем место в ячейке памяти 
    * top = (*top)->prev; // определение новой вершины
	delete pv; //освобождение памяти 
}

void print(node *top)
{
    node *pv = top; //выделяем место в ячейке памяти
 	while (pv != NULL) // если адрес вершины не указывает на 0(т.е. есть еще элементы) 
	{
		cout << pv->value<<" "<< endl;
		pv = pv->prev; // переход к следующему элементу
 	}
}
bool isEmpty(node *top) //возращает false,если стек пуст и true, если стек заполнен хотя бы одним элементом
{
	if (top == NULL)
		return false;
	else
                   return true;
}
void menu()
{
	int a, mn;
    node *top = NULL;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт из меню:" << endl;
		
		cout << "1)Добавить элемент в стек" << endl;
		cout << "2)Удалить элемент из стека" << endl;
		cout << "3)Печать стека" << endl << endl;
		cout << "Нажмите 0 для выхода из программы" << endl;
		cin >> mn;
		switch (mn)
		{
		case 1:
		{
 			cout << "Введите число в стек:" << endl;
			cin >> a;
			if (isEmpty(top) == 0)
 			{
				top = first(a);
 				system("cls");
 			}
 			else
 			{
				push(&top, a);
				system("cls");
			}
			break;
 		}
 		case 2:
 		{
			if (isEmpty(top) == NULL)
 			{
				system("cls");
 				cout << "Элементов в стеке нет" << endl;
 				cout << endl;
				cout << endl;
				cout << endl;
			}
			else
 			{
				pop(&top);
 				system("cls");
 				cout << endl;
 				cout << endl;
 				cout << endl;
 			}
 			break;


 		}


 		case 3:
 		{
			if (isEmpty(top) == 0)
			{
 				system("cls");
 				cout << "Элементов в стеке нет" << endl;
				cout << endl;
 				cout << endl;
				cout << endl;
			}
 			else
 			{
 				system("cls");
				print(&top);
				cout << endl;
				cout << endl;
				cout << endl;
			}
 			break;
		}
	}
	if (mn<0 || mn>3)
		system("cls");
	} while (mn != 0);
}
