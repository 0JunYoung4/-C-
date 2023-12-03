#include <iostream>
#include <random>
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1,999 };

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) : size{ n } {
		p = new int[n];
		for (int i = 0; i < n; ++i)
			p[i] = uid(dre);
		cout << "����(int) - " << size << ", [0] - " << p[0] << '\n';
	}
	MemoryMonster(const MemoryMonster& other) : size(other.size) {
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = other.p[i];
		cout << "������� - " << size << ", [0] - " << p[0] << '\n';
	}
	~MemoryMonster() {
		cout << "�Ҹ����� - " << size << ", [0] - " << p[0] << '\n';
		delete[] p;
	}

	// private���� �������� getter �����
	int getSize() {
		return size;
	}

	void show() {
		cout << "���� �����ϴ� int�� �� - " << size << ", [0] - " << p[0] << '\n';
	}

};

int main() {
	MemoryMonster a[]{ 1, 3, 5 ,7 ,9, 2, 4, 6, 8, 10 };

	//[����] qsort�� ����Ͽ� a�� size���� ������������ �����ϰ� show()�� ȣ���϶�.

	//qsort(a, sizeof(a) / sizeof(MemoryMonster), sizeof(MemoryMonster), [](const void* a, const void* b) {
	//	return *(int*)a - *(int*)b;		// int �����̴ϱ� int�� �������ֱ�
	//	});			//�̰� �Ϻ��� ���� �ƴ� -> size�� private�Լ��ε� �̷��� ���� ����� �����ϰ� �ִ��� ��
	//	�Ϻ��� ���� ���ؼ� getter�� ���� size���� ���� �� �ֵ��� ����� ��ߵ�

	qsort(a, sizeof(a) / sizeof(MemoryMonster), sizeof(MemoryMonster), [](const void* a, const void* b) {
		return ((MemoryMonster*)a)->getSize() - ((MemoryMonster*)b)->getSize();
		});

	for (MemoryMonster& mon : a)
		mon.show();
}
// qsort(������, ���, ũ���, ������)