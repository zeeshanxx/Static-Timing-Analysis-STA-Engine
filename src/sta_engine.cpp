#include "../include/sta_engine.h"
#include <iostream>
#include <queue>
#include <algorithm>

// Constructor initializes graph and timing arrays
STAEngine::STAEngine(int n) : nodes(n) {
    graph.resize(nodes);
    reverseGraph.resize(nodes);
    arrivalTime.assign(nodes, -1e18);   // acts like -infinity
    requiredTime.assign(nodes, 1e18);   // acts like +infinity
    slack.assign(nodes, 0.0);
}

// Adds a directed edge with delay
void STAEngine::addEdge(int from, int to, double delay) {
    graph[from].push_back({to, delay});
    reverseGraph[to].push_back({from, delay});
}

// Topological sort using Kahn's algorithm
void STAEngine::topologicalSort() {
    std::vector<int> indegree(nodes, 0);

    for (int u = 0; u < nodes; u++) {
        for (auto &e : graph[u]) {
            indegree[e.to]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < nodes; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (auto &e : graph[u]) {
            if (--indegree[e.to] == 0) {
                q.push(e.to);
            }
        }
    }
}

// Forward propagation: compute arrival times
void STAEngine::computeArrivalTime(int source) {
    arrivalTime[source] = 0.0;

    for (int u : topoOrder) {
        if (arrivalTime[u] < 0) continue;

        for (auto &e : graph[u]) {
            arrivalTime[e.to] = std::max(
                arrivalTime[e.to],
                arrivalTime[u] + e.delay
            );
        }
    }
}

// Backward propagation: compute required times
void STAEngine::computeRequiredTime(int sink) {
    requiredTime[sink] = arrivalTime[sink];

    for (int i = topoOrder.size() - 1; i >= 0; i--) {
        int u = topoOrder[i];
        for (auto &e : graph[u]) {
            requiredTime[u] = std::min(
                requiredTime[u],
                requiredTime[e.to] - e.delay
            );
        }
    }
}

// Slack = Required Time - Arrival Time
void STAEngine::computeSlack() {
    for (int i = 0; i < nodes; i++) {
        slack[i] = requiredTime[i] - arrivalTime[i];
    }
}

void STAEngine::runSTA(int source, int sink) {
    topologicalSort();
    computeArrivalTime(source);
    computeRequiredTime(sink);
    computeSlack();

    std::cout << "Node\tAT\tRT\tSlack\n";
    for (int i = 0; i < nodes; i++) {
        std::cout << i << "\t"
                  << arrivalTime[i] << "\t"
                  << requiredTime[i] << "\t"
                  << slack[i] << "\n";
    }

    std::cout << "\nMax Delay (Critical Path): "
              << arrivalTime[sink] << std::endl;
}
