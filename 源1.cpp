//这是一条神奇的天路
//课堂代码
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
class A;

template <class T>
T add(T T1, T T2) {
	return T1 + T2;
}
//写模板类的时候，先写一个普通类的版本,便于调试


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
//class Student {
//private:
//	int number_;//学号
//	std::string name_;//名字
//public:
//	Student(int number = 0, const std::string& name = "") {
//		this->number_ = number;
//		this->name_ = name;
//	}
//	Student(const Student& stu2) {
//		this->number_ = stu2.number_;
//		this->name_ = stu2.name_;
//	}
//	void SetStudent(int number, const std::string& name) {
//		this->number_ = number;
//		this->name_ = name;
//	}
//	std::string GetName() const {
//		return this->name_;
//	}
//	int GetNum() const {
//		return this->number_;
//	}
//	void Show() const {
//		std::cout << "ID: " <<this->number_ << "  Name: " << this->name_ <<std::endl;
//	}
//};
//class Book {
//private:
//	std::string title_;
//	std::string ISBN_;
//	int year_;
//public:
//	
//	Book(const std::string& title = "", const std::string& isbn = "", int year = 0) {
//		this->title_ = title;
//		this->ISBN_ = isbn;
//		this->year_ = year;
//	}
//	Book(const Book& book2) {
//		this->title_ = book2.title_;
//		this->ISBN_ = book2.ISBN_;
//		this->year_ = book2.year_;
//	}
//	Book& operator=(const Book& book2) {
//		this->title_ = book2.title_;
//		this->ISBN_ = book2.ISBN_;
//		this->year_ = book2.year_;
//		return *this;
//	}
//	std::string GetTitle() const {
//		return this->title_;
//	}
//	std::string GetISBN() const {
//		return this->ISBN_;
//	}
//	int GetYear() const {
//		return this->year_;
//	}
//	void SetBook(const std::string& title, const std::string& isbn, int year) {
//		this->title_ = title;
//		this->ISBN_ = isbn;
//		this->year_ = year;
//	}
//	void Show() const {
//		std::cout << "title: "<<this->title_ << "  ISBN: " <<this->ISBN_ << "  Publishing_reign: " << this->year_ << std::endl;
//	}
//};
//class Course {
//private:
//	std::string teacher_name_;  //教师姓名
//	int year_;         //学年
//	Book book_;         //教科书
//	static int count_;  //课程数量
//	Student *students_;
//	Book *reference_books_;
//	int number_of_books;
//	int number_of_students;
//	void copy(const Course& course2) {
//		this->teacher_name_ = course2.teacher_name_;
//		this->year_ = course2.year_;
//		this->book_ = course2.book_;
//		this->number_of_books = course2.number_of_books;
//		this->number_of_students = course2.number_of_students;
//		this->students_ = new Student[10];
//		for (int i = 0; i < this->number_of_students; ++i) {
//			this->students_[i] = course2.students_[i];
//		}
//		this->reference_books_ = new Book[2];
//		for (int i = 0; i < this->number_of_books; ++i) {
//			this->reference_books_[i] = course2.reference_books_[i];
//		}
//	}
//public:
//	Course(const std::string& t_name, int year, const Book& book) {
//		this->teacher_name_ = t_name;
//		this->year_ = year;
//		this->book_ = book;
//		this->students_ = new Student[10];
//		this->reference_books_ = new Book[2];
//		this->reference_books_[0] = book;
//		this->number_of_books = 1;
//		this->number_of_students = 0;
//		Course::count_++;
//	}
//	Course(const Course& course2) {
//		this->copy(course2);
//		Course::count_++;
//	}
//	Course& operator= (const Course& course2) {
//		this->copy(course2);
//		Course::count_++;
//		return *this;
//	}
//	~Course() {
//		delete[] this->reference_books_;
//		delete[] this->students_;
//	}
//	void add_student(const Student& stu) {
//		this->students_[this->number_of_students] = stu;
//		this->number_of_students++;
//	}
//	void add_refer_book(const Book& book) {
//		this->reference_books_[this->number_of_books] = book;
//		this->number_of_books++;
//	}
//
//	void Show() const{
//		std::cout << "Course:" << this->book_.GetTitle() << "  " << "Teacher:" << this->teacher_name_ << "  " << "ISBN:" << this->book_.GetISBN() << "  " << "Publishing_reign:" << this->book_.GetYear() << "  " << "academic_years:" << this->year_ << std::endl;
//	}
//	void show_students() const{
//		std::cout << "Students:" << std::endl;
//		for (int i = 0; i < this->number_of_students; ++i) {
//			this->students_[i].Show();
//		}
//	}
//	void show_books() const {
//		std::cout << "References_books:" << std::endl;
//		for (int i = 0; i < this->number_of_books; ++i) {
//			this->reference_books_[i].Show();
//		}
//	}
//	
//};
//int Course::count_ = 0;
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
	//const指针和引用参数不能接受非const的东西
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

