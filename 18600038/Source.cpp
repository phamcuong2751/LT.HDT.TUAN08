#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CAnimals
{
protected:
	string M_Code;
	int M_Speed;
	int M_Equiment;
public:
	void Input();
	void Output();
	virtual float RunTime();
};

void CAnimals::Input()
{
	cout << "Code: ";
	cin >> M_Code;
	cout << "Speed: ";
	cin >> M_Speed;
	cout << "Equiment: ";
	cin >> M_Equiment;
}

void CAnimals::Output()
{
	cout << "Code: " << M_Code << " ";
	cout << "Speed: " << M_Speed << " ";
	cout << "Equiment: " << M_Equiment << "";
	cout << endl;
}

float CAnimals::RunTime()
{
	return 1.0;
}

//------------------------------------CLION-----------------------------------
class CLion :public CAnimals
{
private:
public:
	void Input();
	void Output();
	float RunTime();
};

float CLion::RunTime()
{
	int speed = 0;
	if (M_Equiment == 1)
		speed = M_Speed * 2;
	else
		speed = M_Speed;
	float time = (float)210 / speed;
	return time;
}

//------------------------------------CRabbit-----------------------------------
class CRabbit :public CAnimals
{
private:
public:
	void Input();
	void Output();
	float RunTime();
};

float CRabbit::RunTime()
{
	int speed = 0;
	if (M_Equiment == 1)
		speed = M_Speed + 30;
	else
		speed = M_Speed;
	float time = (float)210 / speed;
	return time;
}
//------------------------------------CTortoise-----------------------------------
class CTortoise :public CAnimals
{
private:
public:
	void Input();
	void Output();
	float RunTime();
};

float CTortoise::RunTime()
{
	int speed = 0;
	if (M_Equiment == 1)
		speed = M_Speed * 5;
	else
		speed = M_Speed;
	float time = (float)135 / speed;
	return time;
}
//------------------------------------CGame-----------------------------------
class CGame
{
private:
	vector<CAnimals*> list_ani;
public:
	void Input();
	void Output();
	void Result();
};

void CGame::Input()
{
	int n = 0;
	cout << "Input amount: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ani = 0;
		cout << "Input amount (1. Lion, 2. Rabbit, 3. Tortoise): ";
		cin >> ani;
		CAnimals* temp = new CAnimals;
		if (ani == 1)
			temp = new CLion;
		if (ani == 2)
			temp = new CRabbit;
		if (ani == 3)
			temp = new CTortoise;
		temp->Input();
		list_ani.push_back(temp);
	}
}

void CGame::Output()
{
	for (int i = 0; i < list_ani.size(); i++)
	{
		list_ani[i]->Output();
	}
}

void CGame::Result()
{
	CAnimals* temp;
	for (int i = 0; i < list_ani.size() - 1; i++)
	{
		for (int j = i + 1; j < list_ani.size(); j++)
		{
			if (list_ani[i]->RunTime() > list_ani[j]->RunTime())
			{
				temp = list_ani[i];
				list_ani[i] = list_ani[j];
				list_ani[j] = temp;
			}
		}
	}
}

int main()
{
	CGame ABC;
	ABC.Input();
	cout << endl;
	ABC.Output();
	cout << endl;
	ABC.Result();
	cout << endl;
	ABC.Output();

	return 0;

}