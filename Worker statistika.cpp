#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <chrono>
using namespace std;

class Task
{
	string title;
	int cost;
	int NeedHour;
	bool implementation = false;
public:
	Task(string title, int cost, int hours)
	{
		this->title = title;
		this->cost = cost*hours;
		this->NeedHour = hours;
	}
	Task(){}
	int GetCost()
	{
		return cost;
	}
	void OutputTask()
	{
		cout.fill('*');
		cout << setw(24) << '*' << endl;
		cout << setw(21) << "\x1b[35m"+title + "\x1b[0m**" << endl;
		cout << setw(21) <<"\x1b[35mОплата за задание: " << cost << "\x1b[0m*" << endl;
		cout << setw(21) << "\x1b[31mТребуемое время: " << NeedHour << "\x1b[0m **" << endl;
		(implementation == 1) ? cout << "\x1b[35m Статус выполнения: \x1b[0m" << "\x1b[32mВыполнено\x1b[0m" << endl : cout << "\x1b[35mСтатус выполнения: \x1b[0m" << "\x1b[33mВ процессе\x1b[0m"<<endl;
	}
	int perfomance()
	{
		if (NeedHour > 0)
		{ 
			NeedHour -= 1;
			if (NeedHour == 0)
			{
				execution();
				return cost;
			}
		}
		return 0;
	}
	void execution()
	{
		implementation = true;
	}
	bool perfomed()
	{
		if (implementation == true)
			return true;
		else
			return false;
	}
};


class Worker
{
	string name;
	string Databirthday;
	string post;
	string city;
	vector <Task> tasks;
	int salary = 0;
public:
	Worker(string name, string birthday, string post, string city)
	{
		this->name = name;
		this->Databirthday = birthday;
		this->post = post;
		this->city = city;
	}
	void ReceivingTask(Task task)
	{
		tasks.push_back(task);
	}
	void Working()
	{
		for (int i = 0; i < tasks.size(); i++)
		{

			if (!tasks[i].perfomed())
				salary += tasks[i].perfomance();
			else
				continue;
		}
	}
	void ConclusionTasks()
	{
		for (Task task : tasks)
		{
			task.OutputTask();
		}
	}
	void ConclusionWorker()
	{
		cout.fill('-');
		cout << setw(27) << '#' << endl;
		cout << setw(20) <<"\x1b[33mИмя: \x1b[0m" + name  << endl;
		cout << setw(20) << "\x1b[33mДень рождения: \x1b[0m" + Databirthday  << endl;
		cout << setw(20) << "\x1b[33mДолжность: \x1b[0m" + post  << endl;
		cout << setw(20) << "\x1b[33mГород проживания: \x1b[0m" + city  << endl;
		cout << setw(20) << "\x1b[33mЗарплата: \x1b[0m" << salary << endl;
	}
	int GetSalary()
	{
		return salary;
	}
};



int main()
{
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	Worker workers[5] = { Worker("Pavel", "15.04.2002", "director", "Moscow") , Worker("Basil", "20.09.2002", "secretary", "Moscow"),
		Worker("Artem", "17.11.2001", "programmer", "Sankt-Peterburg"), Worker("Nikita", "06.02.2001", "administrator", "Moscow"), Worker("Max", "12.07.2001", "accountant", "Moscow") };

	Task tasks[20] = { Task("programming",rand() % 200 + 50,rand() % 10 + 1),Task("administration",rand() % 200 + 50,rand() % 10 + 1),Task("time planning",rand() % 200 + 50,rand() % 10 + 1),
	Task("room booking",rand() % 200 + 50,rand() % 10 + 1) ,Task("working with data",rand() % 200 + 50,rand() % 10 + 1) ,Task("text translation",rand() % 200 + 50,rand() % 10 + 1) ,
	Task("systems setup",rand() % 200 + 50,rand() % 10 + 1), Task("registration of appeals",rand() % 200 + 50,rand() % 10 + 1),
	Task("process management",rand() % 200 + 50,rand() % 10 + 1) ,Task("visa approval",rand() % 200 + 50,rand() % 10 + 1),
	Task("retail",rand() % 200 + 50,rand() % 10 + 1), Task("retail",rand() % 200 + 50,rand() % 10 + 1),Task("work at the checkout",rand() % 200 + 50,rand() % 10 + 1),
	Task("installation of equipment",rand() % 200 + 50,rand() % 10 + 1), Task("wiring harness",rand() % 200 + 50,rand() % 10 + 1), Task("installation of programs",rand() % 200 + 50,rand() % 10 + 1),
	Task("turnstile setting",rand() % 200 + 50,rand() % 10 + 1), Task("travel for documents",rand() % 200 + 50,rand() % 10 + 1), Task("ordering materials",rand() % 200 + 50,rand() % 10 + 1),
	Task("filling out payment documents",rand() % 200 + 50,rand() % 10 + 1) };
	
	//Finding the most profitable job
	Task MaxCostTask = tasks[0];
	for (int i = 0; i < 20 ; i++)
	{
		if (MaxCostTask.GetCost() < tasks[i].GetCost())
			MaxCostTask = tasks[i];
	}

	//Job distribution
	int count = 0;
	for (int j = 0; j < 5; j++)
	{
		for (int g = 0; g < 4; g++)
		{
			workers[j].ReceivingTask(tasks[count++]);
		}
	}
	//Working day

	for (int hour  = 0; hour<8 ;hour++)
	{
		system("cls");
		for (int employee = 0; employee < 5; employee++)
		{
			workers[employee].Working();
			workers[employee].ConclusionTasks();
		}
		Sleep(1000);

	}
	
	//Employee earnings report

	for (int k = 0; k < 5; k++)
	{
		workers[k].ConclusionWorker();
	}

	MaxCostTask.OutputTask();

	return 0;
}