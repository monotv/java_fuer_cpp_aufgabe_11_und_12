#include "rationalnumber.h"
#include <string>
using namespace std;

#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

struct RationalNumberWithCount {
    RationalNumber n;
    int count;
};

/*struct RNC_CONF {
    static const int RNC_MAX = 1000;
    static const string RNC_SORT_METHOD = "merge";
};*/

static const int RNC_MAX = 1000;
static const string RNC_SORT_METHOD = "merge";

struct RationalNumberCollection {
    RationalNumberWithCount rnwcar[RNC_MAX];
    int length;
};
void showAllRnwc(RationalNumberCollection *c);
void rncSort(RationalNumberCollection *c, int length);
void mergeSort(RationalNumberCollection *c, int length);
void rncInit(RationalNumberCollection *c);
int rncAdd(RationalNumberCollection *c, RationalNumber n);
int rncCount(RationalNumberCollection *c, RationalNumber n);
int rncRemove(RationalNumberCollection *c, RationalNumber n);
int rncTotalUniqueCount(RationalNumberCollection *c); // count of unique rn
int rncTotalCount(RationalNumberCollection *c); // count of all rn
RationalNumber rncSum(RationalNumberCollection *c); // sum of all rn
RationalNumber rncAverage(RationalNumberCollection *c); // average of all rn
RationalNumber rncMedian(RationalNumberCollection *c); // median of all rn

#endif // RATIONALNUMBERCOLLECTION_H
