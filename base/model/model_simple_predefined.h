#ifndef MODEL_SIMPLE_PREDEFINED_H
#define MODEL_SIMPLE_PREDEFINED_H


#define TRIANGLE_MACRO(x1,y1,z1,x2,y2,z2,x3,y3,z3) x1,y1,z1,x2,y2,z2,x3,y3,z3
#define TRIANGLE2D_MACRO(x1,y1,x2,y2,x3,y3,z) TRIANGLE_MACRO(x1,y1,z,x2,y2,z,x3,y3,z)
#define TRIANGLE2D_MACRO(x1,y1,x2,y2,x3,y3,z) TRIANGLE_MACRO(x1,y1,z,x2,y2,z,x3,y3,z)
#define QUAD_MACRO(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4) TRIANGLE_MACRO(x1,y1,z1,x2,y2,z2,x3,y3,z3),TRIANGLE_MACRO(x2,y2,z2,x4,y4,z4,x3,y3,z3)
#define QUAD2D_MACRO(x1,y1,x2,y2,x3,y3,x4,y4,z) QUAD_MACRO(x1,y1,z,x2,y2,z,x3,y3,z,x4,y4,z)
#define RECTANGLE_MACRO(x1,y1,z1,z2,x3,y3,z3,z4) QUAD_MACRO(x1,y1,z1,x2,y1,z2,x2,y2,z3,x1,y2,z4)
#define RECTANGLE2D_MACRO(x1,y1,x3,y3,z) RECTANGLE_MACRO(x1,y1,z,z,x3,y3,z,z)

#endif // MODEL_SIMPLE_PREDEFINED_H
