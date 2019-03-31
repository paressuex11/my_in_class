//����һ���������·
//���ô���
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <vector>
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
class Student {
private:
	int number_;//ѧ��
	std::string name_;//����
public:
	Student(int number = 0, const std::string& name = "") {
		this->number_ = number;
		this->name_ = name;
	}
	Student(const Student& stu2) {
		this->number_ = stu2.number_;
		this->name_ = stu2.name_;
	}
	void SetStudent(int number, const std::string& name) {
		this->number_ = number;
		this->name_ = name;
	}
	std::string GetName() const {
		return this->name_;
	}
	int GetNum() const {
		return this->number_;
	}
	void Show() const {
		std::cout << "ID: " <<this->number_ << "  Name: " << this->name_ <<std::endl;
	}
};
class Book {
private:
	std::string title_;
	std::string ISBN_;
	int year_;
public:
	
	Book(const std::string& title = "", const std::string& isbn = "", int year = 0) {
		this->title_ = title;
		this->ISBN_ = isbn;
		this->year_ = year;
	}
	Book(const Book& book2) {
		this->title_ = book2.title_;
		this->ISBN_ = book2.ISBN_;
		this->year_ = book2.year_;
	}
	Book& operator=(const Book& book2) {
		this->title_ = book2.title_;
		this->ISBN_ = book2.ISBN_;
		this->year_ = book2.year_;
		return *this;
	}
	std::string GetTitle() const {
		return this->title_;
	}
	std::string GetISBN() const {
		return this->ISBN_;
	}
	int GetYear() const {
		return this->year_;
	}
	void SetBook(const std::string& title, const std::string& isbn, int year) {
		this->title_ = title;
		this->ISBN_ = isbn;
		this->year_ = year;
	}
	void Show() const {
		std::cout << "title: "<<this->title_ << "  ISBN: " <<this->ISBN_ << "  Publishing_reign: " << this->year_ << std::endl;
	}
};
class Course {
private:
	std::string teacher_name_;  //��ʦ����
	int year_;         //ѧ��
	Book book_;         //�̿���
	static int count_;  //�γ�����
	Student *students_;
	Book *reference_books_;
	int number_of_books;
	int number_of_students;
	void copy(const Course& course2) {
		this->teacher_name_ = course2.teacher_name_;
		this->year_ = course2.year_;
		this->book_ = course2.book_;
		this->number_of_books = course2.number_of_books;
		this->number_of_students = course2.number_of_students;
		this->students_ = new Student[10];
		for (int i = 0; i < this->number_of_students; ++i) {
			this->students_[i] = course2.students_[i];
		}
		this->reference_books_ = new Book[2];
		for (int i = 0; i < this->number_of_books; ++i) {
			this->reference_books_[i] = course2.reference_books_[i];
		}
	}
public:
	Course(const std::string& t_name, int year, const Book& book) {
		this->teacher_name_ = t_name;
		this->year_ = year;
		this->book_ = book;
		this->students_ = new Student[10];
		this->reference_books_ = new Book[2];
		this->reference_books_[0] = book;
		this->number_of_books = 1;
		this->number_of_students = 0;
		Course::count_++;
	}
	Course(const Course& course2) {
		this->copy(course2);
		Course::count_++;
	}
	Course& operator= (const Course& course2) {
		this->copy(course2);
		Course::count_++;
		return *this;
	}
	~Course() {
		delete[] this->reference_books_;
		delete[] this->students_;
	}
	void add_student(const Student& stu) {
		this->students_[this->number_of_students] = stu;
		this->number_of_students++;
	}
	void add_refer_book(const Book& book) {
		this->reference_books_[this->number_of_books] = book;
		this->number_of_books++;
	}

