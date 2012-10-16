#include "rationalnumber.h"
#include "rationalnumbercollection.h"
#include "utils.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*  binary search
 *  source: http://en.wikipedia.org/wiki/Binary_search_algorithm
 */
int midpoint(int imin, int imax){
    return imin + ((imax - imin) / 2);
}
int binarySearch(RationalNumberWithCount A[], RationalNumber key, int imin, int imax){
  // continually narrow search until just one element remains
  int imid;
  while (imin < imax)
    {
      imid = midpoint(imin, imax);

      // code must guarantee the interval is reduced at each iteration
      assert(imid < imax);
      // note: 0 <= imin < imax implies imid will always be less than imax

      // reduce the search
      if (rnLessThan(A[imid].n, key))
        imin = imid + 1;
      else
        imax = imid;
    }
  // At exit of while:
  //   if A[] is empty, then imax < imin
  //   otherwise imax == imin

  // deferred test for equality
  if ((imax == imin) && (rnEqual(A[imid].n, key)))
    return imin;
  else
    return -1;
}

void rncInit(RationalNumberCollection* c){
    RationalNumber rn = {0, 0};
    RationalNumberWithCount defaultValue = {rn, 0};
    c->length = 0;
    // set fields of array values to default value
    for(int i;i<RNC_MAX;i++){
        c->rnwcar[i] = defaultValue;
    }
}
int rncAdd(RationalNumberCollection *c, RationalNumber n){
    if(n.denum == 0){
        return 0;
    }
    n = rnNormalize(n);
    for(int i = 0;i<c->length;i++){
        // if value is allready in array
        if(rnEqual(n, c->rnwcar[i].n)){
            c->rnwcar[i].count++;
            return i;
        }
        // shift right if new value is less than current [i]
        if(rnLessThan(n, c->rnwcar[i].n)){
            for(int j = c->length;j>i;j--){
                c->rnwcar[j] = c->rnwcar[j-1];
            }
            c->rnwcar[i].n = n;
            c->rnwcar[i].count = 1;
            c->length++;
            return i;
        }
    }
    // new value that is biggest
    c->rnwcar[c->length].n = n;
    c->rnwcar[c->length].count = 1;
    c->length++;
    return c->length;
}
int rncRemove(RationalNumberCollection *c, RationalNumber n){
    RationalNumber rn = {0, 0};
    RationalNumberWithCount defaultValue = {rn, 0};
    int index = binarySearch(c->rnwcar, n, 0, c->length);
    if(index == -1){
        return index;
    } else {
        c->rnwcar[index].count--;
        // shift array left if count is 0 and rn is deleted from array
        if(c->rnwcar[index].count == 0){
            for(int i = index;i<c->length;i++){
                c->rnwcar[index] = c->rnwcar[index+1];
            }
            c->rnwcar[c->length] = defaultValue;
            return 0;
        } else {
            return c->rnwcar[index].count;
        }
        return 1;
    }
    return -1;
}
int rncCount(RationalNumberCollection *c, RationalNumber n){
    RationalNumberWithCount rnwc;
    int index = binarySearch(c->rnwcar, n, 0, c->length);
    if(index == -1){
        return 0;
    } else {
        rnwc = c->rnwcar[index];
        return rnwc.count;
    }
}

int rncTotalUniqueCount(RationalNumberCollection *c){
    return c->length;
}

int rncTotalCount(RationalNumberCollection *c){
    int count = 0;
    for(int i = 0;i<c->length;i++){
        count += c->rnwcar[i].count;
    }
    return count;
}

RationalNumber rncSum(RationalNumberCollection *c){
    RationalNumber sum = c->rnwcar[0].n;
    for(int i = 0;i<c->length;i++){
        sum = rnAdd(sum, c->rnwcar[i].n);
    }
    return sum;
}

RationalNumber rncAverage(RationalNumberCollection *c){
    RationalNumber num = rncSum(c),
            denum = {rncTotalCount(c), 1},
            average = rnDivide(num, denum);
    return average;
}

RationalNumber rncMedian(RationalNumberCollection *c){
    RationalNumber median,
            num,
            denum = {2, 1};
    if(c->length == 1){
        return c->rnwcar[0].n;
    }
    if(c->length%2 == 0){
        num = rnAdd(c->rnwcar[(c->length/2)-1].n, c->rnwcar[c->length/2].n);
        median = rnDivide(num, denum);
    } else {
        median = c->rnwcar[(c->length/2)+1].n;
    }
    return median;
}
void showAllRnwc(RationalNumberCollection *c){
    int i = 0;
    while(c->rnwcar[i].count != 0){
        cout << "RationalNumber #" << i << ": " << c->rnwcar[i].n.num << "/" << c->rnwcar[i].n.denum << " count: " << c->rnwcar[i].count << endl;
        i++;
    }
}
