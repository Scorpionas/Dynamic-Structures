
// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "bst.h"
#include "conio.h"
#include "iostream"
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{

	int val = 10;
	bst A(val);

	val = 5;
	A.addNodeWrapper(val);

	val = 8;
	A.addNodeWrapper(val);

	val = 7;
	A.addNodeWrapper(val);

	val = 15;
	A.addNodeWrapper(val);

	val = 13;
	A.addNodeWrapper(val);
	A.inorder(&A);
	cout << endl;
	A.delNodeWrapper(7);
	A.inorder(&A);



	_getch();
	return 0;
}
