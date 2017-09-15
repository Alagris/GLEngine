#ifndef SWITCH_CASE_ENUM_TO_STRING_H_INCLUDED
#define SWITCH_CASE_ENUM_TO_STRING_H_INCLUDED


#define ENUM_CASE(glenum,output) case (glenum): \
									output=#glenum;\
									break;

#endif // SWITCH_CASE_ENUM_TO_STRING_H_INCLUDED
