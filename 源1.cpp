//这是一条神奇的天路
//课堂代码
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stack>
using namespace std;
template <class T>
T add(T T1, T T2) {
	return T1 + T2;
}
class A {
public:
	int *a;
	int x;
	int y;
	void aaa(){}
public:
	A(int x = 0, int y = 0) : x(x), y(y) { this->a = new int; }
	
	~A() {
		cout << "I'm died";
	}

	A operator+(A b) {
		A new_one;
		new_one.x = this->x + b.x;
		new_one.y = this->y + b.y;
		return new_one;
	}
};
class node {
public:
	string label;
	string tag;
	node *next;
	node() {
		this->next = 0;
	}
};
class LinkedList
{ 
public:
	node* first_node;

	LinkedList() {
		first_node = 0;
	}
	void add_the_first_data() {
		node* next = new node;
		next = this->first_node;
		this->first_node = next;
	}
	void delete_first_node() {
		node* nodd = this->first_node;
		this->first_node = this->first_node->next;
		delete[] nodd;

	}
	~LinkedList() {
		while (this->first_node != 0) {
			this->delete_first_node();
		}
	}
};
class Matrix5x5 {
public:
	double value[5][5];
	Matrix5x5() {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				this->value[i][j] = 0;
			}
		}
	}
	double get(int x, int y) {
		return this->value[x][y];
	}
	void set(int x, int y, double val) {
		this->value[x][y] = val;
	}

};
class Yinyin {  //c++ 会帮程序员自动实现4个函数：拷贝构造，默认构造，析构函数，赋值运算符
public:
	int *px;
	int py = 0;
	void read() {
		cout << "aaaaaaaaa";
	}
	Yinyin() {
		//类比__init__
		//no return
		//每个对象必须调用构造函数，也只能调用一个
		//可重载，只要签名不同，构造对象时按照参数类型选构造函数
		this->px = new int; //类比malloc, retunr 一个地址, new 一次就要 delete一次，否则会内存泄露
		//特殊构造函数 默认构造 和 拷贝构造  构造函数的参数不能是对象是本身，应该用引用，否则会无限递归
		//默认构造 自己不写编译器自动加，写了就不加
		//拷贝构造 用本类的对象给自己赋值
			//最好使用const 作参数这样匿名对象也能拷贝了
			//所有成员变量依次拷贝
			//Student s1(s2);     Student s1 = s2; 只是不同写法 都是调用了拷贝构造函数
			//s1 = s2 是调用了operator = 初始化和赋值是不同的
			//通常不自己写
			//成员变量有指针的时候得自己写 (深拷贝)
			//匿名对象取引用只能赋给常引用 const Yinyin& a = b + c
			//
		//构造函数的另一个功能：定义类型转换规则
			//进行强制类型转换比如：Student s1; s1 = 12345;
				//s1 = 12345;语句和 s1 = (Student)12345; 和 s1 = Student(12345)一样
			//c++自动合成了赋值操作符"="
			

	}
	



	~Yinyin() {
		//类比 free 内存后执行的内容
		//no return
		delete[] this->px; //类比free
	}
	bool operator > (Yinyin& y2) {//也可以放在类外面声明
		return this->py > y2.py;
	}//operator overload

};

void print(int, int);
void print(float, float);
//参数类型会作为函数签名的一部分，但返回值的类型不属于
//参数，int 和 int const签名是一样的，但是int 和 int&不同 和const int也不同
//引用当参数时，其实传地址，并没有声明新对象
//引用当返回值的时候，返回值可以作左值
//参数类型有自定义类对象的时候会调用相应类的拷贝构造函数，来把值赋给临时变量
//return s;语句会产生一个匿名对象和s一模一样，如果要返回一个对象，会先进行拷贝构造，把s拷贝给那个匿名对象
	//返回值优化：有些编译器会省略拷贝构造的过程，直接返回s，所以拷贝函数尽量只做拷贝的事情
//内存分配：静态存储区分配->栈区(stack)分配->堆区(heap)分配
	//只读区：代码段
	//静态：静态，全局变量，编译时就分配好
	//栈：函数局部变量在栈上创建，分配效率高，容量有限，小心溢出，（大规模数组应放在函数外面定义）从高地址
	//堆：动态内存分配，灵活，容量大，但需要手动释放，从低地址

void replace(string& source, string sub, string that) {
	int pos = source.find(sub);
	source.replace(pos, sub.length(), that);
}
//getline(fstream, string);
//cout 使用：setw运算符指定下一项的域宽  eg : cout << setw(1) << "12", setw 在<iomanip>默认右对齐 setprecision()精度 setiosflag()标识符
//cin.getline()不存换行符
//int main() {
//	A aa;
//	A aaa(aa);
//	cout << aa.a << '\t' << aaa.a;
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;
class Matrix {
private:
	int rows;
	int columns;
	double *values;
public:
	Matrix(int rows, int column, double values[]) {
		this->rows = rows;
		this->columns = column;
		this->values = new double[rows*column];
		if (!(this->values)) return;
		if (!values) {
			for (int i = 0; i < rows * column; ++i) {
				this->values[i] = 0;
			}
			return;
		}
		for (int i = 0; i < rows * column; ++i) {
			this->values[i] = values[i];
		}
	}
	Matrix(int rows, int column) {
		this->rows = rows;
		this->columns = column;
		this->values = new double[rows*column];
		for (int i = 0; i < rows * column; ++i) {
			this->values[i] = 0;
		}
	}
	Matrix(const Matrix& m2) {
		this->columns = m2.columns;
		this->rows = m2.rows;
		this->values = new double[this->rows * this->columns];
		for (int i = 0; i < m2.rows * m2.columns; ++i) {
			this->values[i] = m2.values[i];
		}
	}
	~Matrix() {
		delete[] this->values;
	}
	void print() const {
		for (int i = 0; i < this->rows; ++i) {
			for (int j = 0; j < this->columns; ++j) {
				cout << "    " << this->values[this->columns * i + j];
			}
			cout << endl;
		}

	}//heandm
	Matrix transpose() {
		Matrix temp(this->columns, this->rows);
		for (int i = 0; i < temp.rows; ++i) {
			for (int j = 0; j < temp.columns; ++j) {
				temp.values[i*temp.columns + j] = this->values[j * this->columns + i];
			}
		}
		return temp;
	}
	void printt() {
		cout << rows;
	}
};

Matrix read() {
	int rows;
	int columns;
	double values[1000];
	cin >> rows >> columns;
	for (int i = 0; i < rows * columns; ++i) {
		cin >> values[i];
	}
	Matrix matrix(rows, columns, values);
	return matrix;
}

int main() {
	Matrix matrix(1, 1, NULL); // calls copy constructor 
	matrix.print();
	std::cout << endl;
	matrix.printt();
	system("pause");
}
