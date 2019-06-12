
//7장-15.MAINCC.CPP
//ColorCircle 예제의 main 함수
#include <iostream>
using namespace std;
//#include "7장-13-2.CIRCLEC.h"
//#include "7장-13.CIRCLE.h"
//#include "7장_13-1.COLOR.h"
/*
(4) 다중 상속의 예제
<Circle 클래스 작성>
1. 중점(X_center, Y_center), 반지름(radius)을 저장하는 변수 작성
2. 중점, 반지름을 변경하는 public interface 작성
3. 변수에 접근하기 위한 public interface 작성
4. 변수의 값을 출력하는 show 함수 작성
5. ++연산자 오버로딩(void operator ++ ()) 작성
6. 파라미터가 있는 생성자 작성(Circle(int x, int y, int r = 20) :
	X_center(x), Y_center(y), radius(r) { })

	< Color 클래스 작성 >
	1. 컬러를 저장하는 변수 작성
	2. 변수에 접근하기 위햔 public interface 작성
	3. ++연산자 오버로딩(void operator ++ ()) 작성
4. 파라미터가 있는 생성자 작성(public:
	enum { BLACK, RED, BLUE, GREEN, YELLOW, WHITE };
	Color(int c = BLACK) : color(c) { })
*/
//	< ColorCircle 클래스 >
		class ColorCircle : public Circle, Color {
		public:
			ColorCircle(int x, int y, int r = 20, int c = Color::RED) :
				Circle(x, y, r), Color(c) { }
			void Paint() {
				Circle::Paint();
				cout << ", the color number is " << Color::Col();
			}
			void operator ++ () {
				Color :: operator++ ();
				Circle :: operator++ ();
			}
	};

//	<Main 함수>
		int main() {
		int nRad1, nRad2;
		cout << "Input starting and final radius: ";
		cin >> nRad1 >> nRad2;
		for (ColorCircle cc(30, 30, nRad1, Color::RED);
			cc.Radius() < nRad2; ++cc) {
			cc.Paint();
			cout << endl;
		}
		system("pause");
		return 1;
	}
