#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int num, denum;
};

int calcGcd(int n, int m);

bool rnIsValid(RationalNumber n),
    rnEqual(RationalNumber n, RationalNumber m),
    rnLessThan(RationalNumber n, RationalNumber m);

RationalNumber rnAdd(RationalNumber n, RationalNumber m),
    rnSubstract(RationalNumber n, RationalNumber m),
    rnMultiply(RationalNumber n, RationalNumber m),
    rnDivide(RationalNumber n, RationalNumber m),
    rnNormalize(RationalNumber n);

#endif // RATIONALNUMBER_H
