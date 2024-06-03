#pragma once

#ifndef Monster_h
#define Monster_h

#include <iostream>

const int  NAME_LENGTH{ 16 };

struct Monster 
{
	char name[NAME_LENGTH];
	int hp;
	int mp;
};

struct Monster2
{
	char name[NAME_LENGTH];
	int hp;
	int mp;

	Monster2 *pNext;
};

struct Monster3 
{
	char name[NAME_LENGTH];
	int hp;
	int mp;

	Monster3 *pPrev;
	Monster3 *pNext;
};

#endif /*Monster_h*/
