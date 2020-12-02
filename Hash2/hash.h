#ifndef HASH_H
#define HASH_H
#include <string.h>

class Node {
public:
	const char* key;
	Node* next;

	Node(const char* k) : key(k) {
		next = NULL;
	}
};

class myHash
{
	int code;

	// 해시버켓용 Node 포인터 배열
	Node* bucket[10] = { NULL, };

public:
	myHash(int c = 0) :code(c)
	{
	}
	~myHash()
	{
		// 3. 버켓에 할당된 Node 리스트를 해제하는 코드 작성
		for (int i = 0; i < 10; i++)
		{
			printf("delete[%d]", i);
			while (bucket[i] != NULL) {
				Node* t = bucket[i]->next;
				printf("%s ", bucket[i]->key);
				delete bucket[i];
				bucket[i] = t;
			}
			printf("\n");
		}

	}
	int Hash(const char* key)
	{
		int sum = 0;
		int len = strlen(key);
		for (int i = 0; i < len; i += 2)
			sum += (key[i] * (i + 1));
		return sum;
	}

	void add(const char* key)
	{
		// 1. key를 이용해서 Node 객체를 만든뒤 버켓에 추가하는 코드 작성
		int hk = Hash(key) % 10;
		Node* node = new Node(key);
		if (bucket[hk] == NULL)
			bucket[hk] = node;
		else
		{	
			// Method 1
			Node* t = bucket[hk];
			while (t->next != NULL)
				t = t->next;
			t->next = node;
			// Method 2
			/*Node* next = bucket [hk];
			bucket[hk] = node;*/

		}

	}

	void print()
	{
		// 2. 버켓을 순회하면서 입력된 모든 데이터를 화면에 출력하는 코드 작성
		for (int i = 0; i < 10; i++)
		{
			printf("%d      ", i);
			
			Node* t = bucket[i];
			while (t != NULL)
			{
				printf("%s", t->key);
				t = t->next;
			}
			printf("\n");
		}
	}

	Node* search(const char* key)
	{
		// 4. key값을 가진 Node를 리턴하는 코드 작성
		int hk = Hash(key) % 10;
		Node* t = bucket[hk];
		while (t != NULL)
		{
			if (strcmp(t->key, key) == 0)
				return t;
			t = t->next;
		}
		return t;

	}
};

#endif
