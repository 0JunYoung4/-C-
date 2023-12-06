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
	STRING t = s;

	s.show();
	t.show();

	// 이 코드 살리는거 중요함. 왜 죽고 어떻게 살려야 되는지 생각해보기

}
// 복사생성자가 없다면 얕은 복사가 이루어짐
// t라는 객체에 s라는 객체값을 복사하게 됨으로써 t는 s와 연결된 freestore의 메모리 주소를 가리킨다.
// t가 소멸될때 해당 메모리도 사라지므로 오류가 발생하게 된다.	(댕글링포인터)
// 이를 해결하기 위해 새로운 메모리를 받아서 거기에 s의 값을 저장해주는 깊은 복사가 필요하다.