#ifndef STACK_H
#define STACK_H

//FABRICIO MONSALVE 20131411
void Stack_create(int *&stack);
void Stack_push(int *&stack, int item);
int Stack_pop(int *&stack, int &item);
bool Stack_isEmpty(int *&stack);
int Stack_size(int *&stack);
void Stack_resize(int *&stack);

void Stack_create(double *&stack);
void Stack_push(double *&stack, double item);
int Stack_pop(double *&stack, double &item);
bool Stack_isEmpty(double *&stack);
int Stack_size(double *&stack);
void Stack_resize(double *&stack);



#endif /* STACK_H */

