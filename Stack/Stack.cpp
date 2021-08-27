#include <iostream>

using namespace std;

template <typename T>
class Stack // "Stack" that stacks T
{
public:
  T* values;
  int topIndex;
  int maxSize;
  Stack(const int size)
  {
    maxSize = size;
    values = new T[size];
    topIndex = -1;
  }
  ~Stack()
  {
    delete[] values;
  }
  void push(const T& value)
  {
    if(!isFull())
      values[++topIndex] = value;
    else
      cout << "Stack is Full" << endl;
  }
  void pop()
  {
    if(!empty())
      topIndex--;
    else
      cout << "Stack is Empty";
  }
  T top() const
  {
    if(!empty())
      return values[topIndex];
    else
      return NULL;
  }
  bool empty() const
  {
    return topIndex == -1;
  }
  bool isFull() const
  {
    return topIndex + 1 == maxSize;
  }
};

template<typename T>
ostream& operator <<(ostream &out, Stack<T> &st)
{
	T *temp = st.values;
	out << "┌───┐" <<endl;
	for(int i=st.topIndex; i >= 0; i--){
	    out <<"  "<<temp[i]<< endl;
	}
	out << "└───┘" << endl;
    return out;
}

int main()
{
	Stack<int> st(10);
	cout << "Stack push" << endl;
	st.push(1);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(3);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(5);
	cout << st <<endl;
	cout << "Stack Top : " << st.top() << endl << endl;
	cout << "Stack pop" << endl;
	st.pop();
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
}