#include<bits/stdc++.h
#include<fstream>
using namespace std;
#define MaxLen 100 
struct Node//点的信息 
{
	int num;//编号 
	string name;//地名 
};
struct ENode
{
	Node V1,V2;//边的起点和终点 
	int weight;//边的权值 
};
string name[100]={" ","体育场","学术报告厅","大会堂",
                    "图书馆","实验楼","教学楼",
					"八角楼","办公楼","第一饭堂",
					"隧道口","第二饭堂","门诊楼",
					"又康超市","GoGo新天地","宿舍"};//每个地点的编号 从1开始 
					
class Map
{
	private:
		int vNum;//顶点数 
		int eNum;//边数 
		ENode adj[MaxLen] [MaxLen];//邻接矩阵 
	public:
		Map(); 
		void CreateMap();//地图的构建 
        void ModifyMap();//地图的修改 
        void DeleteMap();//地图的删除 
        void PrintAdjMatrix();//输出地图的邻接矩阵 
        void PrintAdjList();//输出地图的邻接表
        void DFS();
        void DFSmain(string place);
        void Dijkstra();
        void Floyd(); 		
};
 Map::Map()//初始化 
{
	vNum=0;
	eNum=0;		
}
	
void Map::CreateMap()
{
	ifstream vNumtext;//读取顶点数和边数的文件 
	vNumtext.open("vNumtext.txt",ios::in);
	if(!vNumtext.is_open())
	    cout<<"vNumtext文件打开失败"<<endl; 
	int a =0;
	vNumtext>>vNum>>eNum;
	a=vNum;
	for(int i=0;i<a;i++)//初始化矩阵 
		for(int j=0;j<a;j++)
		{
		adj[i][j].weight=0;
		}
	vNumtext.close();
	ifstream main;//读取地图信息文件 
	main.open("main.txt",ios::in);
	if(!main.is_open())
	    cout<<"地图信息文件打开失败"<<endl;
		ENode E; 
	if(eNum!=0)//如果存在边 
	{
		for(int i=0;i<eNum;i++)
		{
			while (!main.eof())
			{
				main>>E.V1.num>>E.V2.num>>E.V1.name>>E.V2.name>>E.weight;
				adj[E.V1.num][E.V2.num].weight=E.weight;//给两个地点之间的距离赋值 
				adj[E.V2.num][E.V1.num].weight=E.weight;
			}
		}
	}
	main.close();		
}
void Map::PrintAdjMatrix()//输出地图的邻接矩阵
{
	cout<<setw(8)<<"\t"<<"    ";
	for(int k=1;k<=vNum;k++)
		cout<<name[k]<<"  ";
	cout<<endl;
	for(int i=1;i<=vNum;i++)
	{
		cout<<setw(8)<<name[i]<<setw(10);
		for(int j=1;j<=vNum;j++)
		{
			cout<<adj[i][j].weight<<"\t"<<"   ";
		}
		cout<<endl;
	}
		
}

void Map::PrintAdjList()//输出地图的邻接表 
{
	for(int i=1;i<=vNum;i++)
	{
		cout<<setw(8)<<i<<"  "<<name[i]<<setw(6);
		for(int j=1;j<=vNum;j++)
		{
			if(adj[i][j].weight!=0)
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
void Map::DFS()
{
	bool *visited;//visit数组 
	visited=new bool[vNum];
	visited[vNum]={0};
	int distance=0;//所用路程 
	cout<<"请输入你的起始地：";
	string place;//地点 
	cin>>place;
	int placenum;//地点的编号 
	for(int i=1;i<=vNum;i++)
	{
		if(place==name[i])
		{
			placenum=i;
			visited[i]=true;
			break;
		}
		else
		cout<<"你输入的地点不存在";
	}
	
}

void Menu()//系统菜单 
{
	cout<<"                                 -----------------------------------------------------"<<endl;
	cout<<"                                 *****************************************************"<<endl;
	cout<<"                                 -----------------欢迎使用校园导航系统----------------"<<endl;
	cout<<"                                 *****************************************************"<<endl;
	cout<<"                                 -----------------------------------------------------"<<endl;
	cout<<"                                                  1.地图的邻接矩阵"<<endl;
	cout<<"                                                  2.地图的邻接表"<<endl;
	cout<<"                                                  3.修改地图"<<endl;
	cout<<"                                                  4.删除地图"<<endl;
	cout<<"                                                  5.打卡所有地方所需距离"<<endl;
	cout<<"                                                  6.一地点到所有其他地点路线"<<endl;
	cout<<"                                                  7.两地点间路线"<<endl;
	cout<<"                                                  8.任意两地点间距离"<<endl;
	cout<<"                                                  9.退出"<<endl;
	cout<<"                                 -----------------------------------------------------"<<endl;
}
	
void choose(Map &G)//用户选择的功能
{
	int choice;
	int kk=0;
	while(kk<=8){
		Menu();
		cout<<"请输入想使用的功能序号:"<<endl;
		cin>>choice;
		kk=choice;
	switch(choice)
	{
		case 1:
			G.PrintAdjMatrix();
			break;
		case 2:
			G.PrintAdjList();
			break;
		case 3:
			cout<<"待完善！";
			break;
		case 4:
			cout<<"待完善！";
			break;
		case 5:
			cout<<"待完善！";
			break;
		case 6:
			cout<<"待完善！";
			break;
		case 7:
			cout<<"待完善！";
			break;
		case 8:
			cout<<"待完善！";
			break;
		case 9:
			break;
			
		}
	}
}
int main()
{
	Map m1;
	m1.CreateMap();
	choose(m1);
	return 0;
}