//#include <iostream>
//using namespace std;
//class Matrix {
//private:
//	int rows;
//	int columns;
//	double *values;
//public:
//	Matrix(int rows, int column, double values[]) {
//		this->rows = rows;
//		this->columns = column;
//		this->values = new double[rows*column];
//		if (!(this->values)) return;
//		if (!values) {
//			for (int i = 0; i < rows * column; ++i) {
//				this->values[i] = 0;
//			}
//			return;
//		}
//		for (int i = 0; i < rows * column; ++i) {
//			this->values[i] = values[i];
//		}
//	}
//	Matrix(int rows, int column) {
//		this->rows = rows;
//		this->columns = column;
//		this->values = new double[rows*column];
//		for (int i = 0; i < rows * column; ++i) {
//			this->values[i] = 0;
//		}
//	}
//	Matrix(const Matrix& m2) {
//		this->columns = m2.columns;
//		this->rows = m2.rows;
//		this->values = new double[this->rows * this->columns];
//		for (int i = 0; i < m2.rows * m2.columns; ++i) {
//			this->values[i] = m2.values[i];
//		}
//	}
//	~Matrix() {
//		delete[] this->values;
//	}
//	void print() const {
//		for (int i = 0; i < this->rows; ++i) {
//			for (int j = 0; j < this->columns; ++j) {
//				cout << "    " << this->values[this->columns * i + j];
//			}
//			cout << endl;
//		}
//
//	}//heandm
//	Matrix transpose() {
//		Matrix temp(this->columns, this->rows);
//		for (int i = 0; i < temp.rows; ++i) {
//			for (int j = 0; j < temp.columns; ++j) {
//				temp.values[i*temp.columns + j] = this->values[j * this->columns + i];
//			}
//		}
//		return temp;
//	}
//	void printt() {
//		cout << rows;
//	}
//};
#include <iostream>
using namespace std;
#define maxx(a, b) (a >= b ? a : b)
#define minn(a, b) (a <= b ? a : b)
template <class Type>
class Matrix {
private:
	int rows;
	int columns;
	vector<Type> values;
public:
	Matrix(int rows, int column, const vector<Type>& vec) {
		this->rows = rows;
		this->columns = column;
		this->values = vec;
		
		for (int i = 0; i < rows * column; ++i) {
			this->values[i] = values[i];
		}
	}
	Matrix(int rows, int column) {
		this->rows = rows;
		this->columns = column;
		Type* new_one = new Type[rows*column];
		vector<Type> vec (new_one, new_one + rows * column);
		this->values = vec;
		delete[] new_one;
		for (int i = 0; i < rows * column; ++i) {
			this->values[i] = 0;
		}
	}
	Type& get(int x, int y) {
		return this->values[(x - 1) * this->columns + y - 1];
	}
	Matrix(const Matrix& m2) {
		this->columns = m2.columns;
		this->rows = m2.rows;
		Type* new_one = new Type[m2.columns * m2.rows];
		vector<Type> vec(new_one, new_one + this->rows * this->columns);
		this->values = vec;
		delete[] new_one;
		for (int i = 0; i < m2.rows * m2.columns; ++i) {
			this->values[i] = m2.values[i];
		}
	}
	~Matrix() {
		this->values.clear();
	}
	void print() const {
		for (int i = 0; i < this->rows; ++i) {
			for (int j = 0; j < this->columns; ++j) {
				cout << "    " << this->values[this->columns * i + j];
			}
			cout << endl;
		}

	}
	Matrix concatenateRows(const Matrix & matrix2) const {
		Matrix temp(this->rows + matrix2.rows, this->columns);
		for (int i = 0; i < this->rows * this->columns; ++i) {
			temp.values[i] = this->values[i];
		}
		int j = 0;
		for (int i = this->rows*this->columns; i < temp.columns * temp.rows; ++i, ++j) {
			temp.values[i] = matrix2.values[j];
		}
		return temp;
	}
	Matrix concatenateColumns(const Matrix & matrix2) const {
		Matrix temp(this->rows, this->columns + matrix2.columns);
		for (int i = 0; i < this->rows; ++i) {
			for (int j = 0; j < this->columns; ++j) {
				temp.values[i *temp.columns + j] = this->values[i * this->columns + j];
			}
		}

		for (int i = 0; i < this->rows; ++i) {
			int k = 0;
			for (int j = this->columns; j < temp.columns; ++j, ++k) {
				temp.values[i *temp.columns + j] = matrix2.values[i*this->columns + k];
			}
		}
		return temp;
	}
	Matrix getRow(int row) const {
		Matrix temp(1, this->columns);
		for (int i = 0; i < this->columns; ++i) {
			temp.values[i] = this->values[(row - 1) * this->columns + i];
		}
		return temp;
	}

