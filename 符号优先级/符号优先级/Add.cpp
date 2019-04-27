#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//add.c源文件
/*static*/ int  Add(int x, int y)    //具有外部链接属性
{
	return x + y;
}
/*static*/ int g_val = 2016;    //具有外部链接属性