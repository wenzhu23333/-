#include<iostream>
using namespace std;
#define N 6
#include<memory.h>
#include<stdlib.h>

struct Node
{
    int destination;
    int nextJump;
    int cost;
    struct Node* nextNode;
};
typedef Node* NodePtr;

int graph[N][N];
NodePtr routeHeaders[N];
NodePtr newRouteHeaders[N];
int gxcount = 0;
bool isChange=false;

void InitGraph();
void InitRouteTable();
void ShowRouteTable(NodePtr head);
NodePtr CopyRouteTable(NodePtr head);
void DeleteRouteHeaders(NodePtr head);
void Update();


int main()
{
    InitGraph();
    InitRouteTable();
    while(1)
    {
        cout<<"��"<<gxcount+1<<"�ε�·�ɱ�Ϊ��"<<endl;
        isChange = false;
        Update();
        ShowRouteTable(routeHeaders[0]);
        gxcount++;
        if(!isChange)   break;

    }
     for(int i=0; i<N; i++)   DeleteRouteHeaders(newRouteHeaders[i]);
    return 0;
}

//��ʼ����������ͼ
void InitGraph()
{
    memset(graph,-1,sizeof(graph));
    graph[0][1]=11;  graph[0][4]=5;
    graph[1][0]=11;  graph[1][2]=2;  graph[1][5]=6;
    graph[2][1]=2;  graph[2][3]=3;  graph[2][4]=7;
    graph[3][2]=3;  graph[3][5]=1;
    graph[4][0]=5;  graph[4][5]=4;  graph[4][2]=7;
    graph[5][4]=4;  graph[5][1]=6;  graph[5][3]=1;
    /*graph[6][0]=6;  graph[6][4]=1;  graph[6][7]=4;
    graph[7][3]=2;  graph[7][5]=2;  graph[7][6]=4;*/
}

//��ʼ��·�ɱ�
void InitRouteTable()
{
    for(int i=0; i<N; i++)
    {
        routeHeaders[i] = NULL;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(graph[i][j]>0)
            {
                NodePtr newNode = (NodePtr)malloc(sizeof(Node)) ;
                newNode->destination = j;
                newNode->nextJump = j;
                newNode->cost = graph[i][j];
                newNode->nextNode = routeHeaders[i];
                routeHeaders[i] = newNode;
            }
        }

    }
}

void ShowRouteTable(NodePtr head)
{
    NodePtr tmp=head;
    cout<<"Ŀ������"<<"\t"<<"����"<<"\t"<<"��һ��"<<endl;
    while(tmp)
    {

        cout<<char(tmp->destination+65)<<"\t\t"<<tmp->cost<<"\t"<<char(tmp->nextJump+65)<<endl;
        tmp = tmp->nextNode;
    }
}

NodePtr CopyRouteTable(NodePtr head)
{
    NodePtr newTable=NULL,tmp=head;
    while(tmp)
    {
        NodePtr t1 = (NodePtr)malloc(sizeof(Node));
        t1->destination = tmp->destination;
        t1->nextJump = tmp->nextJump;
        t1->cost = tmp->cost;

        t1->nextNode = newTable;
        newTable = t1;

        tmp = tmp->nextNode;
    }

    return newTable;
}

//����·�ɱ�
void Update()
{

    for(int i=0; i<N; i++)
    {
        NodePtr newTable = CopyRouteTable(routeHeaders[i]);     //i����·�ɱ�

        for(int j=0; j<N; j++)
        {
            if(graph[i][j]>0)
            {
                //���i��j���ڣ����ȡj��·�ɱ��޸���Ӧ��Ϣ
                NodePtr t = routeHeaders[j];
                NodePtr head = NULL;
                while(t)
                {
                    NodePtr np = (NodePtr)malloc(sizeof(Node));
                    np->destination = t->destination;
                    np->nextJump = j;            //��һ��Ϊj
                    np->cost = t->cost+graph[i][j];       //����Ҫ��һ
                    np->nextNode = head;
                    head = np;

                    t = t->nextNode;
                }

                //���ݻ�õ�·�ɱ�ȥ����·����Ϣ

                NodePtr t2 = head;              //t2ָ���ȡ��·�ɱ�
                while(t2)
                {
                    NodePtr t1 = newTable;  //t1ָ��i����·�ɱ�ı�ͷ

                    int destination  = t2->destination;
                    while(t1 && (t1->destination!=destination) ) t1=t1->nextNode;
                    if(t1==NULL)
                    {
                        //����ɱ���û�и�Ŀ������destination����Ѹ���Ŀ��ӵ���·�ɱ���
                        if(t2->destination != i) //����Ŀ�����粻�����Լ�
                        {
                            isChange=true;
                            NodePtr n1 = (NodePtr)malloc(sizeof(Node));
                            n1->destination = t2->destination;
                            n1->nextJump = t2->nextJump;
                            n1->cost = t2->cost;

                            n1->nextNode = newTable;
                            newTable = n1;
                        }

                    }else{
                        //�ɱ����и�Ŀ������destination
                        if(t1->nextJump == j) //����һ����ַ��j������յ�����Ŀ���µ���·�ɱ���
                        {
                            if( t1->cost !=  t2->cost)isChange=true;
                            t1->cost =  t2->cost;
                        } else{
                            //���յ�����Ŀ�еľ���С��ԭ����cost�������
                            if(t2->cost < t1->cost)
                            {
                                isChange=true;
                                t1->cost = t2->cost;
                                t1->nextJump = t2->nextJump;
                            }
                            //����ʲôҲ����
                        }
                    }

                    t2 = t2->nextNode;
                }

            }
        }

        newRouteHeaders[i] = newTable;
    }


    for(int i=0; i<N; i++)
    {
        DeleteRouteHeaders(routeHeaders[i]);
        routeHeaders[i] = newRouteHeaders[i];
    }
        //ShowRouteTable(newRouteHeaders[0]);
}

void DeleteRouteHeaders(NodePtr head)
{

        NodePtr t1=head,t2=t1->nextNode;
        while(t1)
        {
            free(t1);
            t1=t2;
            if(t2)  t2=t2->nextNode;
        }

}

