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

	// �ؽù��Ͽ� Node ������ �迭
	Node* bucket[10] = { NULL, };

public:
	myHash(int c = 0) :code(c)
	{
	}
	~myHash()
	{
		// 3. ���Ͽ� �Ҵ�� Node ����Ʈ�� �����ϴ� �ڵ� �ۼ�
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
		// 1. key�� �̿��ؼ� Node ��ü�� ����� ���Ͽ� �߰��ϴ� �ڵ� �ۼ�
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
		// 2. ������ ��ȸ�ϸ鼭 �Էµ� ��� �����͸� ȭ�鿡 ����ϴ� �ڵ� �ۼ�
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
		// 4. key���� ���� Node�� �����ϴ� �ڵ� �ۼ�
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
