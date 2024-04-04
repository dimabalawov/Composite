#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 *  ������� ��������������, ���������� ������� � ����������� ��������� ��� ������������� �������� �� �������� � ������.
 *  ��������� �������� ������������ ���������� �������������� � ��������� �������.
	������� ���������� �������� �������, ������� ����� �������� �� ����������� � ������� ��������, �������� ����������� �������,
 *  ������ ������� ���������� ����� ����� ������� ����� �������.
 *
 * ���� �� ����� �������� ����������� - �������� �������� �� ������������� �����, �������� �� ��� � �������� ��� ��������� ��������.
 * ��� ���������� ���� ���� ����� Component ������ ������� ��� ����� ������ �������� ������ ��� ������� Composite � Leaf.
 * ������ ����� Component ������������� ��� ���� �������� ���������� �� ���������, � ��������� Composite � Leaf �������� ��.
 *
 * ����������:
 * - ���������� �������� �������, ��������� �� ����������� � ��������� ��������.
 * - �������� ����������� �������.
 * - ��������� ���������� ����� ����� �����������.
 * - ������������ �������� ������ �������
*/

/*
 Component
	- ��������� ��������� ��� ����������� ��������;
	- ������������� ���������� ���������� �������� �� ���������, ����� ��� ���� �������;
	- ��������� ��������� ��� ������� � �������� � ���������� ���;
	- ���������� ��������� ��� ������� � �������� ���������� � ����������� ��������� � ��� ������������� ��������� ���.
 */

class Component abstract
{
protected:
	string name;
	unsigned int price;
public: 
	Component(string name, unsigned int price)
	{
		this->name = name;
		this->price = price;
	}

	virtual  void Add(Component *c) abstract;
	virtual  void Remove(Component *c) abstract;
	virtual  void Display(int depth) abstract;
};

/*
 * Composite
 *  - ���������� ��������� �����������, � ������� ���� �������;
	- ������ ����������-�������;
	- ��������� ����������� � ���������� ��������� �������� � ���������� ������ Component;
*/

class Composite : public Component
{
	vector<Component*> components;
public:
	Composite(string name,unsigned int price):Component(name,price){	}

	void Add(Component * component) override
	{
		components.push_back(component);
	}
	void Remove(Component *component) override
	{
		auto iter = find(components.begin(), components.end(), component);
		components.erase(iter);
	}
	void Display(int depth) override
	{
		string s(depth, '-');
		if (price > 0)
			
			cout << s + name + " Price: " << price << endl;
		else
			cout << s + name << endl;


		for(Component *component : components)
		{
			component->Display(depth + 2);
		}
	}
};
/*
 * Leaf
	- ������������ �������� ���� ���������� � �� ����� ��������;
	- ���������� ��������� ����������� �������� � ����������;
 */
class Leaf : public Component
{
public:
	Leaf(string name, unsigned int price) : Component(name, price) {	}

	void Add(Component *c) override
	{
		cout << "Cannot add to file\n";
	}
	void Remove(Component *c) override
	{
		cout << "Cannot remove from file\n";
	}
	void Display(int depth) override
	{
		string s(depth, '-');
		if (price > 0)

			cout << s + name + " Price: " << price << endl;
		else
			cout << s + name << endl;
	}
};

int main()
{
	// ������ ������������ ��������� ���������� ����� ��������� Component.

	Component *root = new Composite("Building",0);
	Component *reception = new Composite("Reception",0);
	root->Add(reception);

	reception->Add(new Leaf("Warm tones",0));

	Component *coffetable = new Composite("Coffe Table",100);
	reception->Add(coffetable);
	coffetable->Add(new Leaf("10-20 Magazines", 50));

	reception->Add(new Leaf("Sofa", 400));

	Component* secretarytable = new Composite("Secretary Table", 600);
	reception->Add(secretarytable);

	Component* computer = new Composite("Computer", 900);
	secretarytable->Add(computer);
	computer->Add(new Leaf("2TB Hard Drive", 200));

	secretarytable->Add(new Leaf("Office stuff", 150));

	reception->Add(new Leaf("Water cooler", 100));

	Component* auditory1 = new Composite("Auditory 1", 0);
	root->Add(auditory1);
	auditory1->Add(new Leaf("10 tables", 400));
	auditory1->Add(new Leaf("Board", 70));

	Component* desk = new Composite("Teacher's Desk", 0);
	auditory1->Add(desk);
	desk->Add(new Leaf("Computer", 900));

	auditory1->Add(new Leaf("Posters",140));

	
	Component* auditory2 = new Composite("Auditory 2", 0);
	root->Add(auditory2);
	Component* tables = new Composite("20 Tables", 300);
	auditory2->Add(tables);

	tables->Add(new Leaf("Black colour tables", 300));
	tables->Add(new Leaf("Round-placed tables", 150));

	auditory2->Add(new Leaf("Board", 70));
	auditory2->Add(new Leaf("Sofa", 300));

	Component* compauditory = new Composite("Computer Auditory", 0);
	root->Add(compauditory);
	
	Component* tablescomp = new Composite("10 Computer Tables", 600);
	Component* computer2 = new Composite("Computer on every table", 6000);
	Component* board = new Composite("Board", 100);

	compauditory->Add(tablescomp);
	tablescomp->Add(computer2);

	computer2->Add(new Leaf("Proccesor 2.2 Hz", 200));
	computer2->Add(new Leaf("Hard Drive 80GB", 50));
	computer2->Add(new Leaf("RAM 1GB", 10));

	tablescomp->Add(new Leaf("Socket", 20));

	compauditory->Add(board);
	board->Add(new Leaf("Markers", 30));


	Component* dinary = new Composite("Dinary", 0);
	root->Add(dinary);
	Component* dinarytable = new Composite("Table", 50);
	dinary->Add(new Leaf("Coffee machine", 300));
	dinary->Add(dinarytable);
	dinarytable->Add(new Leaf("4 Chairs", 100));

	dinary->Add(new Leaf("Refrigirator", 600));
	dinary->Add(new Leaf("Sink", 200));


	root->Display(0);

	system("pause");
}


