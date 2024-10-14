#include <stdio.h>
#include <stdint.h>

template<class T>
struct Fraction {
	T Up = 0;
	T Buttom = 0;
};


template<class T>
Fraction<T> ConstructFraction(T Number) {
	Fraction<T> F;
	F.Up = Number;
	F.Buttom = 1;

	return F;
}
template<class T>
Fraction<T> ConstructFraction(T Up, T Buttom) {
	Fraction<T> F;
	F.Up = Up;
	F.Buttom = Buttom;

	return F;
}

intmax_t GCD(intmax_t A, intmax_t B) {
	intmax_t X = A % B;
	intmax_t Y = A;

	while(X != 0) {
		Y = X;
		X = Y % X;
	}
	return Y;
}

template<class T>
Fraction<T> Add(Fraction<T>& In, Fraction<T>& B) {
	Fraction<T> A = In;
	Fraction<T> C = B;
	Fraction<T> R;
	int X = GCD(In.Buttom, B.Buttom);

	int Y = In.Buttom / X;
	int Z = B.Buttom / X;

	A.Up *= Y;
	A.Buttom *= Y;
	C.Up *= Z;
	C.Buttom *= Z;
	R.Buttom = A.Buttom;
	R.Up = A.Up + B.Up;

	int D=GCD(R.Up, R.Buttom);
	R.Up /= D;
	R.Buttom /= D;
	return R;
}

template<class T>
Fraction<T> Sub(Fraction<T>& In, Fraction<T>& B) {
	Fraction<T> A = In;
	Fraction<T> C = B;
	Fraction<T> R;
	int X = GCD(In.Buttom, B.Buttom);

	int Y = In.Buttom / X;
	int Z = B.Buttom / X;

	A.Up *= Y;
	A.Buttom *= Y;
	C.Up *= Z;
	C.Buttom *= Z;
	R.Buttom = A.Buttom;
	R.Up = A.Up - B.Up;

	int D=GCD(R.Up, R.Buttom);
	R.Up /= D;
	R.Buttom /= D;
	return R;
}

template<class T>
Fraction<T> Mul(Fraction<T>& In, Fraction<T>& B) {
	Fraction<T> R;
	R.Up = In.Up * B.Up;
	R.Buttom = In.Buttom * B.Buttom;

	int X = GCD(R.Up, R.Buttom);
	R.Up /= X;
	R.Buttom /= X;

	return R;

}template<class T>
Fraction<T> Div(Fraction<T>& In, Fraction<T>& B) {
	Fraction<T> R;
	Fraction<T> C;
	C.Up = B.Buttom;
	C.Buttom = B.Up;
	R.Up = In.Up * C.Up;
	R.Buttom = In.Buttom * C.Buttom;

	int X = GCD(R.Up, R.Buttom);
	R.Up /= X;
	R.Buttom /= X;

	return R;
}
int main() {
	Fraction<int> A = ConstructFraction<int>(16, 21);
	Fraction<int> B = ConstructFraction<int>(21, 15);
	Fraction<int> C = ConstructFraction<int>(0, 0);

	C = Add(A, B);
	C = Sub(A, B);
	C = Mul(A, B);
	C = Div(A, B);
}
