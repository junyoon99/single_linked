#pragma once


#include "Monster.h"


struct DoubleLinkedList 
{
	Monster3 *pHead;
	Monster3 *pTail;
	int size;
};

void CreateMonster(DoubleLinkedList &list, const char *name, int hp, int mp) 
{
	Monster3 *m = new Monster3;
	strcpy_s(m->name, NAME_LENGTH, name);
	m->hp = hp;
	m->mp = mp;
	m->pNext = m->pPrev = nullptr;
	list.size++;

	if (list.pTail == nullptr) 
	{
		list.pHead = list.pTail = m;
	}
	else 
	{
		list.pTail->pNext = m;
		m->pPrev = list.pTail;
		list.pTail = m;
	}

}

void DeleteList(DoubleLinkedList &list) 
{
	Monster3 *m = list.pHead;
	Monster3 *pNext{};

	while (m != nullptr) 
	{
		pNext = m->pNext;
		delete m;
		m = pNext;
	}

	list.pHead = list.pTail = nullptr;
	list.size = 0;
}

void PrintList(const DoubleLinkedList &list) 
{
	Monster3 *m = list.pHead;

	while (m != nullptr) 
	{
		std::cout << m->name << std::endl;
		m = m->pNext;
	}
}

void DeleteMonster(DoubleLinkedList &list, const char *name) 
{
	Monster3 *m = list.pHead;

	while (m != nullptr) 
	{
		if (strcmp(m->name, name) == 0) 
		{
			break;
		}

		m = m->pNext;
	}

	if (m != nullptr) 
	{
		if (m->pPrev == nullptr) 
		{
			//m->pNext->pPrev = nullptr;
			list.pHead = m->pNext;
		}
		else 
		{
			m->pPrev->pNext = m->pNext;
		}

		if (m->pNext == nullptr) 
		{
			//m->pPrev->pNext = nullptr;
			list.pTail = m->pPrev;
		}
		else 
		{
			m->pNext->pPrev = m->pPrev;
		}

		delete m;
	}
}

void DoubleLinkedListTest() 
{
	DoubleLinkedList list{};

	CreateMonster(list, "Wolf", 100, 0);
	CreateMonster(list, "Demon", 100, 0);
	PrintList(list);
	

	DeleteMonster(list, "Demon");
	PrintList(list);
	DeleteList(list);
}