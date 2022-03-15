#include <iostream>

using namespace std;

struct tlist
{
	tlist* next;
	tlist* prev;
	double value;
};

void create(tlist* el)
{
	int size = 0;
	el->prev = NULL;
	tlist* temp = new tlist;
	tlist* temp2 = new tlist;
	cout « "Enter size of list:";
	cin » size;
	cout « "\nEnter 0 element:";
	cin » el->value;
	el->next = temp;
	temp->prev = el;
	for (int i = 1; i < size; i++)
	{
		cout « "\nEnter " « i « " element:";
		cin » temp->value;
		temp2 = new tlist;
		temp->next = temp2;
		temp2->prev = temp;
		temp = temp2;
		temp->next = NULL;
	}

}

void print(tlist* el)
{
	tlist* temp = el;
	while (temp->next != NULL)
	{
		cout « temp->value « " ";
		temp = temp->next;
	}
	cout « endl;
}


void add(tlist* el, double a)
{
	if (el->next == NULL) //last
	{
		tlist* temp = new tlist;
		el->next = temp;
		temp->prev = el;
		temp->value = a;
	}
	else
	{
		tlist* inserted = new tlist;
		inserted->value = a;
		tlist* temp = el->next;
		el->next = inserted;
		inserted->prev = el;
		inserted->next = temp;
		temp->prev = inserted;
	}
}


void find(tlist* el, double num, double adding)
{
	tlist* temp = el;
	while (temp->next != NULL)
	{
		if (temp->value == num) add(temp, adding);
		temp = temp->next;
	}
}

int main()
{
	tlist* a = new tlist;
	create(a);
	find(a, 2.0, 5.0); //1 число - то, что ищем, 2 - что вставляем, можно вставить рандомные переменные
	cout « "ascending order\n";
	print(a);
	while (a->next->next != NULL)
	{
		a = a->next;
	}
	cout « "descending order\n";
	while (a != NULL)
	{
		cout « a->value « " ";
		a = a->prev;
	}
	system("pause");
	return 0;
}
