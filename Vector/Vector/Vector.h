#pragma once
#include <vector>
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
template <class T>
class Vector
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;
	//vector初始容量：
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	void PushBack(const T& val)
	{
		//判断容量
		/*if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newCapacity);
		}
		*_finish++ = val;*/
		Insert(end(), val);
	}

	Vector(const Vector<T>& v)
	{
		//考虑深拷贝
		//开空间
		//拷贝
		_start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}
	// v1 = v2 = v3 = v4
	//Vector<T>& operator=(const Vector<T>& v)
	//{
	//	//检查是否自己赋值
	//	//返回值类型： 引用， 为了连续赋值
	//	//返回： *this
	//	if (this != &v)
	//	{
	//		T* tmp = new T[v.Capacity()];
	//		for (int i = 0; i < v.Size(); i++)
	//		{
	//			tmp[i] = v[i];
	//		}
	//		if (_start)
	//		{
	//			delete[] _start;
	//		}
	//		_start = tmp;
	//		_finish = _start + v.Size();
	//		_endOfStorage = _start + v.Capacity();
	//	}

	//	return *this;
	//}
	// v1 = v2   v2 --> v  
	Vector<T> operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}

	void PopBack()
	{
		Erase(end() - 1);
		//Erase(_finish - 1);
	}
	//可读可写
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	size_t Capacity() const
	{
		return _endOfStorage - _start;
	}

	bool Empty()
	{
		return _start == _finish;
	}

	size_t Size() const
	{
		return _finish - _start;
	}

	//可读可写
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//只读
	const_iterator begin() const 
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			int len = Size();
			//开辟新的空间
			T* tmp = new T[n];
			//拷贝原有空间的内容
			// memcpy : 浅拷贝
			/*if (_start)
			{
				memcpy(tmp, _start, sizeof(T)* len);
				delete[] _start;
			}*/
			// 调用自定义类型的赋值运算符重载，进行深拷贝
			if (_start)
			{
				for (int i = 0; i < len; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			//更新指针
			_start = tmp;
			_finish = _start + len;
			_endOfStorage = _start + n;
		}
	}

	// 插入会导致迭代器失效： 增容， 原有空间被释放，迭代器指向的位置失效
	void Insert(iterator pos, const T& val)
	{
		assert(pos <= _finish && pos >= _start);
		size_t len = pos - _start;
		//检查空间是否足够
		if (_finish == _endOfStorage)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		//增容之后，更新迭代器
		pos = _start + len;
		iterator end = _finish;
		//从后向前挪动元素，腾出pos的空间，存放新的元素val
		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}

		*pos = val;
		_finish++;
	}

	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		iterator begin = pos + 1;
		//从pos+1依次向前挪动元素
		while (begin < _finish)
		{
			// pos + 1 --> pos
			// _finish - 1 --> _finish - 2
			*(begin - 1) = *begin;
			++begin;
		}

		--_finish;

		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			//新增位置赋值
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};