	Matrix getColumn(int column) const {
		Matrix temp(this->rows, 1);
		for (int i = 0; i < this->rows; ++i) {
			temp.values[i] = this->values[i * this->columns + column - 1];
		}
		return temp;
	}
	Matrix transpose() const {
		Matrix temp(this->columns, this->rows);
		for (int i = 0; i < temp.rows; ++i) {
			for (int j = 0; j < temp.columns; ++j) {
				temp.values[i*temp.columns + j] = this->values[j * this->columns + i];
			}
		}
		return temp;
	}
	Matrix operator *(Type value) const {
		Matrix temp(this->rows, this->columns, this->values);
		for (int i = 0; i < temp.columns * temp.rows; ++i) {
			temp.values[i] *= value;
		}
		return temp;
	}
	Matrix operator +(Type value) const {
		Matrix temp(this->rows, this->columns, this->values);
		for (int i = 0; i < temp.columns * temp.rows; ++i) {
			temp.values[i] += value;
		}
		return temp;
	}
	Matrix operator +(const Matrix& matrix2) const {
		Matrix temp(this->rows, this->columns, this->values);
		for (int i = 0; i < temp.columns * temp.rows; ++i) {
			temp.values[i] += matrix2.values[i];
		}
		return temp;
	}
	Matrix operator -(Type value) const {
		Matrix temp(this->rows, this->columns, this->values);
		for (int i = 0; i < temp.columns * temp.rows; ++i) {
			temp.values[i] -= value;
		}
		return temp;
	}
	Matrix operator -(const Matrix& matrix2) const {
		Matrix temp(this->rows, this->columns, this->values);
		for (int i = 0; i < temp.columns * temp.rows; ++i) {
			temp.values[i] -= matrix2.values[i];
		}
		return temp;
	}
	Matrix operator * (const Matrix & matrix2) const {
		Matrix temp(this->rows, matrix2.columns);
		for (int i = 0; i < temp.rows; ++i) {
			for (int j = 0; j < temp.columns; ++j) {
				for (int k = 0; k < this->columns; ++k) {
					temp.values[i * temp.columns + j] += this->values[i * this->columns + k] * matrix2.values[k * matrix2.columns + j];
				}
			}
		}
		return temp;
	}
	Matrix reshape(int rows, int columns) const {
		Matrix temp(rows, columns);
		Type* values = new Type[this->rows * this->columns];
		int k = 0;
		for (int j = 0; j < this->columns; ++j) {
			for (int i = 0; i < this->rows; ++i, ++k) {
				values[k] = this->values[i * this->columns + j];
			}
		}
		k = 0;
		for (int j = 0; j < temp.columns; ++j) {
			for (int i = 0; i < temp.rows; ++i, ++k) {
				temp.values[i * temp.columns + j] = values[k];
			}
		}
		return temp;
	}
	bool whether_vector() const {
		if (this->rows == 1 || this->columns == 1) {
			return true;
		}
		else return false;
	}
	Matrix max() const {
		if (this->whether_vector()) {
			Type maxxx = this->values[0];
			for (int i = 1; i < maxx(this->rows, this->columns); ++i) {
				if (this->values[i] > maxxx) maxxx = this->values[i];
			}
			Matrix temp(1, 1);
			temp.values[0] = maxxx;
			return temp;
		}
		else {
			Matrix temp(1, this->columns);
			for (int j = 0; j < this->columns; ++j) {
				temp.values[j] = this->values[j];
				for (int i = 0; i < this->rows; ++i) {
					if (this->values[i*this->columns + j] > temp.values[j]) temp.values[j] = this->values[i * this->columns + j];
				}
			}

			return temp;
		}

	}
	Matrix min() const {
		if (this->whether_vector()) {
			Type minnn = this->values[0];
			for (int i = 1; i < maxx(this->rows, this->columns); ++i) {
				if (this->values[i] < minnn) minnn = this->values[i];
			}
			Matrix temp(1, 1);
			temp.values[0] = minnn;
			return temp;
		}
		else {
			Matrix temp(1, this->columns);
			for (int j = 0; j < this->columns; ++j) {
				temp.values[j] = this->values[j];
				for (int i = 0; i < this->rows; ++i) {
					if (this->values[i*this->columns + j] < temp.values[j]) temp.values[j] = this->values[i * this->columns + j];
				}
			}

			return temp;
		}
	}
	Matrix sum()const {
		if (this->whether_vector()) {
			Type sum = this->values[0];
			for (int i = 1; i < maxx(this->rows, this->columns); ++i) {
				sum += this->values[i];
			}
			Matrix temp(1, 1);
			temp.values[0] = sum;
			return temp;
		}
		else {
			Matrix temp(1, this->columns);
			for (int j = 0; j < this->columns; ++j) {
				for (int i = 0; i < this->rows; ++i) {
					temp.values[j] += this->values[i * this->columns + j];
				}
			}
			return temp;
		}
	}
};

