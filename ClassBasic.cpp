// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//todo: const, static https://modoocode.com/197


namespace ClassBasicNamespace {
	//////////////////////////////////////////////////
	// 키워드: 클래스 생성자, 오버로딩, 소멸자
	//////////////////////////////////////////////////

	class MyClass {
	private:
		int value;
		int size;
		int* arr;
	public:
		MyClass() {
			// 멤버 변수 값 초기화
			value = 1;
			size = 10;
			// 멤버 변수 중 포인터 배열 초기화
			arr = new int[size];
			initializeArr();
			cout << "My Class 생성자(디폴트): value: " << value << this->size << endl;
			cout << "생성자 배열 주소: " << &arr[0] << endl;
		};
		MyClass(int value, int size) {
			// 멤버 변수 값 초기화
			this->value = value;
			this->size = size;

			// 멤버 변수 중 포인터 배열 초기화
			arr = new int[size];
			initializeArr();
			std::cout << "My Class 생성자(파라미터): value: " << this->value << "  " << this->size << std::endl;

			cout << "생성자 배열 주소: " << &arr[0] << endl;
		};
		MyClass(const MyClass& cls) {
			cout << "My Class 복사 생성자 " << endl;
			// 멤버 변수 값 초기화(deep copy):
			this->value = cls.value;
			this->size = cls.size;

			// good case - 새로운 주소에 값이 할당 된다
			arr = new int[size];
			initializeArr();


			// bad case - 같은 주소를 바라보기 때문에 소멸 명령이 중복되어 처리 > 없는 위치라는 에러가 발생
			// this->arr = cls.arr;
			cout << "복사 생성자 배열 주소: " << &arr[0] << endl;
		};
		void printOverloading() {
			cout << "printOverloading 오버로딩: 파라미터 없음: " << value * 3.14 << endl;
		};
		void printOverloading(double pi) {
			cout << "printOverloading 오버로딩: 파라미터 있음: " << value * pi << endl;
		}

		void printOverloadingRule(int pi) {
			cout << "printOverloadingRule 오버로딩 int 타입: " << value * pi << endl;
		}
		void printOverloadingRule(double pi) {
			cout << "printOverloadingRule 오버로딩: double 타입: " << value * pi << endl;
		}
		/*void printOverloadingRule(char pi) {
			cout << "input char type " << radius * pi << endl;
		}*/

		void initializeArr() {
			for (int index = 0;index < size;index++) {
				arr[index] = value + 10 + index;
				//cout << arr[index] << " ";
			}
		}

		~MyClass() {
			cout << "My Class 소멸자: " << value << "   " << arr[size - 1] << endl;
			delete arr;
		}
	};

	class MyClassChild : MyClass {
	public:
		MyClassChild() {
			cout << "My Class Child 생성자(기본)" << endl;
		};
		~MyClassChild() {
			cout << "My Class Child 소멸자: " << endl;
		};
	};
}
void ClassBasicMain() {
	
	ClassBasicNamespace::MyClass overloadingCls;
	cout << "=================== 함수 오버로딩 ===================" << endl;
	overloadingCls.printOverloading();
	overloadingCls.printOverloading(4.1);
	cout << endl;
	
	// 오버로딩 룰
	cout << "=================== 오버로딩 룰 ===================" << endl;
	cout << "int: 3 ";
	overloadingCls.printOverloadingRule(3);
	cout << "char: 4 ";
	overloadingCls.printOverloadingRule('4');
	cout << "double: 5.14 ";
	overloadingCls.printOverloadingRule(5.14); // getAreaOverloadingRule(char pi) 존재 여부에 다라 good case/ bad case
	// double -> int, char 둘 다 가능 (임의의 숫자 타입이 임의의 숫자 타입
	cout << endl;

	
	// 클래스 생성자
	cout << "=================== 클래스 생성자 ===================" << endl;
	ClassBasicNamespace::MyClass initCls;
	ClassBasicNamespace::MyClass initClsWithParam(-1, 3);
	cout << endl;

	// 복사 생성자
	cout << "=================== 복사 생성자 ===================" << endl;
	ClassBasicNamespace::MyClass copyInitClass(overloadingCls);
	cout << "char: 4 ";
	overloadingCls.printOverloadingRule('4');

	// 소멸자
	cout << endl;
	cout << "=================== 소멸자 ===================" << endl;



}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
