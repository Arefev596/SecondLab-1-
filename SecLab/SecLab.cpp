#include "stdio.h"
#include "locale.h"
#pragma warning(disable : 4996)


struct DList
{
	DList* next;
	DList* prev;
	int value;
};

void Init(DList* el)
{
	int size;
	el->prev = NULL;
	DList* temp = new DList;
	DList* temp2 = new DList;

	printf("Введите размер двусвязного списка: ");
	scanf("%i", &size);
	while (size < 0) {
		printf("Введите число большее 0!\n");
		scanf("%i", &size);
	}


	printf("Введите значение головы: ");
	scanf("%i", &el->value);
	el->next = temp;
	temp->prev = el;

	for (int i = 1; i < size; ++i)
	{
		printf("Введите %i", i);
		printf(" элемент: ");
		int help;
		scanf("%i", &help);
		temp->value = help;
		temp2 = new DList;
		temp->next = temp2;
		temp2->prev = temp;
		temp = temp2;
		temp->next = NULL;
	}

}

void print(DList* el)
{
	DList* temp = el;
	while (temp->next != NULL)
	{
		printf("%i", temp->value);
		printf(" ");
		temp = temp->next;
	}
	printf("\n");
}


void add(DList* el, double a)
{
	if (el->next == NULL) //элемент указывает на последний
	{
		DList* temp = new DList;
		el->next = temp;
		temp->prev = el;
		temp->value = a;
	}
	else
	{
		DList* inserted = new DList;
		inserted->value = a;
		DList* temp = el->next;
		el->next = inserted;
		inserted->prev = el;
		inserted->next = temp;
		temp->prev = inserted;
	}
}


void Switch(DList* el, int num, int adding)
{
	DList* temp = el;
	while (temp->next != NULL)
	{
		if (temp->value == num)
			add(temp, adding);
		else {
			printf("Числа %i", num);
			printf(" нет в списке!\n");
			break;
		}
		temp = temp->next;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	DList* NewDList = new DList;
	Init(NewDList);

	printf("После какого числа вы хотите добавить новое? \n");
	int DataForSwitch;
	scanf("%i", &DataForSwitch);
	printf("Введите символ, который хотите добавить: ");
	int AddingData;
	scanf("%i", &AddingData);
	Switch(NewDList, DataForSwitch, AddingData);

	printf("Список в возрастающем порядке\n");
	print(NewDList);
	while (NewDList->next->next != NULL)
	{
		NewDList = NewDList->next;
	}
	printf("Список в убывающем порядке\n");
	while (NewDList != NULL)
	{
		printf("%i", NewDList->value);
		printf(" ");
		NewDList = NewDList->prev;
	}

	return 0;

}