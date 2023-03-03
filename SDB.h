#ifndef SDB_H_
#define SDB_H_
#include "std.h"
typedef struct SimpleDb
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
struct SimpleDb *next;
} student;



bool SDB_isfull ();
void SDB_GetUsedSize ();
bool SDB_AddEntry ();
void SDB_DeleteEntry ();
bool SDB_ReadEntry ();
void SDB_GetList ();
bool SDB_IsIdExist ();
#endif