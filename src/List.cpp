//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : List in C++,
//============================================================================

#include <iostream>
#define MAX_LIST_ELEMS 1666

typedef struct List
	{
		struct List * next;
		int payload;
	} List_t;


List_t * init(int a); // а- значение первого узла
List_t * addelem(List_t *lst, int number); //Добавление элемента
void listprint(List_t *lst);               //Вывод данных каждого элемента списка
List_t * deletelem(List_t *lst, List_t *root); //удаление элемента списка
List_t * delete_every_fifth(List_t *root); //Удаление каждого пятого элемента списка

List_t * for_del [MAX_LIST_ELEMS/5+1] = {0};

int main()
{
	using namespace std;
	cout << "List Program started, " << "MAX_LIST_ELEMS=" << MAX_LIST_ELEMS << endl << endl; // prints List Program started
	List_t *root, *a;
	int i=0;
	//заполнение списка
	cout << "Заполнение списка!" << endl;
	//инициализация списка
	root=init(1);
	for (i=MAX_LIST_ELEMS; i>1; --i)
	{
		a=addelem(root, i);
	}
	//Выводим на экран данные элементов списка
	listprint(root);
	cout << endl;
	a=delete_every_fifth(root);

	//Выводим на экран данные элементов списка после удаления каждого пятого элемента
	cout << "После удаления каждого пятого элемента списка!" << endl;
	listprint(root);
	return 0;
}

List_t * init(int a) // а- значение первого узла
{
	List_t *lst;
	// выделение памяти под корень списка
	lst = (List_t*)malloc(sizeof(List_t));
	lst->payload = a;
	lst->next = NULL; // это последний узел списка
	return(lst);
}

List_t * addelem(List_t *lst, int number)
{
	List_t *temp, *p;
	temp = (List_t*)malloc(sizeof(List_t));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->payload = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}

void listprint(List_t *lst)
{
	using namespace std;
	List_t *p;
	p = lst;
	do
	{
		cout << p->payload << " ";
		p = p->next; // переход к следующему узлу
	}
	while (p != NULL);
	cout << endl;
}

List_t * deletelem(List_t *lst, List_t *root)
{
	List_t *temp;
	temp = root;
	while (temp->next != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->next;
	}
	temp->next = lst->next; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}

List_t * delete_every_fifth(List_t *root)
{
	using namespace std;
	List_t *p;
	p=root;
	int i=0;
	// перемещаемся на нужный элемент
	p=p->next;
	p=p->next;
	i=MAX_LIST_ELEMS;
	while (p->next != NULL) // просматриваем список начиная с корня
	{
		p=p->next;
		if ((i%5==0))  // ищем каждый пятый элемент
		{
			p=deletelem(p,root);
			//cout << "i%5=" << i%5 << " " << " " << "i=" << i << " p->payload=" << p->payload << endl; //отладочный вывод
		}
	    i--;
	}
 return root;
}

