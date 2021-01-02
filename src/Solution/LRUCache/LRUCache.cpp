#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
	size = 0;
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	for (unsigned int i = 0; i < capacity; i++)
		lru.push_back(0);

	for (unsigned int i = 0; i < requestsNo.size(); i++)
	{
		while (size != capacity)
		{
			for (unsigned int j = 0; j < capacity; j++)
			{
				if (requestsNo[i] == lru[j])
				{
					for (int z = j; z > 0; z--)
						lru[z] = lru[z - 1];
					lru[0] = requestsNo[i];
					size++;
				}
				else
				{
					lru.insert(lru.begin(), requestsNo[i]);
					size++;
				}
			}
		}

		if (size == capacity)
		{
			lru.pop_back();
			for (int j = capacity - 1; j > 0; j--)
				lru[j] = lru[j - 1];
			lru[0] = requestsNo[i];
		}
	}
	vector<int> aux(capacity, 0);
	for (unsigned int i = 0; i < capacity; i++)
		aux[i] = lru[i];

	return aux;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
	lru.reserve(capacity);
}

void LRUCache::setLRU(vector<int> aux)
{
	lru = aux;
	size = aux.size();
	capacity = 4;
}
