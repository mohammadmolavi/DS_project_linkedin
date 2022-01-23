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

vector <UsersInfo> list1;
map <int, string > idToName;
map <string, int> nameToId;
map <int, vector<string>> idToSpecialties;
map <string, vector<int>> specialtiesToId;
map <int, string> idToUniversity;
map <int, string> idToField;
map <int, string> idToWorkplace;
graph connected;
vector <int> fiveDegree;
int iddd;

void saveInfo()
{
	ifstream users("users.json");
	Json::Value v;
	Json::Reader r;
	r.parse(users, v);
	for (int i = 0; !v[i].isNull(); i++)
	{
		UsersInfo newUser;
		Json::FastWriter fastWriter;
		string s = fastWriter.write(v[i]["name"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.name = s;
		s = fastWriter.write(v[i]["id"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.id = stoi(s);
		s = fastWriter.write(v[i]["dateOfBirth"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.dateOfBirth = s;
		s = fastWriter.write(v[i]["universityLocation"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.universityLocation = s;
		s = fastWriter.write(v[i]["field"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.field = s;
		s = fastWriter.write(v[i]["workplace"]);
		s.erase(s.begin());
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		newUser.workplace = s;
		for (int j = 0; !v[i]["specialties"][j].isNull(); j++)
		{
			s = fastWriter.write(v[i]["specialties"][j]);
			s.erase(s.begin());
			s.erase(s.end() - 1);
			s.erase(s.end() - 1);
			newUser.specialties.push_back(s);
		}
		for (int j = 0; !v[i]["connectionId"][j].isNull(); j++)
		{
			s = fastWriter.write(v[i]["connectionId"][j]);
			s.erase(s.begin());
			s.erase(s.end() - 1);
			s.erase(s.end() - 1);
			newUser.connectioId.push_back(stoi(s));
		}
		list1.push_back(newUser);
	}
}

void saveToMap()
{
	for (int i = 0; i < list1.size(); i++)
	{
		idToName[list1[i].id] = list1[i].name;
		nameToId[list1[i].name] = list1[i].id;
		idToSpecialties[list1[i].id] = list1[i].specialties;
		for (int j = 0; j < list1[i].specialties.size(); j++)
			specialtiesToId[list1[i].specialties[j]].push_back(list1[i].id);
		idToUniversity[list1[i].id] = list1[i].universityLocation;
		idToField[list1[i].id] = list1[i].field;
		idToWorkplace[list1[i].id] = list1[i].workplace;
	}
}

void saveToGraph()
{
	for (int i = 0; i < list1.size(); i++)
	{
		connected.insertV(list1[i].id);
	}
	for (int i = 0; i < list1.size(); i++)
	{
		for (int j = 0; j < list1[i].connectioId.size(); j++)
		{
			connected.connect(list1[i].id, list1[i].connectioId[j]);
		}
	}
}


void save5Degree(int id, int count)
{
	vector <int> connectedUsers = connected.getConnectedV(id);
	for (int i = 0; i < connectedUsers.size(); i++)
	{
		bool flag = false;
		if (connected.isConnect(connectedUsers[i], iddd) || connectedUsers[i] == iddd)
			flag = true;
		for (int j = 0; j < fiveDegree.size() && !flag; j++)
			if (fiveDegree[j] == connectedUsers[i])
				flag = true;
		if (!flag)
			fiveDegree.push_back(connectedUsers[i]);
		if (!flag && count < 5)
			save5Degree(connectedUsers[i], count + 1);
	}
}

bool cmp(pair<int, int>& a,
	pair<int, int>& b)
{
	return a.second > b.second;
}

void printSortMap(map<int, int>& M)
{

	vector<pair<int, int> > A;
	for (auto& it : M) {
		A.push_back(it);
	}
	sort(A.begin(), A.end(), cmp);
	int count = 0;
	for (auto& it : A)
	{
		if (count == 20)
			break;
		cout << "id: " << it.first
			<< "\tname: " << idToName[it.first]
			<< "\tpoint: " << it.second << endl;
		count++;
	}
}

void printRecommended(int id)
{
	int index = id;
	for (int i = 0; i < list1.size(); i++)
		if (list1[i].id == id)
			index = i;
	vector <int> connectedUsers = connected.getConnectedV(id);
	for (int i = 0; i < connectedUsers.size(); i++)
	{
		save5Degree(connectedUsers[i], 1);
	}
	vector <string> specilties = list1[index].specialties;
	string workplace = list1[index].workplace;
	string field = list1[index].field;
	string university = list1[index].universityLocation;
	map <int, int> priority;
	for (int i = 0; i < fiveDegree.size(); i++)
	{
		for (int j = 0; j < specilties.size(); j++)
			for (int k = 0; k < idToSpecialties[fiveDegree[i]].size(); k++)
				if (specilties[j].compare(idToSpecialties[fiveDegree[i]][k]) == 0)
					priority[fiveDegree[i]] += 8;
		if (idToField[fiveDegree[i]].compare(field) == 0)
			priority[fiveDegree[i]] += 10;
		if (idToWorkplace[fiveDegree[i]].compare(workplace) == 0)
			priority[fiveDegree[i]] += 10;
		if (idToUniversity[fiveDegree[i]].compare(university) == 0)
			priority[fiveDegree[i]] += 5;
	}
	printSortMap(priority);
}

int main()
{
	saveInfo();
	saveToMap();
	saveToGraph();
	int id;
	cout << "Enter id : ";
	cin >> id;
	iddd = id;
	printRecommended(id);
}