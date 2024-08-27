// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//todo: const, static https://modoocode.com/197


namespace ClassOverloadingNamespace {
	//////////////////////////////////////////////////
	// 키워드: 클래스 생성자, 오버로딩, 소멸자
	//////////////////////////////////////////////////

	class MyClass {
	private:
		int value;
		int size;
		int* arr;
		int getValuePrivate() {
			return this->value;
		}
	protected:
		int getValueProtected() {
			cout << "부모 getValueProtected";
			return this->value;
		};
	public:
		MyClass() {
			// 멤버 변수 값 초기화
			value = 1;
			size = 10;
			// 멤버 변수 중 포인터 배열 초기화
			arr = new int[size];
			initializeArr();
			cout << "My Class 생성자(디폴트): value: " << value << "  "<< this->size << endl;
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
		void action() {
			cout << "My Class action 함수" << endl;
		};
		void overridingAction() {
			cout << "My Class overridingAction 함수" << endl;
		}
		int getValuePublic() {
			cout << "부모 getValuePublic";
			return this->value;
		};

		void printValueNotVirtual() {
			cout << "부모 not virtual 함수 " <<  endl;
		}

		virtual void printValueVirtual() {
			cout << "부모 virtual 함수 " << endl;
		}

		// etc
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

	class MyClassChild :public MyClass {
	public:
		MyClassChild(): MyClass() {
			cout << "My Class Child 생성자(기본)" << endl;
		};
		MyClassChild(int value, int size): MyClass(value, size) {
			cout << "My Class Child 생성자(인자)" << endl;			
			
		};
		MyClassChild(const MyClassChild& target): MyClass(target) {		
		}
		void overridingAction() {
			cout << "My Class Child overridingAction 함수" << endl;
		}
		int getValueChildPublic() {
			cout << "자식 getValueChildPublic -> ";
			return this->getValueProtected();
		}
		void printValueNotVirtual() {
			cout << "자식 함수 " <<  endl;
		}
		void printValueVirtual()override {
			cout << "자식 virtual 함수 " << endl;
		}
		~MyClassChild() {
			cout << "My Class Child 소멸자" << endl;
		};
	};
}
int main() {
	// 상속
	cout << endl;
	cout << "=================== 상속 ===================" << endl;
	ClassOverloadingNamespace::MyClassChild child;

	// 접근 지정자
	cout << endl;
	cout << "=================== 접근 지정자 ===================" << endl;
	cout << "public "; 
	child.getValuePublic();
	cout << endl<<"protected ";
	child.getValueChildPublic();

	// 오버라이딩
	cout << endl;
	cout << "=================== 오버라이딩 ===================" << endl;
	child.action();
	child.overridingAction();

	// is-a
	cout << "=================== is-a ===================" << endl;
	ClassOverloadingNamespace::MyClassChild child2(5, 5);
	ClassOverloadingNamespace::MyClass* p_c = &child2;
	ClassOverloadingNamespace::MyClass* p_p = new ClassOverloadingNamespace::MyClass(4, 4);
	p_c->overridingAction();
	cout << endl;

	// virtual
	p_c->printValueNotVirtual();
	p_c->printValueVirtual();
	p_p->printValueVirtual();

	// 소멸자
	cout << endl;
	cout << "=================== 소멸자 ===================" << endl;
	delete p_p;


}
