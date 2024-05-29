#pragma once
#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include "Monster.h"

#include <cstring>

struct SingleLinkedList 
{
	Monster2 *pHead;
	Monster2 *pTail;

	int size;
};

void CreateMonster(SingleLinkedList &list, const char *name, int hp, int mp) 
{
	Monster2 *m = new Monster2;

	m->hp = hp;
	m->mp = mp;

	//std::strncpy(m->name, name, NAME_LENGTH);
	strcpy_s(m->name, NAME_LENGTH, name);

	m->pNext = nullptr;

	if (list.pHead == nullptr && list.pTail == nullptr) 
	{
		list.pHead = m;
		list.pTail = m;
	}
	else 
	{
		list.pTail->pNext = m;
		list.pTail = m;
	}
	list.size++;
}



int GetMonsterCount(const SingleLinkedList &list)
{
	return list.size;
}

void PrintMonsters(const SingleLinkedList &list) 
{
	Monster2 *m = list.pHead;

	while (m != nullptr) 
	{
		std::cout << m->name << "," << m->hp << "," << m->mp << std::endl;
		m = m->pNext;
	}
}

bool FindMonster(const SingleLinkedList &list, const char *name) 
{
	Monster2 *m = list.pHead;
	while (m != nullptr) 
	{
		if (strcmp(m->name, name) == 0) 
		{
			return true;
		}
		m = m->pNext;
	}
}

void DeleteList(SingleLinkedList &list) 
{
	Monster2 *m = list.pHead;
	Monster2 *next;

	while (m != nullptr) 
	{
		next = m->pNext;
		delete m;

		m = next;
	}

	list.pHead = list.pTail = nullptr;
	list.size = 0;
}

void DeleteMonster(SingleLinkedList &list, const char *name) 
{
	Monster2 *m = list.pHead;
	Monster2 *previous = nullptr;

	while (m != nullptr) 
	{
		if (strcmp(m->name, name) == 0) 
		{
			break;
		}

		previous = m;
		m = m->pNext;
	}

	if (m != nullptr) 
	{
		if (list.pHead == list.pTail) 
		{
			list.pHead = list.pTail = nullptr;
		}
		else if(previous == nullptr)
		{
			list.pHead = m->pNext;
		}
		else if (m == list.pTail) 
		{
			previous->pNext = nullptr;
			list.pTail = previous;
		}
		else 
		{
			previous->pNext = m->pNext;
		}
	}
	list.size--;
}

void SingleLinkedListTest()
{
	SingleLinkedList list{};

	CreateMonster(list, "Wolf", 100, 0);
	CreateMonster(list, "Demon", 200, 100);

	std::cout << GetMonsterCount(list) << std::endl;
	PrintMonsters(list);

	std::cout << FindMonster(list, "Wolf") << std::endl;

	DeleteList(list);

	DeleteMonster(list, "Wolf");
}

#endif // !SingleLinkedList_h
