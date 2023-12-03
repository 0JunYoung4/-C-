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
	void show() const {			// const�� �������μ� �б⸸ �ϰڴٰ� ������. �̶� ���� �ٲٴ� �õ��� �ϸ� ����
		cout << "���� �����ϴ� int�� �� - " << size << ", [0] - " << p[0] << '\n';
	}

};

int main() {
	MemoryMonster a[3]{ 1,4,5 };

	cout << "\n\n\n";

	for (const MemoryMonster& mon : a)			// const�� ����Ѵٴ°� �б⸸ �Ѵٴ� ���̱⿡ �Լ� ������ �б⸸ �Ѵٴ�
												// ������ ����� �Ѵ�.
		mon.show();				
	cout << "\n\n\n";
}