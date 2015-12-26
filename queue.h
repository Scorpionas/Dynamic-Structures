struct Node
{
	int value; //информационное поле
	Node *next; //указатель на следующий элемент; 
};


Node *First(int value); // создание первого элемента в очереди
void add(Node **pend, int value); // добавление элемента в очередь
void del(Node **pbeg); // удаление элемента из очереди
void print(Node **pbeg); // печать элементов очереди
bool isEmpty(Node *pbeg); // проверка очереди на пустоту
void menu(); // интерфейс очереди
