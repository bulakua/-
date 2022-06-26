# -
#include<Python.h>
#include <stdlib.h>
#include <cstdio>
#include<iostream>
#include <fstream>
#include<iomanip>
#include <string> 
#include <algorithm>
#include <cmath>
#include <deque>	
#include <vector>		
#include <queue>		
#include <cstring>      
#include <map>		
#include <stack>	
#include <set>
using namespace std;

#define MaxLen 30 
const int IntMax = 0x3f3f3f3f;
const int IntMin = 0x80000000;

struct Node//点的信息 
{
	int num;//编号 
	string name;//地名 
};
struct ENode
{
	Node V1, V2;//边的起点和终点 
	int weight;//边的权值 
};
string name[30] = { " ","stadium","lecturehall","auditorium",
					"library","laboratory","teachingbuilding",
					"octagon","officebuilding","firstdininghall",
					"tunnel","seconddininghall","clinicbuilding",
					"youkangmarket","gogonewworld","dorm" };//每个地点的编号 从1开始 

string List_use[30] = { " ","STA","LEC","AUD","LIB","LAB",
	  "TEA","OCT","OFF",
	  "FIR","TUN","SEC","CLI",
	  "YOU","GOG","DOR" };

class Map
{
	private:
		int vNum;//顶点数 
		int eNum;//边数 
		ENode adj[MaxLen][MaxLen];//邻接矩阵 
	public:
		Map();
		void CreateMap();//地图的构建 
		void ModifyMap();//地图的修改 
		//void DeleteMap();//地图的删除 
		void PrintAdjMatrix();//输出地图的邻接矩阵 
		void PrintAdjList();//输出地图的邻接表
		void DFS_Min();
		void DFS_Floyd();
		void DFS_ALL(int v);
		void Minimumpoints();
		void ShortestPath_Dijkstra();
		void AdjacentNodes();
		int find_node(string fname);
};

Map::Map()//初始化 
{
	vNum = 0;
	eNum = 0;
}

void Map::CreateMap()
{
	ifstream vNumtext;//读取顶点数和边数的文件 
	vNumtext.open("D:/Practice Week/vNumtext.txt", ios::in);
	if (!vNumtext.is_open())
		cout << "vNumtext Document Open Failed!!!" << endl;
	int a = 0;
	vNumtext >> vNum >> eNum;
	a = vNum;
	for (int i = 0; i <= a; i++)//初始化矩阵 
		for (int j = 0; j <= a; j++)
		{
			adj[i][j].weight = 0;
		}
	vNumtext.close();
	ifstream main;//读取地图信息文件 
	main.open("D:/Practice Week/main.txt", ios::in);
	if (!main.is_open())
		cout << "The Information Document Of Map Open Failed!!!" << endl;
	ENode E;
	if (eNum != 0)//如果存在边 
	{
		for (int i = 0; i < eNum; i++)
		{
			while (!main.eof())
			{
				main >> E.V1.num >> E.V2.num >> E.V1.name >> E.V2.name >> E.weight;
				adj[E.V1.num][E.V2.num].weight = E.weight;//给两个地点之间的距离赋值 
				adj[E.V2.num][E.V1.num].weight = E.weight;
			}
		}
	}
	main.close();
}

int floyda[50][50];//原先100*100，怕数组爆了于是改成50*50
bool vimin[50];
int ans[50];
int u = 1;

void Map::DFS_Floyd()
{
	for (int i = 1; i <= vNum; i++)
		for (int j = 1; j <= vNum; j++)
			floyda[i][j] = floyda[j][i] = adj[i][j].weight;
	for (int k = 1; k <= vNum; k++)
		for (int i = 1; i <= vNum; i++)
			for (int j = 1; j <= vNum; j++)
				floyda[i][j] = min(floyda[i][k] + floyda[k][j], floyda[i][j]);
}

void Map::DFS_ALL(int v)
{
	ans[u] = v;
	vimin[v] = 1;
	for (int w = 1; w <= vNum; w++)
		if (adj[v][w].weight != IntMax && (!vimin[w]))
		{
			u++;
			Map::DFS_ALL(w);
		}
}

