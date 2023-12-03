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
		cout << "생성(int) - " << size << ", [0] - " << p[0] << '\n';
	}
	MemoryMonster(const MemoryMonster& other) : size(other.size) {
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = other.p[i];
		cout << "복사생성 - " << size << ", [0] - " << p[0] << '\n';
	}
	~MemoryMonster() {
		cout << "소멸직전 - " << size << ", [0] - " << p[0] << '\n';
		delete[] p;
	}

	// private값을 쓰기위해 getter 만들기
	int getSize() {
		return size;
	}

	void show() {
		cout << "내가 관리하는 int의 수 - " << size << ", [0] - " << p[0] << '\n';
	}

};

int main() {
	MemoryMonster a[]{ 1, 3, 5 ,7 ,9, 2, 4, 6, 8, 10 };

	//[문제] qsort를 사용하여 a를 size기준 오름차순으로 정렬하고 show()를 호출하라.

	//qsort(a, sizeof(a) / sizeof(MemoryMonster), sizeof(MemoryMonster), [](const void* a, const void* b) {
	//	return *(int*)a - *(int*)b;		// int 기준이니까 int로 변형해주기
	//	});			//이건 완벽한 답은 아님 -> size는 private함수인데 이렇게 쓰면 제대로 참조하고 있는지 모름
	//	완벽한 답을 위해선 getter를 만들어서 size값을 꺼낼 수 있도록 만들어 줘야됨

	qsort(a, sizeof(a) / sizeof(MemoryMonster), sizeof(MemoryMonster), [](const void* a, const void* b) {
		return ((MemoryMonster*)a)->getSize() - ((MemoryMonster*)b)->getSize();
		});

	for (MemoryMonster& mon : a)
		mon.show();
}
// qsort(무엇을, 몇개를, 크기는, 기준은)