#ifndef LINEARLIST_
#define LINEARLIST_

#include <iostream>
#include "xcept.h"
#include "ChangeSize1D.h"

using namespace std;

template <class T>
class LinearList
{
	friend ostream& operator<<(ostream& out,LinearList<T>& x){x.Output(out);return out;};
public:
	LinearList();//构造函数
	~LinearList() {delete [] element;};//解析函数
	bool IsEmpty()const{return length==0;}//线性表是否为空
	int Length()const{return length;};//线性表长度
	int MaxSize()const{return Maxsize;};//线性表尺寸
	bool Find(int k,T& x)const;//查找第K位数据，并赋值到x
	int Search(T& x)const;//查找是否有值为x的元素，并返回位置k
	LinearList<T>& Insert(int k,const T& x);//在第K位后面插入x
	LinearList<T>& Delete(int k,T& x);//删除第K位，并将值赋到x中
	void Output(ostream &out) const;//输出线性表序列
	
private:
	int length;
	int Maxsize;
	T* element;
};

template<class T>
LinearList<T>::LinearList()
{
	Maxsize =1;
	length = 0;
	element =new T[Maxsize];
}

template<class T>
bool LinearList<T>::Find(int k,T& x)const
{
	if (k<1||k>length)
	{
		return false;
	}
	x = element[k-1];
	return true;
}

template<class T>
int LinearList<T>::Search(T& x)const
{
	int i=0;
	while ((x!=element[i])||i<length)
	{
		i++;
	}
	if (i<length)
		return i+1;
	else
		return 0;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k,T& x)
{
	if (Find(k,x))
	{
		for (int i =k-1; i <length-1; i++)
		{
			element[i] =element[i+1]; 
		}
		length--;
		if ((length <= Maxsize/4)&&Maxsize>1)
		{
			Maxsize /= 2;
			ChangeSize1D(element,length,Maxsize/2);
		}
		return *this;
	}
	else
	{
		throw OutOfBounds();
	}

}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T& x)
{
	if (k<0||k>length)
	{
		throw OutOfBounds();
	}
	if (length == Maxsize)
	{
		Maxsize *= 2;
		ChangeSize1D(element,length,Maxsize);
	}
	for (int i = length; i >k; i--)
	{
		element[i] = element[i-1];
	}
	element[k] = x;		
	length++;
	return *this;
}

template<class T>
void LinearList<T>::Output(ostream& out)const
{
	for (int i = 0; i < length; i++)
	{
		out<<element[i]<<" ";
	}
}


#endif
