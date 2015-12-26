struct node
{
	int value;     // информационное поле
	node *prev;    // указатель на предыдущий элемент
};

node* first(int value); // функция вставки первого элемента в стек 
void print(node **top);   //печать стека
void push(node **top, int value);   // занесение в стек  
void pop(node**top);             // удаление из стека
void menu();   // интерфейс стека
