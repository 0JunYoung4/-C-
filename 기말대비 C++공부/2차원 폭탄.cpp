//----------------------------------------------------------------
// 2차원 점을 생성하고 폭탄을 터뜨리자
//----------------------------------------------------------------
#include <iostream>
#include <random>
#include <math.h>

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ -100,100};

//[문제] 2차원 점 100개를 생성하라.
//좌표값은 [-100, 100] 랜덤값으로 설정
//원점에서 폭탄이 터진다. (반경 20까지 영향받는다.)
//폭탄의 영향을 받는 점을 출력하라.

class Point2D {
public:
	int x;
	int y;

	void Show() {
		cout << "( " << x << ", " << y << " )" << '\n';
	}
};

int main()
{

	Point2D points[100];

	for (Point2D& p : points) {			//Point2D에 있는 x,y를 바꿔주기위해 참조를 해야됨
		p.x = uid(dre);
		p.y = uid(dre);
	}

	for (Point2D p : points) {
		if (sqrt(p.x * p.x + p.y * p.y) <= 20)
			p.Show();
	}



}