	void Show() const{
		std::cout << "Course:" << this->book_.GetTitle() << "  " << "Teacher:" << this->teacher_name_ << "  " << "ISBN:" << this->book_.GetISBN() << "  " << "Publishing_reign:" << this->book_.GetYear() << "  " << "academic_years:" << this->year_ << std::endl;
	}
	void show_students() const{
		std::cout << "Students:" << std::endl;
		for (int i = 0; i < this->number_of_students; ++i) {
			this->students_[i].Show();
		}
	}
	void show_books() const {
		std::cout << "References_books:" << std::endl;
		for (int i = 0; i < this->number_of_books; ++i) {
			this->reference_books_[i].Show();
		}
	}
	
};
int Course::count_ = 0;
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
class Yinyin {  //c++ ������Ա�Զ�ʵ��4���������������죬Ĭ�Ϲ��죬������������ֵ�����
public:
	int *px;
	int py = 0;
	void read() {
		cout << "aaaaaaaaa";
	}
	Yinyin() {
		//���__init__
		//no return
		//ÿ�����������ù��캯����Ҳֻ�ܵ���һ��
		//�����أ�ֻҪǩ����ͬ���������ʱ���ղ�������ѡ���캯��
		this->px = new int; //���malloc, retunr һ����ַ, new һ�ξ�Ҫ deleteһ�Σ�������ڴ�й¶
		//���⹹�캯�� Ĭ�Ϲ��� �� ��������  ���캯���Ĳ��������Ƕ����Ǳ���Ӧ�������ã���������޵ݹ�
		//Ĭ�Ϲ��� �Լ���д�������Զ��ӣ�д�˾Ͳ���
		//�������� �ñ���Ķ�����Լ���ֵ
			//���ʹ��const ������������������Ҳ�ܿ�����
			//���г�Ա�������ο���
			//Student s1(s2);     Student s1 = s2; ֻ�ǲ�ͬд�� ���ǵ����˿������캯��
			//s1 = s2 �ǵ�����operator = ��ʼ���͸�ֵ�ǲ�ͬ��
			//ͨ�����Լ�д
			//��Ա������ָ���ʱ����Լ�д (���)
			//��������ȡ����ֻ�ܸ��������� const Yinyin& a = b + c
			//
		//���캯������һ�����ܣ���������ת������
			//����ǿ������ת�����磺Student s1; s1 = 12345;
				//s1 = 12345;���� s1 = (Student)12345; �� s1 = Student(12345)һ��
			//c++�Զ��ϳ��˸�ֵ������"="
			

	}
	



	~Yinyin() {
		//��� free �ڴ��ִ�е�����
		//no return
		delete[] this->px; //���free
	}
	bool operator > (Yinyin& y2) {//Ҳ���Է�������������
		return this->py > y2.py;
	}//operator overload

};

void print(int, int);
void print(float, float);
//�������ͻ���Ϊ����ǩ����һ���֣�������ֵ�����Ͳ�����
	//constָ������ò������ܽ��ܷ�const�Ķ���
//������int �� int constǩ����һ���ģ�����int �� int&��ͬ ��const intҲ��ͬ
//���õ�����ʱ����ʵ����ַ����û�������¶���
//���õ�����ֵ��ʱ�򣬷���ֵ��������ֵ
//�����������Զ���������ʱ��������Ӧ��Ŀ������캯��������ֵ������ʱ����
//return s;�������һ�����������sһģһ�������Ҫ����һ�����󣬻��Ƚ��п������죬��s�������Ǹ���������
	//����ֵ�Ż�����Щ��������ʡ�Կ�������Ĺ��̣�ֱ�ӷ���s�����Կ�����������ֻ������������
//�ڴ���䣺��̬�洢������->ջ��(stack)����->����(heap)����
	//ֻ�����������
	//��̬����̬��ȫ�ֱ���������ʱ�ͷ����
	//ջ�������ֲ�������ջ�ϴ���������Ч�ʸߣ��������ޣ�С������������ģ����Ӧ���ں������涨�壩�Ӹߵ�ַ
	//�ѣ���̬�ڴ���䣬�������󣬵���Ҫ�ֶ��ͷţ��ӵ͵�ַ

void replace(string& source, string sub, string that) {
	int pos = source.find(sub);
	source.replace(pos, sub.length(), that);
}
//getline(fstream, string);
//cout ʹ�ã�setw�����ָ����һ������  eg : cout << setw(1) << "12", setw ��<iomanip>Ĭ���Ҷ��� setprecision()���� setiosflag()��ʶ��
//cin.getline()���滻�з�
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


int main() {
	Book book1("C++", "3849720", 2010);
	Course course1("Claudio", 4, book1);
	/*Book book2("Python", "3849721", 2012);
	Course course2("Nicholas", 4, book2);
	Book book3("advanced_mathematics", "3849722", 2016);
	Course course3("Sourav", 4, book3);*/
	
	/*course2.Show();
	course3.Show();*/
	Book book2("C++ Primer Plus", "978-5-115", 2012);
	course1.add_refer_book(book2);
	Student stu1(0, "handx");
	Student stu2(1, "handxx");
	Student stu3(2, "handxxx");
	course1.add_student(stu1);
	course1.add_student(stu2);
	course1.add_student(stu3);
	course1.Show();
	course1.show_books();
	course1.show_students();
	return 0;
}
