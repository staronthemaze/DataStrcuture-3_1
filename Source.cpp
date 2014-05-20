#include"LinearList.h"

int main()
{
	LinearList<int> L;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	cout<<"MaxSize = "<<L.MaxSize()<<endl;
	L.Insert(0,2);
	L.Insert(1,6);
	cout<<"List is "<<L<<endl;
	cout<<"MaxSize = "<<L.MaxSize()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	int z;
	L.Find(1,z);
	cout<<"First Element is "<<z<<endl;
	cout<<"Length is "<<L.Length()<<endl;
	L.Delete(1,z);
	cout<<"Deleted Element is "<<z<<endl;
	cout<<"MaxSize = "<<L.MaxSize()<<endl;
	cout<<"List is"<<L<<endl;
	while (true)
	{

	}
}
