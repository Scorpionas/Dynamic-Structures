struct node
{
	int value; // информационное поле
	node *next; // указатель на следующий элемент
};


node *first(int value); // создание первого элемента в списке
void add(node *pbeg, int value); //добавление элемента в конец списка
node* find(node *const pbeg, int value); // поиск элемента 
int del(node **pbeg); // удаление элемента из списка
node *insert(node *const pbeg, int key, int value); // вставка после ключа
void insert_before(node **pbeg, int key, int value); // вставка до ключа