//int main() {
//	Book book1("C++", "3849720", 2010);
//	Course course1("Claudio", 4, book1);
//	/*Book book2("Python", "3849721", 2012);
//	Course course2("Nicholas", 4, book2);
//	Book book3("advanced_mathematics", "3849722", 2016);
//	Course course3("Sourav", 4, book3);*/
//	
//	/*course2.Show();
//	course3.Show();*/
//	Book book2("C++ Primer Plus", "978-5-115", 2012);
//	course1.add_refer_book(book2);
//	Student stu1(0, "handx");
//	Student stu2(1, "handxx");
//	Student stu3(2, "handxxx");
//	course1.add_student(stu1);
//	course1.add_student(stu2);
//	course1.add_student(stu3);
//	course1.Show();
//	course1.show_books();
//	course1.show_students();
//	return 0;
//}
//int main() {
//	cout << "constructor 1" << endl;
//	Matrix<double> matrix1(3, 3);
//	matrix1.print();
//
//	const double values1[] = {
//		1, 2, 3,
//		4, 5, 6,
//		7, 8, 9,
//	};
//	vector<double> values2;
//	for (int i = 0; i < 9; ++i) {
//		values2.push_back(values1[i]);
//	}
//
//	cout << "constructor 2" << endl;
//	Matrix<double> matrix2(3, 3, values2);
//	matrix2.print();
//
//	cout << "copy constructor" << endl;
//	Matrix<double> matrix3 = matrix2;
//	matrix3.print();
//
//	cout << "operator =" << endl;
//	matrix3.get(1, 1) = 10.0;
//	matrix3 = matrix2;
//	matrix3.print();
//
//	cout << "getColumn" << endl;
//	matrix2.getColumn(2).print();
//	cout << "getRow" << endl;
//	matrix2.getRow(2).print();
//
//	cout << "concatenateRows" << endl;
//	matrix1.concatenateRows(matrix2).print();
//	cout << "concatenateColumns" << endl;
//	matrix1.concatenateColumns(matrix2).print();
//
//	cout << "reshape" << endl;
//	matrix1.concatenateColumns(matrix2).
//		reshape(6, 3).print();
//
//	cout << "transpose" << endl;
//	matrix2.transpose().print();
//
//	cout << "operator +" << endl;
//	(matrix2 + matrix2).print();
//	cout << "operator +" << endl;
//	(matrix2 + 10).print();
//	cout << "operator -" << endl;
//	(matrix2.transpose() - matrix2).print();
//	cout << "operator -" << endl;
//	(matrix2 - 10).print();
//
//	cout << "operator *" << endl;
//	(matrix2.transpose() * matrix2).print();
//	cout << "operator *" << endl;
//	(matrix2 * 2).print();
//
//	cout << "max" << endl;
//	cout << matrix2.max().max().get(1, 1) << endl;
//	cout << "min" << endl;
//	cout << matrix2.min().min().get(1, 1) << endl;
//	cout << "sum" << endl;
//	cout << matrix2.sum().sum().get(1, 1) << endl;
//	system("pause");
//}
//int a = 0;
//int main() {
//	
//	cout << "wohaoshuai";
//
//	system("pause");
//	return 0;
//}
//

