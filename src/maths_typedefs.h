#ifndef __MATHS_TYPEDEFS_H__
#define __MATHS_TYPEDEFS_H__
#include "combinetext.h"

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
    float value;
    int exponant;
    std::string display()
    {
        return combinetext("%gx^%f",value,exponant);
    }
}exponantf;


#endif // __MATHS_TYPEDEFS_H__