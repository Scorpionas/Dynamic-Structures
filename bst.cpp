#include "stdafx.h"
#include "bst.h"
#include "iostream"
using namespace std;

bst::bst() //конструктор без параметров
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = 0;
}

bst::bst(int val) //конструктор с параментром
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = val;
}

bst::~bst() //деструктор 
{

}


void bst::addNode(bst *root, int key)
{
	if (key < root->value){ //в случае, если ключ меньше значения корня дерева

		if (root->leftSubtree){ // если существует левое поддерево
			addNode(root->leftSubtree, key); // добавляем в левое поддерево
		}
		else{
			root->leftSubtree = new bst(key); // иначе создаём поддерево
		}
	}

	if (key >= root->value){ //в случае, если ключ больше значения корня дерева
		if (root->rightSubtree){  // если существует правое поддерево
			addNode(root->rightSubtree, key); // добавляем в правое поддерево
		}
		else{
			root->rightSubtree = new bst(key); // иначе создаём поддерево
		}
	}
}



void bst::addNodeWrapper(int key){
	addNode(this, key);// добавляем новый элемент по ключу, указатель this ссылается на адрес корня дерева
}


/*
BRIEF: Функция поиска узла или листа в дереве по ключу. Использует рекурсию,для перемещения по дереву в поисках нужной позиции.
IN: Число(Ключ) по которому идёт поиск, указатель на корень дерева,который будет меняться в процессе рекурсии.
OUT: Указатель на узел,найденный по ключу.
*/
bst* bst::find(bst *root, int key)
{

	if (!root) return NULL;
	if (key == root->value)
		//return *root;
		return root;
	if (key < root->value)
	{
		return (find(root->leftSubtree, key));
	}
	else
	{
		return find(root->rightSubtree, key);
	}

}


/*
BRIEF: Функция вызова функции поиска узла или листа в дереве по ключу,которая добавит адрес корня дерева,в виде this : переменной ссылающийся самой на себя. Сделанно это для упрощения работы с программой.
IN: Число(Ключ) по которому идёт поиск. указатель на корень дерева,который будет меняться в процессе рекурсии.
OUT: ---
*/
void bst::findWrapper(int key){
	find(this, key);
}


bst bst::minimum(bst *root)
{
	bst *pv = root;//выделяем место в ячейке памяти под указатель и присваиваем ему указатель на корень или узел
	while (pv->leftSubtree)
		pv = pv->leftSubtree;
	return *pv; //возвращает указатель на самый левый элемент.
}

bst bst::maximum(bst *root)
{
	bst *pv = root;//выделяем место в ячейке памяти под указатель и присваиваем ему указатель на корень или узел
	while (pv->rightSubtree) //пока есть правое поддерево
		pv = pv->rightSubtree;
	return *pv;//возвращает указатель на самый правый элемент.
}
/*
BRIEF: Функция вызова функции удаления узла или листа в дереве по ключу,которая добавит адрес корня дерева,в виде this : переменной ссылающийся самой на себя. Сделанно это для упрощения работы с программой.
IN: Число(Ключ) по которому произойдет удаление.
OUT: ---
*/
void bst::delNodeWrapper(int key){
	delNode(this, key); //удаления узла или листа в дереве по ключу
}


/*
BRIEF: Функция печати дерева.
IN: Указатель на корень дерева.
OUT: ---
*/
void bst::inorder(bst*root)
{
	cout << endl;
	if (root)
	{
		if (root->value != 0)
			cout << root->value;
		if (root->leftSubtree != 0)
		{
			inorder(root->leftSubtree);
		}
		if (root->rightSubtree != 0)
		{
			inorder(root->rightSubtree);
		}
	}
}
/*
BRIEF: Функция удаления узла или листа по ключу.
IN: Число(Ключ) по которому произойдет удаление. Указатель на корень дерева.
OUT: Возвращает True или False,в зависимости от результата работы.
*/

bool bst::delNode(bst *root, int key)
{
	bst *min = NULL;
	bst *max = NULL;
	bst *pv = NULL;
	pv = find(root, key);
	bst *pv1 = find1(root, key);
	if (pv != NULL)
	{
		if (pv->rightSubtree != NULL)
		{
			minimum(pv->rightSubtree);
			*min = minimum(pv->rightSubtree);
			pv->value = (min)->value;
			*min = NULL; // возможно это некорректно
		}

		else
		{
			if (pv->leftSubtree != NULL)
			{
				maximum(pv->leftSubtree);
				*max = maximum(pv->leftSubtree);
				pv->value = (max)->value;
				*max = NULL; // возможно это некорректно
			}
			else
			{
				*pv = NULL;
			}
		}

		return true;
	}
	else
		return false;
}
