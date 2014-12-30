#ifndef NEW_H
#define NEW_H


#if !defined MANY || MANY < 1
#define MANY 10
#endif

void* new(const void * type, ...);
void delete(void * _item);

#endif