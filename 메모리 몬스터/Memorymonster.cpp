//[문제] 나는 MemoryMonster다. 나는 생성 시에 int 값을 전달받아 그 수만큼 int 메모리를 생성한다.
// 생성한 메모리의 값을 랜덤하게 기록한다. 
// 나를 코딩해 줘.
// 다음 코드가 문제없이 실행되면 좋겠어.

#include <iostream>
#include <random>

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,999 };

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) : size{ n } {			// 인자를 받아서 메모리를 생성하기전 인자를 size에 저장해 둔다.
		p = new int[n];				// 받은 인자만큼 int메모리를 만든다.
		for (int i = 0; i < n; ++i)
			p[i] = uid(dre);		// 각각에 랜덤값을 집어 넣는다.
	}
	void show() {
		cout << "메모리 확보한 수 - " << size << "첫 데이터 - " << p[0] << '\n';
	}
};

int main() {
	MemoryMonster m{ 100 };
	m.show();
}

// 이렇게 하면 new로 받은 메모리도 안지워 지고 비어있는 부분이 매우 많다.
// 스페셜한 부분을 다 해주자

// 스페셜한 것 = 디폴트 생성자, 복사생성자, 연산자 오버로딩, 소멸자.
// 사용자가 정의한 함수 MemoryMonster(int)와 같은건 스페셜 하지 않음
// 클래스 작성 순서는 public 부터 만들기를 권장함. 그 후에 스페셜한 함수, protected, private 순으로 만든다.

