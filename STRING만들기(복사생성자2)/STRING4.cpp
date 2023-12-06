#include <iostream>
#include <string>

using namespace std;
class STRING {
	size_t num;
	char* p;

public:
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "생성자(const char*) - " << num << ", 메모리: " << (void*)p << '\n';
	}

	STRING(const STRING& other) : num{ other.num } {
		p = new char[num];
		memcpy(p, other.p, num);
		
		cout << "복새 생성자 - " << num << ", 메모리: " << (void*)p << '\n';
	}

	~STRING() {
		
		cout << "소멸자 - " << num << ", 메모리: " << (void*)p << "\n";
		delete[] p;
	}

	// 복사 생성자랑 copy assignment operator은 세트임.
	STRING& operator=(const STRING& other) {
		// 자기 자신을 할당하지 않도록 하기 위해 먼저 확인해줘야됨
		if (this == &other)
			return*this;
		delete[] p;
		num = other.num;
		p = new char[num];
		memcpy(p, other.p, num);
		
		cout << "copy assignment operator - " << num << ", 메모리: " << (void*)p << '\n';

	}

	size_t size() const {
		return num;
	}

	void show() const {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}

};

int main()
{
	
	STRING s{ "스트링" };
	STRING t{ "2023. 11. 09" };

	s.show();
	t.show();

	t = s;		// 스페셜한 순간

	cout << "\n\n\ns와 같아진 t" << "\n\n\n";
	t.show();
}

// 오류 고치기
// t가 s의 메모리를 가리키게 되면서 기존의 메모리와의 연결을 끊어버리는데 이 메모리는 사라지지 않고 
// 떠돌고 있음. 또한 t가 사라지면서 댕글링포인터가 되어 오류가 발생