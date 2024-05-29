#pragma once

#include <iostream>
#include <cstring>

#ifndef DynamicArray_h
#define DynamicArray_h

#include "Monster.h"


struct DynamicArray
{
	Monster *pArray;
	int size;
};

void CreateMonster(DynamicArray& array, const char *name, int hp, int mp) 
{
	Monster *temp = new Monster[array.size + 1];

	for (int i = 0; i < array.size; i++) 
	{
		temp[i] = array.pArray[i];
	}

	delete[] array.pArray;
	array.pArray = temp;

	Monster& m = array.pArray[array.size];

	strcpy_s(m.name, NAME_LENGTH, name);

	//for (int i{}; i < NAME_LENGTH - 1 && name[i] != '\0'; i++) 
	//{
	//	m.name[i] = name[i];
	//}

	m.name[NAME_LENGTH - 1] = '\0';
	m.hp = hp;
	m.mp = mp;
	array.size++;
}

void DeleteMonster(DynamicArray &array, const char *name) 
{
	int index{ -1 };
	for (int i = 0; i < array.size; i++) 
	{
		if (strcmp(array.pArray[i].name, name) == 0) 
		{
			index = i;
			break;
		}
	}

	if (index != -1) 
	{
		Monster *temp = new Monster[array.size - 1];
		int j{};
		for (int i = 0; i < array.size; i++) 
		{
			if (i != index) 
			{
				temp[j++] = array.pArray[i];
			}
		}
		delete[] array.pArray;
		array.pArray = temp;
		--array.size;
	}
}
int GetMonsterCount(const DynamicArray &array) 
{
	return array.size;
}
bool FindMonsters(const DynamicArray &array, const char *name) 
{
	for (int i = 0; i < array.size; i++) 
	{
		if (strcmp(array.pArray[i].name, name) == 0)
		{
			return true;
		}
	}
}
void PrintMonsters(const DynamicArray &array) 
{
	for (int i{}; i < array.size; i++) 
	{
		const Monster &m = array.pArray[i];
		std::cout << m.name << "," << m.hp << "," << m.mp << std::endl;
	}
};

void DynamicArrayTest() 
{
	DynamicArray array{};

	CreateMonster(array, "Wolf", 100, 0);
	CreateMonster(array, "Demon", 200, 100);

	std::cout << GetMonsterCount(array) << std::endl;
	PrintMonsters(array);

	std::cout << FindMonsters(array, "Wolf") << std::endl;

	DeleteMonster(array, "Wolf");
	PrintMonsters(array);
}

#endif/*DynamicArray_h*/