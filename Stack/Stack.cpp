#include <iostream>
#define MAXVALUE 20

using namespace std;

template <typename T>
class Stack
{
public:
  T *values;
  int topPoint;
  int size;
  Stack()
  {
    size = MAXVALUE;
    values = new T[size];
    topPoint = -1;
  }
  ~Stack()
  {
    delete[] values;
  }
  void push(T value)
  {
    if(!isFull())
      values[++topPoint] = value;
    else
      cout << "Stack is Full" << endl;
  }
  void pop()
  {
    if(!empty())
      topPoint--;
    else
      cout << "Stack is Empty";
  }
  T top()
  {
    if(!empty())
      return values[topPoint];
    else
      return NULL;
  }
  bool empty()
  {
    return topPoint == -1;
  }
  bool isFull()
  {
    return topPoint+1 == size;
  }
};

template<typename T>
ostream& operator <<(ostream &out, Stack<T> &st)
{
	T *temp = st.values;
	out << "┌───┐" <<endl;
	for(int i=st.topPoint; i>=0; i--){
	    out <<"  "<<temp[i]<< endl;
	}
	out << "└───┘" << endl;
    return out;
}

int main()
{
	Stack<int> st;
	cout << "Stack push" << endl;
	st.push(1);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(3);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(5);
	cout << st <<endl;
	cout << "Stack Top : " <<st.top() << endl << endl;
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