void Map::DFS_Min()
{
	int vv=0;
	vimin[14] = 1;
	DFS_Floyd();

	ifstream fIn("D:/Practice Week/FDfsFind.txt");
	ofstream fOut("D:/Practice Week/FDfsFindans.txt");
	string str;
	string vname;
	while (fIn.peek() != EOF)
	{
		getline(fIn, vname);
	}
	for (int i = 1; i <= vNum; i++)
	{
		if (vname == name[i])
			vv = i;
	}

	DFS_ALL(vv);
	fOut << name[ans[1]];
	fOut.close();
	//--------------------------------------------------------
	int v, w, k;
	ENode adj222[MaxLen][MaxLen];
	for (v = 1; v <= vNum; v++)
		for (w = 1; w <= vNum; w++)
			adj222[v][w] = adj[v][w];
	string begin, end;
	int D[51][51];
	int P[51][51];
	for (v = 1; v <= vNum; v++)
	{
		for (w = 1; w <= vNum; w++)
		{
			D[v][w] = adj222[v][w].weight;
			P[v][w] = w;
		}
	}

	for (k = 1; k <= vNum; k++)
	{
		for (v = 1; v <= vNum; v++)
		{
			for (w = 1; w <= vNum; w++)
			{
				if (D[v][w] > D[v][k] + D[k][w])
				{
					D[v][w] = D[v][k] + D[k][w];
					P[v][w] = P[v][k];
				}
			}
		}
	}
	ans[vNum] = ans[1];
	ofstream ofs;
	ofs.open("D:/Practice Week/fDfsFindans.txt", ios::app);
	for (k = 1; k < vNum; k++)
	{
		int i, j;
		begin = name[ans[k]]; end = name[ans[k + 1]];
		for (i = 1; i <= vNum; i++)
		{
			if (!(begin.compare(name[i])))
				break;
		}
		for (j = 1; j <= vNum; j++)
		{
			if (!(end.compare(name[j])))
				break;
		}
		int d = P[i][j];
		while (d != j)
		{
			ofs << '%' << name[d];
			d = P[d][j];
		}
		ofs << '%' << name[j];
	}
	//	for(int i=2;i<=vNum;i++)
	//		fOut<<'%'<<name[ans[i]];
	int allsum = 0;
	for (int i = 1; i < vNum; i++) {
		//cout << ans[i] << endl<<"&"<<endl;
		allsum += floyda[ans[i]][ans[i + 1]];
	}
	ofs << '#' << allsum;
	/*
	for (int i = 1; i <= vNum; i++) {
		for (int j = 1; j <= vNum; j++) {
			cout << floyda[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	ofs.close();
}

void Map::ModifyMap() {
	fstream fs;
	fs.open("D:/Practice Week/Modify.txt", ios::in);
	string Modify;
	if (fs.is_open())
	{
		string line;
		while (getline(fs, line))
		{
			Modify = line;
		}
		fs.close();
	}
	else {
		cout << "Function_Choose.txt get failed!" << endl;
	}
	int len = Modify.size();
	int Modify_aspect = 1;
	string start, destination, distance;
	for (int i = 0; i < len; i++) {
		if (Modify_aspect == 1 && Modify[i] != '%')start += Modify[i];
		if (Modify_aspect == 1 && Modify[i] == '%') {
			Modify_aspect += 1;
			continue;
		}
		if (Modify_aspect == 2 && Modify[i] != '%')destination += Modify[i];
		if (Modify_aspect == 2 && Modify[i] == '%')Modify_aspect += 1;
		if (Modify_aspect == 3 && Modify[i] != '%')distance += Modify[i];
	}
	int final_distance = 0, jinzhi = 1;
	for (int j = distance.size() - 1; j > -1; j--) {
		final_distance += (int(distance[j]) - 48) * jinzhi;
		jinzhi *= 10;
	}
	for (int i = 1; i <= vNum; i++) {
		for (int j = 1; j <= vNum; j++) {
			if (name[i] == start && name[j] == destination) {
				adj[i][j].weight = final_distance;
				adj[j][i].weight = final_distance;
				cout << "Modify successfully!!!" << endl;
				break;
			}
		}
	}

}

void Map::PrintAdjMatrix()//输出地图的邻接矩阵
{
	ofstream Matrix("D:/Practice Week/Matrix.txt", ios::out);
	if (Matrix.is_open()) {
		cout << "Matrix open successfully!!!" << endl;
	}
	/*
	cout << setw(8) << "\t" << "    ";
	for (int k = 1; k <= vNum; k++)
		cout << name[k] << "  ";
	cout << endl;
	*/
	for (int i = 1; i <= vNum; i++)
	{
		//cout << setw(8) << name[i] << setw(10);
		//Matrix << "\n";
		for (int j = 1; j <= vNum; j++)
		{
			//Matrix << "    "<<adj[i][j].weight << "    ";
			Matrix << adj[i][j].weight << "%";
			//cout << adj[i][j].weight << "\t" << "   ";
		}
		Matrix << "\n";
		//cout << endl;
	}
	Matrix.close();
	PyObject* PModule_func_five = PyImport_ImportModule("Button_1");// 导入模块
	if (!PModule_func_five) {// 检验是否导入成功
		cout << "Button_1 get moudle failed" << endl;
		//return 0;
	}
	else cout << "Button_1 get moudle succeed" << endl;

}

