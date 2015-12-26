class tree
{
	
};
class bst :public tree
{
	bst *leftSubtree; //укаазатель на левое поддерево
	bst *rightSubtree; //укаазатель на правое поддерево
	int value; // информационное поле 
public:
	bst();
	bst(int val);
	~bst();

	void addNodeWrapper(int key); // добавление нового элемента по ключу
	void addNode(bst *root, int key); // добавление нового элемента 
	bool delNode(bst *root, int key); // удаление элемента 
	bst* find(bst *root, int key); // поиск элемента
	void findWrapper(int key); // поиск по ключу
	bst minimum(bst*root); // поиск минимума
	bst maximum(bst*root); // поиск максимума
	void delNodeWrapper(int key); // удаление элемента по ключу
	void inorder(bst*root); // прямой обход дерева
};
