#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Fraction {
	ll up, down;
} f1, f2;

ll gcv(ll a, ll b) {
	if(b == 0) {
		return a;
	}	else {
		return gcv(b, a % b);
	}
}

Fraction reduction(Fraction f) {
	if(f.down < 0) {
		f.up = -f.up;
		f.down = -f.down;
	}
	if(f.up == 0) {
		f.down = 1;
	} else {
		ll d = gcv(abs(f.up), abs(f.down));
		f.up /= d;
		f.down /= d;
	}
	return f; 
}

void printFac(Fraction f) {
	f = reduction(f);
	if(f.up < 0) {
		printf("(");
	}
	if(f.down == 1) {
		printf("%lld", f.up);
	} else if(abs(f.up) > abs(f.down)) {
		printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
	} else {
		printf("%lld/%lld", f.up, f.down);
	}
	if(f.up < 0) {
		printf(")");
	}
}

void sum(Fraction f1, Fraction f2) {
	Fraction ret;
	ret.up = f1.up * f2.down + f2.up * f1.down;
	ret.down = f1.down * f2.down;
	printFac(f1);
	printf(" + ");
	printFac(f2);
	printf(" = ");
	printFac(ret);
	printf("\n");
}

void difference(Fraction f1, Fraction f2) {
	Fraction ret;
	ret.up = f1.up * f2.down - f2.up * f1.down;
	ret.down = f1.down * f2.down;
	printFac(f1);
	printf(" - ");
	printFac(f2);
	printf(" = ");
	printFac(ret);
	printf("\n");
}

void product(Fraction f1, Fraction f2) {
	Fraction ret;
	ret.up = f1.up * f2.up;
	ret.down = f1.down * f2.down;
	printFac(f1);
	printf(" * ");
	printFac(f2);
	printf(" = ");
	printFac(ret);
	printf("\n");
}

void quotient(Fraction f1, Fraction f2) {
	Fraction ret;
	ret.up = f1.up * f2.down;
	ret.down = f1.down * f2.up;
	printFac(f1);
	printf(" / ");
	printFac(f2);
	printf(" = ");
	if(f2.up == 0) {
		printf("Inf");
	} else {
		printFac(ret);
	}
	printf("\n");
}

int main() {
	scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
	sum(f1, f2);
	difference(f1,f2);
	product(f1, f2);
	quotient(f1, f2);
	return 0;
}