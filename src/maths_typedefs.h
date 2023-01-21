#ifndef __MATHS_TYPEDEFS_H__
#define __MATHS_TYPEDEFS_H__

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
    int xexponant;
    float value;
}exponantf;


#endif // __MATHS_TYPEDEFS_H__