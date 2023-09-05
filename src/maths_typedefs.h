#ifndef __MATHS_TYPEDEFS_H__
#define __MATHS_TYPEDEFS_H__
#include "combinetext.h"
#include <vector>

typedef struct point
{
    float x,y;
    point(float,float);

}point;


typedef struct stdform
{
    float a,b,c;
    stdform(float,float,float);
}stdform;

typedef struct exponantf
{
    float coefficent;
    size_t exponant;
}exponantf;


#endif // __MATHS_TYPEDEFS_H__