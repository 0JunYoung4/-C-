//[����] ���� MemoryMonster��. ���� ���� �ÿ� int ���� ���޹޾� �� ����ŭ int �޸𸮸� �����Ѵ�.
// ������ �޸��� ���� �����ϰ� ����Ѵ�. 
// ���� �ڵ��� ��.
// ���� �ڵ尡 �������� ����Ǹ� ���ھ�.

#include <iostream>
#include <random>

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,999 };

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) : size{ n } {			// ���ڸ� �޾Ƽ� �޸𸮸� �����ϱ��� ���ڸ� size�� ������ �д�.
		p = new int[n];				// ���� ���ڸ�ŭ int�޸𸮸� �����.
		for (int i = 0; i < n; ++i)
			p[i] = uid(dre);		// ������ �������� ���� �ִ´�.
	}
	void show() {
		cout << "�޸� Ȯ���� �� - " << size << "ù ������ - " << p[0] << '\n';
	}
};

int main() {
	MemoryMonster m{ 100 };
	m.show();
}

// �̷��� �ϸ� new�� ���� �޸𸮵� ������ ���� ����ִ� �κ��� �ſ� ����.
// ������� �κ��� �� ������

// ������� �� = ����Ʈ ������, ���������, ������ �����ε�, �Ҹ���.
// ����ڰ� ������ �Լ� MemoryMonster(int)�� ������ ����� ���� ����
// Ŭ���� �ۼ� ������ public ���� ����⸦ ������. �� �Ŀ� ������� �Լ�, protected, private ������ �����.

