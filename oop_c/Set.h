#ifndef SET_H
#define SET_H

const void * Set;
const void * Object;
void * add(void * _set, const void * _element);
void * drop(void * _set, const void * _element);
int contains(const void * _set, const void * _element);
int differ(const void * a, const void * b);

#endif