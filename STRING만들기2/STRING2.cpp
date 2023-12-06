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
		
		cout << "생성자(const char*) - " << num << ", 메모리: " << (void*)p << '\n';		// void*로 출력을 해 줘야 메모리가 나옴
	}
	~STRING() {
		cout << "소멸자 - " << num << ", 메모리: " << (void*)p << "\n";
		delete[] p;		// new로 만들어 줬으니 꼭 만들어 줘야됨
	}
	size_t size() {
		return num;
	}
	void show() {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}
};

int main()
{
	STRING s[]{ "덴마크의", "컴", "과학", "비야네" , "스트로스트룹", "C언어", "바탕으로 만들었다" };

	// [문제] s를 길이 오름차순으로 정렬한 후 출력하라.
	qsort(s, sizeof(s) / sizeof(STRING), sizeof(STRING), [](const void* a, const void* b) {
		return (int)((STRING*)a)->size() - (int)((STRING*)b)->size();		// unsigned long long 타입이여서 음수가 안된다.
		});

	//결과 출력
	cout << "\n 길이 오름차순 정렬결과" << '\n';
	for (STRING& str : s)
		str.show();

}