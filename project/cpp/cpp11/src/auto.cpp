#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class A {
private:
	int a1;
	float a2;
public:
	void seta1(int _a1) { a1 = _a1; }
	void print() {
		cout << "a1:" << a1 << endl;
	}
};
class B {
private:
	int b1;
	float b2;
public:
	void setb1(int _b1) { b1 = _b1; }
	void print() {
		cout << "b1:" << b1 << endl;
	}
};

template<class T1,class T2>
auto add(T1 a, T2 b)->decltype(a+b) {
	return a + b;
}
auto add(int a,float b)->decltype(a){
	return a + b;
}

auto add(A a,B b)->decltype(a){
	return a;
}

auto add(double a,float b)->float{
	return a + b;
}
template<class T1,class T2>
auto add(T1 a,T2 b){
	return a + b;
}
int main_auto() {
	{
		auto a = A();
		auto b = B();
		a.seta1(10);
		b.setb1(100);
		a.print();
		b.print();

		auto c1 = add(10, 10.2f);
		cout << "c1:" << c1 << endl;

		int arr[100];

		//for (int i = 0; i < 100; i++) {
		//	arr[i] = i;
		//}
		int i = 0;
		//for (auto e : arr) {
		//	e = i++;
		//}
		for (auto& e : arr) {
			e = i++;
		}

		for (auto e : arr) {
			cout << "e:" << e << endl;
		}
	}

	{
		//auto i = 0, d = 0.0f;
		auto i1 = 0, *p1 = &i1;
		auto i2 = 0, &r2 = i2;
	}

	{
		double a = 1.0;
		float b = 1.0f;
		float ab = add(a,b);
		double abd = add(a,b);	
		double bd = b;	
	}

	{
		A a;
		B b;
		A ab=add(a,b);
		//B abb = add(a,b);
	}

	system("PAUSE");
	return 0;
}