//contacts
//class Student {
//private:
//	string name;
//protected:
//	string nickname;
//public:
//	string phone_number;
//	friend ostream& operator<<(ostream&, const Student& stu);
//public:
//	Student(const string& name = "", const string& nickname = "", const string& phone_number = "") {
//		this->name = name;
//		this->nickname = nickname;
//		this->phone_number = phone_number;
//	}
//};
//ostream& operator<<(ostream& out, const Student& stu) {
//	out << stu.name << endl;
//	out << stu.nickname << endl;
//	out << stu.phone_number << endl;
//	return out;
//}
//
//class Stu : public Student {
//	void print() {
//		
//	}
//};
//
//int main() {
//	Student();
//	
//	system("pause");
//	return 0;
//}

//多态只会发生在指针和引用里 down-casting：父类的指针可以接受子类的地址，在函数中也是这样
//多态只会发生在指针和引用里 down-casting：父类的指针可以接受子类的地址，在函数中也是这样
//指针指向的函数如果不是虚函数会调用基类的函数，如果是虚函数会检测指向对象的类型来调用子类的函数
//也可以用类名+ :: 来限定调用的函数是谁，为了多态还是别这样...
//继承以后子类的同名虚函数不用加virtual关键字，编译器自动加
//函数的动态匹配: 主要是因为虚函数以及继承的原因无法在编译时确定函数是谁，virtual关键字相当于函数动态匹配的开关



#include <vector>
#include <string>
using namespace std;


int main() {
	system("python C:/Users/11385/Desktop/Lisaru.py");
	cout << "helloworld";
	system("pause");
}
