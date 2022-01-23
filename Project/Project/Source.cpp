#include <json/json.h>
#include <bits/stdc++.h>
using namespace std;

struct UsersInfo
{
	int id;
	string name;
	vector<int> connectioId;
	string dateOfBirth;
	string universityLocation;
	string field;
	string workplace;
	vector <string> specialties;
};

class graph
{
private:
	vector <int> vertieses;
	map<int, vector<int>> edges;
public:
	void insertV(int V)
	{
		vertieses.push_back(V);
	}
	void connect(int V1, int V2)
	{
		bool flag1 = false;
		bool flag2 = false;
		for (int i = 0; i < vertieses.size(); i++)
		{
			if (vertieses[i] == V1)
				flag1 = true;
			if (vertieses[i] == V2)
				flag2 = true;
		}
		if (flag1 && flag2)
			edges[V1].push_back(V2);
		else
			return;
	}
	bool isConnect(int V1, int V2)
	{
		if (edges[V1].empty())
			return false;
		for (int i = 0; i < edges[V1].size(); i++)
		{
			if (edges[V1][i] == V2)
			{
				return true;
			}
		}
		return false;
	}
	vector<int> getConnectedV(int V) { return edges[V]; }
};

int main()
{

}