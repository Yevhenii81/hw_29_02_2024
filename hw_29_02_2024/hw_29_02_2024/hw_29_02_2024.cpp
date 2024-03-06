#include <iostream>
using namespace std;

template<typename T>
class Stack
{
	unsigned int capacity = 10;
	unsigned int size = 0;
	T* array = new T[capacity];
public:
	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	int GetCount() const {
		return size;
	}

	bool IsFull() const
	{
		return false;
	}

	/*void Push(T value) {
		if (size == capacity) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < size; ++i) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
			capacity *= 2;
		}
		array[size++] = value;
	}*/

	void Push(T value)
	{
		if (size == capacity)
		{
			T* temp = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = array[i];
			}
			delete[] array;
			capacity *= 2;
			array = temp;
		}

		array[size++] = value;
	}

	T Pop() {
		if (!IsEmpty()) {
			return array[--size];
		}
		else {
			throw "Stack is empty!";
		}
	}

	~Stack()
	{
		delete[] array;
	}
};

int main()
{
	Stack<int> stack;

	for (int i = 0; i < 1000; ++i) {
		stack.Push(i);
	}


	for (int i = 0; i < 1000; i++) {
		cout << stack.Pop() << "\n";
	}
}