#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}


void dikstra(vector<vector<pair<int, int> > > graph, int source, set<pair<int, int> > sptSet, unordered_map<int, int> dist)
{


    while(!sptSet.empty())
    {
        int vertex = (*(sptSet.begin())).first;
        sptSet.erase({vertex, dist[vertex]});

        int numOfNeighbours = graph[vertex].size();
        for(int i = 0; i<=numOfNeighbours - 1; i++)
        {
            if(sptSet.find({graph[vertex][i].first, dist[graph[vertex][i].first]}) != sptSet.end() && dist[vertex] + graph[vertex][i].second < dist[graph[vertex][i].second])
            {
                //remove from the set
                sptSet.erase(sptSet.find({graph[vertex][i].first, dist[graph[vertex][i].first]}));
                //update in the dist
                 dist[graph[vertex][i].second] = dist[vertex] + graph[vertex][i].second;
                // add again to the set
                sptSet.insert({graph[vertex][i].first, dist[graph[vertex][i].first]});
            }
        }

    }


}
    

void buildGraph(vector<vector<int> > &times, int n, vector<vector<pair<int, int> > > &graph)
{
    vector<pair<int, int> > temp;
    for(int i = 0; i<= n-1; i++)
        graph.push_back(temp);

    int si = times.size();
    for(int i = 0; i<=si - 1; i++)
        graph[times[i][0]].push_back({times[i][1], times[i][2]});
}
    
int networkDelayTime(vector<vector<int> > &times, int n, int k) {
    vector<vector<pair<int, int> > > graph;
    buildGraph(times, n, graph);
    set<pair<int, int> > sptSet;
    unordered_map<int, int> dist;
    for(int i = 0; i<=n-1; i++)
    {
        if(i != k-1)
            sptSet.insert({i, INT_MAX}), dist[i] = INT_MAX;
        else
            sptSet.insert({i, 0}), dist[i] = 0;
    }

    dikstra(graph, k, sptSet, dist);

    int answer = -1;
    for(auto it: dist)
    {
        answer = max(answer, it.second);
    }
    if(answer == INT_MAX)
        return -1;
    return answer;
}
int main()
{
    map<int, int, decltype(&cmp)> mp;
    mp.insert({5, 3});
    mp.insert({7, 2});
    mp.insert({7, 1});
    mp.insert({7, 5});
    cout<<mp.size();
    cout<<endl;
    for(auto it: mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}