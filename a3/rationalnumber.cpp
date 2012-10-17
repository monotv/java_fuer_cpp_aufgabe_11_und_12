#include "rationalnumber.h"
#include "utils.h"
#include <stdio.h>
#include <iostream>
using namespace std;

bool rnIsValid(RationalNumber n){
    if(n.denum == 0){
        return 0;
    }
    return 1;
}
bool rnEqual(RationalNumber n, RationalNumber m){
    if(n.denum == 0 || m.denum == 0){
        return 0;
    }
    n = rnNormalize(n);
    m = rnNormalize(m);
    if(n.num == m.num && n.denum == m.denum){
        return 1;
    }
    return 0;
}
bool rnLessThan(RationalNumber n, RationalNumber m){
    RationalNumber nTemp,
            mTemp;
    n = rnNormalize(n);
    m = rnNormalize(m);
    nTemp = n;
    mTemp = m;
    n.num = nTemp.num * abs(mTemp.denum);
    n.denum = nTemp.denum * abs(mTemp.denum);
    m.num = mTemp.num * abs(nTemp.denum);
    m.denum = mTemp.denum * abs(nTemp.denum);
    // After both denumerators are the same, except their sign,
    // the numerators decide
    if((n.num < m.num && n.denum == m.denum) || (n.num <= m.num && n.denum < m.denum)){
        return 1;
    }
    return 0;
}
RationalNumber rnAdd(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.num = (n.num * m.denum) + (m.num * n.denum);
    result.denum = (n.denum * m.denum);
    result = rnNormalize(result);
    return result;
}

RationalNumber rnSubstract(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.num = (n.num * m.denum) - (m.num * n.denum);
    result.denum = (n.denum * m.denum) - (m.denum * n.denum);
    result = rnNormalize(result);
    return result;
}

RationalNumber rnMultiply(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.num = n.num * m.num;
    result.denum = n.denum * m.denum;
    return result;
}
RationalNumber rnDivide(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.num = n.num * m.denum;
    result.denum = n.denum * m.num;
    result = rnNormalize(result);
    return result;
}
int calcGcd(int n, int m){
    int gcd;
    if(m == 0){
        return n;
    } else {
        return calcGcd(m, n%m);
    }
    return gcd;
}
RationalNumber rnNormalize(RationalNumber n){
    RationalNumber result;
    int gcd;
    if(n.denum < 0){
        n.num *= -1;
        n.denum *= -1;
    }
    gcd = calcGcd(n.num, n.denum);
    gcd = abs(gcd);
    result.num = n.num / gcd;
    result.denum = n.denum / gcd;
    return result;
}
