/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

#include "rationalnumber.h"
#include "rationalnumbercollection.h"

int main()
{

    printf("Performing unit tests for RationalNumber...\n");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    /* Part 2 - RationalNumberCollection data type */

    RationalNumberCollection rnc;
    RationalNumber rn0 = {3, 4},
            rn1 = {6, 4},
            rn2 = {3, 2},
            rn3 = {-9, -6},
            rn4 = {0, 4},
            rn5 = {4, 0},
            rn6 = {5, -7},
            rn7 = {2, 5},
            rn8 = {2, 5},
            rn9 = {5, 3};

    rncInit(&rnc);

    rncAdd(&rnc, rn0);
    rncAdd(&rnc, rn0);
    rncAdd(&rnc, rn1);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn3);
    rncAdd(&rnc, rn6);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn3);
    rncAdd(&rnc, rn4);
    rncAdd(&rnc, rn5);
    rncAdd(&rnc, rn5);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn6);
    rncAdd(&rnc, rn7);
    rncAdd(&rnc, rn8);
    rncAdd(&rnc, rn9);

    showAllRnwc(&rnc);

    int rnCount = rncCount(&rnc, rn2);
    cout << "count: " << rnCount << endl;
    int rnIndexCount = rncRemove(&rnc, rn2);
    cout << "index: " << rnIndexCount << endl;
    rnCount = rncCount(&rnc, rn2);
    cout << "count: " << rnCount << endl;

    rnCount = rncCount(&rnc, rn9);
    cout << "count: " << rnCount << endl;
    rnIndexCount = rncRemove(&rnc, rn9);
    cout << "index: " << rnIndexCount << endl;
    rnCount = rncCount(&rnc, rn9);
    cout << "count: " << rnCount << endl;

    // total unique count should be 4
    //assert(rncTotalUniqueCount(&rnc) == 4);

    // total count should be 4
    //assert(rncTotalCount(&rnc) == 11);

    // sum should be ..
    RationalNumber rnSum = rncSum(&rnc);
    //assert((rnSum.num == 23) && (rnSum.denum == 28));

    // average should be ..
    RationalNumber rnAverage = rncAverage(&rnc);
    cout << "avg: " <<  rnAverage.num << "/" << rnAverage.denum << endl;
    //assert(rncAverage(&rnc) == 11);

    // median should be ..
    // TODO we need sort method for this to work properly
    RationalNumber rnMedian = rncMedian(&rnc);
    cout << "median: " << rnMedian.num << "/" << rnMedian.denum << endl;

    printf(" successful!\n");

    return 0;
}

