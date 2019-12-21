#include <iostream>
#include <fstream>
#define  routeTable "routeTable.txt"
using namespace std;
#define INFINITY 99999
const int MAX_NODES = 1024;
int dist[MAX_NODES][MAX_NODES];   //���ڴ���������˽ṹ���Ӿ���
int static Vnums=6;  //�ܵĽڵ���
void initDist() {    //��ʼ���ڽӾ���
	for (int i = 0; i < MAX_NODES; i++)
		for (int j = 0; j < MAX_NODES; j++)
			dist[i][j] = 0;
}
void creatRouteMap(){ //�����������˽ṹ���ڽӾ���
	dist[0][1] = 11;
    dist[0][2] = INFINITY;
    dist[0][3] = INFINITY;
    dist[0][4] = 5;
    dist[0][5] = INFINITY;
	dist[1][0] = 11;
	dist[1][2] = 2;
	dist[1][3] = INFINITY;
	dist[1][4] = INFINITY;
	dist[1][5] = 6;
	dist[2][0] = INFINITY;
	dist[2][1] = 2; dist[2][3] = 3;
	dist[2][4] = 7; dist[2][5] = INFINITY;
	dist[3][0] = INFINITY;
	dist[3][1] = INFINITY;
	dist[3][2] = 3;
	dist[3][4] = INFINITY;
	dist[3][5] = 1;
	dist[4][0] = 5;
	dist[4][1] = INFINITY;
	dist[4][2] = 7;
	dist[4][3] = INFINITY;
	dist[4][5] = 4;
	dist[5][0] = INFINITY;
	dist[5][1] = 6;
	dist[5][2] = INFINITY;
    dist[5][3] = 1;
    dist[5][4] = 4;
}
void saveRoute(ofstream& routeTables) {  //����·����Ϣ
	for (int i = 0; i < Vnums; i++)
	{
		for (int j = 0; j < Vnums; j++)
		{
			routeTables << dist[i][j] << "\t";
		}
		routeTables << "\n";
	}
}
void dijkstra(int s, int t, int path[]) {
				 struct state {         //��Žڵ�����
					 int predecessor;   //���ڵ�
					 int length;        //Ȩֵ
					 bool lable;      //����״̬
				 }state[MAX_NODES];
				 int k,min;
				 struct state *p;
				 for(p = &state[0]; p < &state[Vnums]; p++)  //��ʼ�����нڵ�����
				 {
					 p->predecessor = -1;
					 p->length = INFINITY;
					 p->lable = false;
				 }
				 state[t].length = 0;
				 state[t].lable = true;
				 k = t;
				 //cout << "���·��Ϊ��" << endl;
				 do{
					 for (int i = 0; i < Vnums; i++)
						 if ((dist[k][i] != 0) && (state[i].lable == false))
							 if (state[k].length + dist[k][i] < state[i].length)
							 {
								 state[i].predecessor = k;  //��¼�ڵ�
								 //cout << k << "->";
								 state[i].length = state[k].length + dist[k][i];  //·�������ܺ�
							 }
					 k = 0;
					 min = INFINITY;
					 for(int i = 0; i < Vnums; i ++)
						 if((state[i].lable == false) && (state[i].length < min))
						 {
							 min = state[i].length;
							 k = i;
						 }
					 state[k].lable = true;
				 }while (k != s);
				 cout << "��̾���Ϊ��" << min << endl;
				 //cout <<"��̾����·��Ϊ��"<< s<<endl;
			 }
void displayRouteInfo() {   //��ʾ·�ɱ���Ϣ

	for (int i = 0; i < Vnums; i++) {
		for (int j = 0; j < Vnums; j++) {
			cout << dist[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}
int main() {
				 int desNode, rouNode;
				 int path[MAX_NODES];
				 ofstream routeTables;   //��ʼ��Ȩֵ����
				 initDist();
				 creatRouteMap();
				 saveRoute(routeTables);
				 displayRouteInfo();
				 cout << "������̾����Ŀ��ڵ��Դ�ڵ㣺" << endl;
				 cin >> desNode;
				 cin >> rouNode;
				 dijkstra(desNode, rouNode, path);
				 return 0;
}
