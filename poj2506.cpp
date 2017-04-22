#include<stdio.h>
#include<string.h>
#include<iosteam>
#include<algorithm>

using namespace std;
const int Base = 1e9;
const int Capacity = 100;

struct BigInt{
    int Len;
    int Data[Capacity];
    BigInt() : Len(0) {}
    BigInt(const BigInt &V) : Len(V.len) {memcpy (Data, V.Data, Len*(sizeof*Data));}
    BigInt(int V) : Len(0) {
        for (; V > 0; V /= Base)
            Data[Len++] = V%Base;
    }

    BigInt & operator = (const BigInt &V) {
        Len = V.Len;
        memcpy(Data, V.Data, Len*(sizeof*data));
        return *this;
    }

    int & operator[] (int Index) {
        return Data[Index];
    }

    int operator[] (int Index) const {
        return Data[Index];
    }
};

int compare(const BigInt &A, const BigInt &B) {
    if (A.Len != B.Len)
        return A.Len > B.Len ? 1 : -1;
    int i = A.Len - 1;
    while (A[i] == B[i]) i--;
    if (i < 0) 
        return 0;
    return A[i] > B[i] ? 1 : -1;
}

BigInt operator + (const BigInt &A, const BigInt &B) {
    int i, Carry = 0;
    BigInt R;
    for (i = 0; i < A.Len || i < B.Len || Carry > 0; i++) {
        if (i < A.Len) Carry += A[i];
        if (i < B.Len) Carry += B[i];
        R[i] = Carry % Base;
        Carry /= Base;
    }
    R.Len = i;
    return R;
}

BigInt operator - (const BigInt &A, const BigInt &B) {
    int i, Carry = 0;
    BigInt R;
    R.Len = A.Len;
    for (i = 0; i < R.Len; i++) {
        R[i] = A[i] - Carry;
        if (i < B.Len) 
            R[i] -= B[i];
        if (R[i] < 0) {
            Carry = 1;
            R[i] += Base;
        } else {
            Carry = 0;
        }
    }
    while (R.Len > 0 && [R.Len - 1] == 0) 
        R.Len --;
    return R;
}

BigInt operator * (const BigInt &A, const int &B) {
    int i;
    long long Carry = 0;
    for (i = 0; i < A.Len || Carry > 0; i++) {
        if (i < A.Len) 
            Carry += long long (A[i]) * B;
        R[i] = Carry % Base;
        Carry /= Base;
    }
    R.Len = i;
    return R;
}


    BigInt(const BigInt &V) : Len(V.len) {memcpy (Data, V.Data, Len*sizeof*Data);}
