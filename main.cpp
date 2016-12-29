#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class C {

public:
	C() {
		cout << "C::C() of \t" << this << endl;
	}

	C(C &other) {
		cout << "C::C(C &other) of \t" << this << " from \t" << &other << endl;
	}

	C(const C &other) {
		cout << "C::C(const C &other) of \t" << this << " from \t" << &other << endl;
	}

//	C operator=(C other) {
//		cout << "C::operator=(C other) of \t" << this << " from \t" << &other << endl;
//		return *this;
//	}

//	C operator=(C &other) {
//		cout << "C::operator=(C &other) of \t" << this << " from \t" << &other << endl;
//		return *this;
//	}

//	C operator=(const C &other) {
//		cout << "C::operator=(const C &other) of \t" << this << " from \t" << &other << endl;
//		return *this;
//	}

	C operator=(C &other) const {
		cout << "C::operator=(C &other) const of \t" << this << " from \t" << &other << endl;
		return *const_cast<C*>(this);
	}

//	C operator=(const C &other) const {
//		cout << "C::operator=(const C &other) const of \t" << this << " from \t" << &other << endl;
//		return *const_cast<C*>(this);
//	}

	C& operator=(C &other) {
		cout << "C::&operator=(C &other) of \t" << this << " from \t" << &other << endl;
		return *this;
	}

//	C& operator=(C other) {
//		cout << "C::&operator=(C other) of \t" << this << " from \t" << &other << endl;
//		return *this;
//	}

//	C& operator=(const C &other) {
//		cout << "C::&operator=(C &other) of \t" << this << " from \t" << &other << endl;
//		return *this;
//	}

//	C& operator=(C &other) const {
//		cout << "C::&operator=(C &other) const of \t" << this << " from \t" << &other << endl;
//		return *const_cast<C*>(this);
//	}

	C& operator=(const C &other) const {
		cout << "C::&operator=(const C &other) const of \t" << this << " from \t" << &other << endl;
		return *const_cast<C*>(this);
	}

	~C() {
		cout << "C::~C() of \t" << this << endl;
	}
};

C g() {
	cout << "In g(), before C r;" << endl;
	C r;
	cout << "In g(): \t" << &r << endl;
	cout << "In g(), before return" << endl;
	return r;
}

C& h() {
	cout << "In &h(), before C r;" << endl;
	C r;
	cout << "In &h(): \t" << &r << endl;
	cout << "In &h(), before return" << endl;
	return r;
}

C i() {
	cout << "In i(), before r = C();" << endl;
	auto r = C();
	cout << "In i(): \t" << &r << endl;
	cout << "In i(), before return" << endl;
	return r;
}

C& j() {
	cout << "In &j(), before r = C();" << endl;
	auto r = C();
	cout << "In &j(): \t" << &r << endl;
	cout << "In &j(), before return" << endl;
	return r;
}

C k() {
	cout << "In k(), before C r((C()));" << endl;
	C r((C()));
	cout << "In k(): \t" << &r << endl;
	cout << "In k(), before return" << endl;
	return r;
}

C& l() {
	cout << "In &l(), before C r((C()));" << endl;
	C r((C()));
	cout << "In &l(): \t" << &r << endl;
	cout << "In &l(), before return" << endl;
	return r;
}

C m() {
	cout << "In m(), before r = C();" << endl;
	auto r = C();
	cout << "In m(): \t" << &r << endl;
	cout << "In m(), before return" << endl;
	return r;
}

C& n() {
	cout << "In &n(), before r = C();" << endl;
	auto r = C();
	cout << "In &n(): \t" << &r << endl;
	cout << "In &n(), before return" << endl;
	return r;
}

C o() {
	cout << "In o(), before r = t;" << endl;
	C t;
	auto r = t;
	cout << "In o(): \t" << &r << endl;
	cout << "In o(), before return" << endl;
	return r;
}

C& p() {
	cout << "In &p(), before r = t;" << endl;
	C t;
	auto r = t;
	cout << "In &p(): \t" << &r << endl;
	cout << "In &p(), before return" << endl;
	return r;
}

C* q() {
	cout << "In q(), before r = new C();" << endl;
	auto r = new C();
	cout << "In q(): \t" << r << endl;
	cout << "In q(), before return" << endl;
	return r;
}

C& r() {
	cout << "In &r(), before return *new C();" << endl;
	return *new C();
}

C s() {
	C t, r;
	cout << "In s(): \t" << &r << endl;
	cout << "In s(), before r = t;" << endl;
	r = t;
	cout << "In s(): \t" << &r << endl;
	cout << "In s(), before return" << endl;
	return r;
}

C& t() {
	C t, r;
	cout << "In &t(): \t" << &r << endl;
	cout << "In &t(), before r = t;" << endl;
	r = t;
	cout << "In &t(): \t" << &r << endl;
	cout << "In &t(), before return" << endl;
	return r;
}

void f() {
	cout << "In f(), before C a;" << endl;
	C a;
	cout << "In f(): a: \t" << &a << endl;
	cout << "In f(), before a = g();" << endl;
	a = g();
	cout << "In f(): a: \t" << &a << endl;
	cout << "In f(), before auto b = g();" << endl;
	auto b = g();
	cout << "In f(): b: \t" << &b << endl;
	cout << "In f(), before C c(g());" << endl;
	C c(g());
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before auto d = C(g());" << endl;
	auto d = C(g());
	cout << "In f(): d: \t" << &d << endl;

	cout << "In f(), before c = g();" << endl;
	c = g();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = h();" << endl;
	c = h();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = i();" << endl;
	c = i();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = j();" << endl;
	c = j();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = k();" << endl;
	c = k();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = l();" << endl;
	c = l();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = m();" << endl;
	c = m();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = n();" << endl;
	c = n();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = o();" << endl;
	c = o();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = p();" << endl;
	c = p();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = q();" << endl;
	auto e = q();
	cout << "In f(): e: \t" << e << endl;
	cout << "In f(), before c = r();" << endl;
	c = r();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = s();" << endl;
	c = s();
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(), before c = t();" << endl;
	c = t();
	cout << "In f(): c: \t" << &c << endl;


	cout << "In f(): a: \t" << &a << endl;
	cout << "In f(): b: \t" << &b << endl;
	cout << "In f(): c: \t" << &c << endl;
	cout << "In f(): d: \t" << &d << endl;
	cout << "In f(): e: \t" << e << endl;
	cout << "In f(), before return" << endl;
	return;
}

int main(int argc, char *argv[])
{
	f();
	return 0;
}
