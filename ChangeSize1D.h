template<class T>
void ChangeSize1D(T* &a,int n,int ToSize)
	{
	T* temp = new T[ToSize];
	if (n>=ToSize)//缩小数组尺寸
	{
		for (int i = 0; i < ToSize; i++)
		{
			temp[i] = a[i];
		}
		delete [] a;
		a = temp;
	}
	else//扩大数组尺寸
	{
		for (int i = 0; i < n; i++)
		{
			temp[i] = a[i];
		}
		delete [] a;
		a = temp;
	}
}
//版本3
