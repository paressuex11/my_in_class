//����һ���������·
//���ô���
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