void Map::PrintAdjList()//输出地图的邻接表 
{
	ofstream List("D:/Practice Week/List.txt", ios::out);
	if (List.is_open()) {
		cout << "List open successfully!!!" << endl;
	}

	for (int i = 1; i <= vNum; i++)
	{
		//		cout<<setw(8)<<i<<"  "<<name[i]<<setw(6);
		List << i<<"%"<<List_use[i] << "%";
		for (int j = 1; j <= vNum; j++)
		{
			if (adj[i][j].weight != 0)
				//			cout<<j<<" ";
				List << j << "%";
		}
		//		cout<<endl;
		List << "^"<<"\n";
	}
	List.close();
	PyObject* PModule_func_five = PyImport_ImportModule("Button_2");// 导入模块
	if (!PModule_func_five) {// 检验是否导入成功
		cout << "Button_2 get moudle failed" << endl;
		//return 0;
	}
	else cout << "Button_2 get moudle succeed" << endl;
}

void Map::AdjacentNodes() {
	int flag1 = -1, flag2 = 0, min;
	string node, closetnode;
	ifstream inFile;
	inFile.open("D:/Practice Week/ANode.txt",ios::in);
	if (!inFile.is_open())
		cout << "ANode文件打开失败" << endl;
	ofstream outFile;
	outFile.open("D:/Practice Week/AdjacentNodes.txt", ios::out);
	if (!outFile.is_open())
		cout << "AdjacentNodes文件打开失败" << endl;
	inFile >> node;
	for (int k = 1; k <= vNum; k++) {
		if (node == name[k]) flag1 = k;
	}
	if (flag1 == -1) cout << "图中不存在该地址" << endl;
	else {
		for (int l = 1; l <= vNum; l++) {
			if (adj[flag1][l].weight != IntMax && flag2 == 1) {
				outFile << "%" << name[l];
				if (adj[flag1][l].weight < min) {
					min = adj[flag1][l].weight;
					closetnode = name[l];
				}
			}
			if (adj[flag1][l].weight != IntMax && flag2 == 0) {
				outFile << name[l];
				flag2 = 1;
				min = adj[flag1][l].weight;
				closetnode = name[l];
			}
		}
		if (flag2 != 0) outFile << "#" << closetnode;
		inFile.close();
		outFile.close();
	}
}

/*
void Map::DFS()
{
	bool* visited;//visit数组 
	visited = new bool[vNum];
	visited[vNum] = { 0 };
	int distance = 0;//所用路程 
	cout << "请输入你的起始地：";
	string place;//地点 
	cin >> place;
	int placenum;//地点的编号 
	for (int i = 1; i <= vNum; i++)
	{
		if (place == name[i])
		{
			placenum = i;
			visited[i] = true;
			break;
		}
		else
			cout << "你输入的地点不存在";
	}

}
*/

ENode adj222[MaxLen][MaxLen];

