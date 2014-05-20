#ifndef XCEPT_
#define XCEPT_

#include<new.h>

class BadInitializers
{
public:
	BadInitializers(){};
	
};

class NoMen
{
public:
	NoMen(){};
};

void my_new_handler()
{
	throw NoMen();
}

new_handler Old_Handler_ = set_new_handler(my_new_handler);
//_PNH Old_Handler_ = _set_new_handler(my_new_handler);

class OutOfBounds
{
public:
	OutOfBounds(){};

};

class SizeMismatch
{
public:
	SizeMismatch(){};

};

class MustBeZero
{
public:
	MustBeZero(){};
	
};

class BadInput
{
public:
	BadInput(){};

};


#endif
