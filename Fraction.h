#pragma once

#include <stdio.h>
#include <stdint.h>

template<class T>
struct Fraction {
	T Up = 0;
	T Buttom = 0;
};

template<class T> Fraction<T> ConstructFraction(T Number);
template<class T> Fraction<T> ConstructFraction(T Up, T Buttom);
template<class T> Fraction<T> Add(Fraction<T>& In, Fraction<T>& B);
template<class T> Fraction<T> Sub(Fraction<T>& In, Fraction<T>& B);
template<class T> Fraction<T> Mul(Fraction<T>& In, Fraction<T>& B);
template<class T> Fraction<T> Div(Fraction<T>& In, Fraction<T>& B);
template<class T> T Mod(Fraction<T>& In);
template<class T , class U> T Divide(Fraction<U>& In);
template<class T> T Up(Fraction<T>& In);
template<class T> T Buttom(Fraction<T>& In);