void Map::Minimumpoints()//某点到另一点经过的点的个数最少
{
	ifstream vNumtext;//读取顶点数和边数的文件 
	vNumtext.open("D:/Practice Week/vNumtext.txt", ios::in);
	if (!vNumtext.is_open())
		cout << "vNumtext Document Open Failed!!!" << endl;
	int a = 0;
	vNumtext >> vNum >> eNum;
	a = vNum;
	for (int i = 1; i <= a; i++)//初始化矩阵 
		for (int j = 1; j <= a; j++)
		{
			adj222[i][j].weight = IntMax;//初始化为无穷大的距离 
		}
	vNumtext.close();
	ifstream other;//读取地图信息文件 
	other.open("D:/Practice Week/main.txt", ios::in);
	if (!other.is_open())
		cout << "The Information Document Of Map Open Failed!!!" << endl;
	ENode H;
	if (eNum != 0)//如果存在边 
	{
		for (int i = 1; i <= eNum; i++)
		{
			while (!other.eof())
			{
				other >> H.V1.num >> H.V2.num >> H.V1.name >> H.V2.name >> H.weight;
				adj222[H.V1.num][H.V2.num].weight = H.weight;//给两个地点之间的距离赋值 
				adj222[H.V2.num][H.V1.num].weight = H.weight;
			}
		}
	}
	other.close();
	//	cout<<setw(8)<<"\t"<<"    ";
	//	for(int k=1;k<=vNum;k++)
	//		cout<<name[k]<<"  ";
	//	cout<<endl;
	//	for(int i=1;i<=vNum;i++)
	//	{
	//		cout<<setw(8)<<name[i]<<setw(10);
	//		for(int j=1;j<=vNum;j++)
	//		{
	//			cout<<adj222[i][j].weight<<"\t"<<"   ";
	//		}
	//		cout<<endl;
	//	}
	//	
		//定义二维数组,此处用弗洛伊德算法 
	int v, w, k;
	int D[51][51];
	int P[51][51];
	//int D[vNum + 1][vNum + 1];
	//int P[vNum + 1][vNum + 1];
	for (v = 1; v <= a; v++) /* 初始化D与P */
	{
		for (w = 1; w <= a; w++)
		{
			D[v][w] = adj222[v][w].weight; /* D[v][w]值即为对应点间的权值 */
			P[v][w] = w; /* 初始化P */
		}
	}

	for (k = 1; k <= a; k++)
	{
		for (v = 1; v <= a; v++)
		{
			for (w = 1; w <= a; w++)
			{
				/* 如果经过下标为k顶点路径比原两点间路径更短 */
				if (D[v][w] > D[v][k] + D[k][w])
				{
					/* 将当前两点间权值设为更小的一个 */
					D[v][w] = D[v][k] + D[k][w];
					P[v][w] = P[v][k]; /* 路径设置为经过下标为k的顶点 */
				}
			}
		}
	}
	//建立好最短路径表之后开始进行查询 
	//第一步输入起点和终点 
	string begin, end;
	//	cout<<"请输入起点："<<endl;
	//	cin >> begin;
	//	cout<<endl<<"请输入终点："<<endl;
	//	cin>>end;
	//	cout<<endl;
	string vname;
	ifstream fIn("D:/Practice Week/Minimumscanf.txt");
	while (fIn.peek() != EOF)
	{
		getline(fIn, vname);
	}
	int fl = vname.find('%');
	begin = vname.substr(0, fl);
	end = vname.substr(fl + 1);
	//第二步找到起点和终点在矩阵中的位置 
	int i, j;//记录位置 
	for (i = 1; i <= a; i++)
	{
		if (!(begin.compare(name[i])))
			break;
	}
	for (j = 1; j <= a; j++)
	{
		if (!(end.compare(name[j])))
			break;
	}
	//	if(i==vNum+1||j==vNum+1)
	//	{
	//		cout<<"请检查您输入的起点和终点是否正确哦！"<<endl<<endl; 
	//		return;
	//	}
		//第三步，路径的输出(输出到txt文件中)，将找到的2个地点投影到P数组中去找出经过点最少的路径
	ofstream ofs;
	ofs.open("D:/Practice Week/Minimumpoints.txt", ios::out);
	ofs << name[i];
	k = P[i][j];
	while (k != j)
	{
		ofs << "%" << name[k];
		k = P[k][j];
	}
	ofs << "%" << name[j] << endl;
	ofs << '#' << D[i][j];
	ofs.close();
	return;
}
//--------------------------------------------------------

int Map::find_node(string fname)
{
	for (int i = 1; i <= vNum; i++)
	{
		if (name[i] == fname)
		{
			return i; //找到了，返回相对应的位置
			break;
		}
	}
	return -1;//没有找到返回-1

}

