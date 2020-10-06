// Bank.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
class Component {
public:
	virtual ~Component() {

	}
	virtual void work() = 0;
	void SetParent(Component* _parent) {
		parent = _parent;
	}
protected:
	std::string name;
	Component* parent;
};
class Composite :public Component {
public:
	void AddWorker(Component* worker) {
		workers.push_back(worker);
	}
protected:
	std::vector<Component*>workers;
};
class ManaginDir :public Composite {
public:
	void DrinkCoffie() {
		std::cout << "Drink coffie" << std::endl;
	}
	void work() {
		for (auto x : workers)
			x->work();
		DrinkCoffie();
	}
};
class SeniorVP :public Composite {
public:
	void PrepareMeeting() {
		std::cout << "Prepare Meeting" << std::endl;
	}
	void work() {
		for (auto x : workers)
			x->work();
		PrepareMeeting();
	}
};
class VP :public Composite {
public:
	void PreparePitchBook() {
		std::cout << "PreparePitchBook" << std::endl;
	}
	void work() {
		for (auto x : workers)
			x->work();
		PreparePitchBook();
	}
};
class BankingAssociate :public Composite {
public:
	void GatherCompaniesIndicators() {
		std::cout << "GatherCompaniesIndicators" << std::endl;
	}
	void PutCompanyIndicator() {
		std::cout << "PutCompanyIndicator" << std::endl;
	}
	void work() {
		for (auto x : workers)
			x->work();
		GatherCompaniesIndicators();
		PutCompanyIndicator();
	}
};
class BankingAnalyst :public Component {
	void MakePresentation()
	{
		std::cout << "MakePresentation" << std::endl;
	}
	void GetCompanyIndicator()
	{
		std::cout << "GetCompanyIndicator" << std::endl;
	}
	void work() {
		MakePresentation();
		GetCompanyIndicator();
	}
};
void dfs(Component*ptr, int depth = 0) {
	if (depth == 4)return;
	for (size_t i = 0; i < 2; i++)
	{
		Component* new_child;
		if (depth == 0)new_child = new SeniorVP;
		if (depth == 1)new_child = new VP;
		if (depth == 2)new_child = new BankingAssociate;
		if (depth == 3)new_child = new BankingAnalyst;
		dynamic_cast<Composite*>(ptr)->AddWorker(new_child);
		dfs(new_child, depth + 1);
	}
}
int main()
{
	ManaginDir* dirptr = new ManaginDir;
	dfs(dirptr);
	return 0;
}