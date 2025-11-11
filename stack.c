#include<stdio.h>
int top=-1,s[5],i,item,choice;
void push(int item)
{
if(top>=4)
{
print("stack is full");
}
else
{