void Map::ShortestPath_Dijkstra()
{
	string vname;
	ifstream fIn("Minimumscanf.txt");
	while (fIn.peek() != EOF)
	{
		getline(fIn, vname);
	}
	int fl = vname.find('%');
	string start_name = vname.substr(0, fl);
	string end_name = vname.substr(fl + 1);
	int start = find_node(start_name);
	int end = find_node(end_name);
	//    while(end == -1)
	//    {
	//        cout << "无此信息，请重新输入" << endl;
	//        cin >> end_name;
	//        end = find_node(end_name);
	//    }

	int dis[30];
	int path[30];
	for (int i = 1; i <= vNum; i++) //初始化dis path
	{
		if (start != i && adj[start][i].weight == 0)
			dis[i] = IntMax;
		else if (adj[start][i].weight != 0)
			dis[i] = adj[start][i].weight;
		else if (start == i)
			dis[i] = 0;
		path[i] = -1;
	}
	bool visited[30] = { false };
	// int s=start;
	visited[start] = true;
	while (1)
	{
		int j;
		bool flag = false;
		for (j = 1; j <= vNum; j++)
		{
			if (visited[j] == false)
			{
				flag = true;
				break;
			}
		}
		int min = j;
		if (flag == false)
			break;
		for (int i = 1; i <= vNum; i++)
		{
			if (visited[i] == false)
				if (dis[min] > dis[i])
					min = i;

		}


		visited[min] = true; //收录的条件就是dis里面最小的
		for (int i = 1; i <= vNum; i++)
		{
			if (adj[min][i].weight != 0 && visited[i] == false) //i是min的邻接点
				if (dis[i] > dis[min] + adj[min][i].weight)
				{
					dis[i] = dis[min] + adj[min][i].weight;
					//暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
					path[i] = min; //暂时的
				}

		}
	}
	if (dis[end] == IntMax)
		cout << "从" << name[start] << "->" << name[end] << "不通" << endl;
	else
	{
		//        cout << "从" << name[start] << "->" << name[end] << "的最短路径为：  " << dis[end] << "m\n"<< "路径为：";
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);

		//        cout << name[st.top()];
		ofstream ofs;
		ofs.open("Dijkstraprintf.txt", ios::out);
		ofs << name[st.top()];
		st.pop();
		while (!st.empty())
		{
			ofs << "%" << name[st.top()];
			st.pop();
		}
		//        cout << endl;
	}

}


void Menu()//系统菜单 
{
	int Fun;
	Py_SetPythonHome(L"D:/Anaconda");
	Py_Initialize();//python初始化
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('D:/Practice Week')");
	PyObject* PModule_jiemian = PyImport_ImportModule("Practice_1");// 导入模块
	if (!PModule_jiemian) {// 检验是否导入成功
		cout << "Python get moudle failed" << endl;
		//return 0;
	}
	cout << "Practice_1 get moudle succeed" << endl;
	fstream fs;
	fs.open("D:/Practice Week/Function_Choose.txt", ios::in);
	string function_check;
	if (fs.is_open())
	{
		string line;
		while (getline(fs, line))
		{
			function_check += line;
		}
		fs.close();
		int a = function_check.length();
		Fun = function_check[a - 1];
	}
	else {
		cout << "Function_Choose.txt get failed!" << endl;
	}
	Py_Finalize();
}

/*
void choose(Map& G)//用户选择的功能
{
	int choice;
	int kk = 0;
	while (kk <= 8) {
		//Menu();
		cout << "请输入想使用的功能序号:" << endl;
		cin >> choice;
		kk = choice;
		switch (choice)
		{
		case 1:
			G.PrintAdjMatrix();
			break;
		case 2:
			G.PrintAdjList();
			break;
		case 3:
			//			cout<<"待完善！";
			G.ModifyMap();
			break;
		case 4:
			cout << "待完善！";
			break;
		case 5:
			cout << "待完善！";
			break;
		case 6:
			cout << "待完善！";
			break;
		case 7:
			cout << "待完善！";
			break;
		case 8:
			cout << "待完善！";
			break;
		case 9:
			break;

		}
	}
}
*/

/*
struct Node//点的信息 
{
	int num;//编号 
	string name;//地名 
};

struct ENode
{
	Node V1, V2;//边的起点和终点 
	int weight;//边的权值 
};

struct Place {
	int vNum;//顶点数 
	int eNum;//边数 
	//ENode adj[MaxLen][MaxLen];//邻接矩阵
};

string name[100] = { " ","stadium","lecturehall","auditorium",
					"library","laboratorybuilding","teachingbuilding",
					"octagonhouse","officebuilding","firstdininghall",
					"tunnel","seconddininghall","clinicbuilding",
					"youkangmarket","gogonewworld","dorm" };//每个地点的编号 从1开始 

*/

