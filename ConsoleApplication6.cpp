#include <iostream>

struct Bullet 
{
	int damage;
	float speed;
	float size;

	Bullet *pNext;
};

int main()
{
	Bullet *a = new Bullet;
	Bullet *b = new Bullet;

	a->pNext = b;
}
