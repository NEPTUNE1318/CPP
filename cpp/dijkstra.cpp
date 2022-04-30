#include <vector>
#include <iostream>
#include <queue>

#define MAX 100
#define INF 99999999

using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int,int> > adj[]) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int> > pq;
    
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int nCost = cost + adj[cur][i].second;
            if (nCost < dist[next] ) {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }
    
    return dist;
}

int main()
{
    int V,E, start;
    vector<pair<int, int> > adj[MAX];
    cout << "정점의 개수 입력 : ";
    cin >> V;
    cout << "간선의 개수 입력 : ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cout << "그래프 입력 [정점 정점 가중치]: ";
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
    }
	
	cout << "시작점 입력 : ";
	cin >> start;
    cout << endl;
    cout << "===다익스트라 결과===" << endl;
    vector<int> dist = dijkstra(start, V, adj);
    for (int i = 0; i < V; i++) {
        printf("%d번 정점에서 %d번 정점까지 최단거리 : %d\n", start, i, dist[i]);
    }
    return 0;
}
