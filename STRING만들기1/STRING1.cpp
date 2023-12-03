#include <iostream>
#include <string>

using namespace std;

// 문자열을 받아 문자열의 길이만큼 메모리를 동적할당하여 가져오도록 하자.


class STRING {
	size_t num;
	char* p;
public:
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "생성자(const char*) - " << num << ", 메모리: " << (void*)p << '\n';
	}

	size_t size() const {		// 읽기만 할거니까 const 붙여주기
		return num;
	}
	void show() const {		// 읽기만 할거니까 const 붙여주기
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}
};

int main()
{
	STRING s{ "나는 STRING 클래스야" };
	cout << "문자열의 길이 - " << s.size() << '\n';
	s.show();
}