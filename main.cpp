#include<iostream>

using namespace std;

#define INF 999

int V, source, cost[100][100];
int dtance[100];
bool visited[100] = { 0 };
int parent[100];

void init()
{
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
		dtance[i] = INF;
	}

	dtance[source] = 0;
}

int getNearest()
{
	int minvalue = INF;
	int minnode = 0;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i] && dtance[i] < minvalue)
		{
			minvalue = dtance[i];
			minnode = i;
		}
	}

	return minnode;
}


void dijkstraAlgorithm()
{

	for (int i = 0; i < V; i++)
	{
		int nearest = getNearest();
		visited[nearest] = true;

		for (int adj = 0; adj < V; adj++)
		{

			if (cost[nearest][adj] != INF && 
				dtance[adj] > dtance[nearest] + cost[nearest][adj])
			{
				dtance[adj] = dtance[nearest] + cost[nearest][adj];
				parent[adj] = nearest;

			}
		}
	}
}

void display()
{
	cout << "Node:\t\t\tCost :\t\t\tPath";

	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t\t" << dtance[i] << "\t\t\t" << " ";

		cout << i << " ";

		int parnode = parent[i];

		while (parnode != source)
		{
			cout << " <-- " << parnode << " ";
			parnode = parent[parnode];
		}
		cout << endl;
	}
}

int main(void) 
{
	cout << "Please Enter number of vertives : ";
	cin >> V;

	for (int i = 0; i < V; i++) 
	{
		for (int j = 0; j< V; j++) 
		{
			cin >> cost[i][j];
		}
	}

	cout << "Source Node : ";
	cin >> source;

	init();
	dijkstraAlgorithm();
	display();
	
}