int main()
{
	Map m1;
	int Func,finish=0;
	m1.CreateMap();
	while (1) {
		Py_SetPythonHome(L"D:/Anaconda");
		Py_Initialize();//python初始化
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('D:/Practice Week')");
		PyObject* PModule_jiemian = PyImport_ImportModule("Practice_1");// 导入模块
		if (!PModule_jiemian) {// 检验是否导入成功
			cout << "Python get moudle failed" << endl;
			return 0;
		}
		else cout << "Practice_1 get moudle succeed" << endl;
		fstream fs;
		fs.open("D:/Practice Week/Function_Choose.txt", ios::in);
		string function_check;
		if (fs.is_open())
		{
			string line;
			while (getline(fs, line))
			{
				function_check += line;
			}
			fs.close();
			int a = function_check.length();
			Func = int(function_check[a - 1]);
			Func -= 48;
		}
		else {
			cout << "Function_Choose.txt get failed!" << endl;
		}

		if (Func == 1) {
			m1.PrintAdjMatrix();
		}

		if (Func == 2) {
			m1.PrintAdjList();
		}

		if (Func == 3) {
			PyObject* PModule_func_three = PyImport_ImportModule("Button_3");// 导入模块
			if (!PModule_func_three) {// 检验是否导入成功
				cout << "Button_3 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_3 get moudle succeed" << endl;
			m1.DFS_Min();
			PyObject* PModule_func_three_next = PyImport_ImportModule("Button_3_Next");// 导入模块
			if (!PModule_func_three_next) {// 检验是否导入成功
				cout << "Button_3_Next get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_3_Next get moudle succeed" << endl;
		}

		if (Func == 4) {
			PyObject* PModule_func_four = PyImport_ImportModule("Button_4");// 导入模块
			if (!PModule_func_four) {// 检验是否导入成功
				cout << "Button_4 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_4 get moudle succeed" << endl;
			m1.AdjacentNodes();
			/*
			PyObject* PModule_func_three_next = PyImport_ImportModule("Button_3_Next");// 导入模块
			if (!PModule_func_three_next) {// 检验是否导入成功
				cout << "Button_3_Next get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_3_Next get moudle succeed" << endl;
			*/
		}
		
		if (Func == 5) {
			PyObject* PModule_func_five = PyImport_ImportModule("Button_5");// 导入模块
			if (!PModule_func_five) {// 检验是否导入成功
				cout << "Button_5 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_5 get moudle succeed" << endl;
			m1.ShortestPath_Dijkstra();
			PyObject* PModule_func_five_min = PyImport_ImportModule("Button_5_shortest");// 导入模块
			if (!PModule_func_five_min) {// 检验是否导入成功
				cout << "Button_5_shortest get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_5_shortest get moudle succeed" << endl;
		}

		if (Func == 6) {
			PyObject* PModule_func_six = PyImport_ImportModule("Button_5");// 导入模块
			if (!PModule_func_six) {// 检验是否导入成功
				cout << "Button_6 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_6 get moudle succeed" << endl;
			m1.Minimumpoints();
			PyObject* PModule_func_five_min = PyImport_ImportModule("Button_5_min");// 导入模块
			if (!PModule_func_five_min) {// 检验是否导入成功
				cout << "Button_5_min get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_5_min get moudle succeed" << endl;
		}
		
		if (Func == 7) {
			PyObject* PModule_func_seven = PyImport_ImportModule("Button_7");// 导入模块
			if (!PModule_func_seven) {// 检验是否导入成功
				cout << "Button_7 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_7 get moudle succeed" << endl;
			m1.ModifyMap();
		}
		
		if (Func == 8)break;
		/*
		switch (Func) {
		case 1:
			cout << "Adjacent Matrix" << endl;
			break;
		case 2:
			cout << "Adjacency List" << endl;
			break;
		case 3:
			cout<<"Clock In The Campus"<<endl;
			break;
		case 4:
			cout << "Check The Nearby Places"<<endl;
			break;
		case 5:
			PyObject * PModule_func_five = PyImport_ImportModule("Button_5");// 导入模块
			if (!PModule_func_five) {// 检验是否导入成功
				cout << "Button_5 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_5 get moudle succeed" << endl;
			break;
		case 6:
			PyObject * PModule_func_six = PyImport_ImportModule("Button_5");// 导入模块
			if (!PModule_func_six) {// 检验是否导入成功
				cout << "Button_5 get moudle failed" << endl;
				return 0;
			}
			else cout << "Button_5 get moudle succeed" << endl;
			break;
		case 7:
			cout << "待完善！";
			break;
		case 8:
			finish = 1;
			break;
		}
		*/
		//if (finish)break;
		Py_Finalize();
	}
	
	
	return 0;
}
