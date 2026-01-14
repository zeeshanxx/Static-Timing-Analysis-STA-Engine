#ifndef STA_ENGINE_H
#define STA_ENGINE_H

#include <vector>

struct Edge {
    int to;
    double delay;
};

class STAEngine {
private:
    int nodes;
    std::vector<std::vector<Edge>> graph;
    std::vector<std::vector<Edge>> reverseGraph;

    std::vector<double> arrivalTime;
    std::vector<double> requiredTime;
    std::vector<double> slack;
    std::vector<int> topoOrder;

    void topologicalSort();
    void computeArrivalTime(int source);
    void computeRequiredTime(int sink);
    void computeSlack();

public:
    explicit STAEngine(int n);
    void addEdge(int from, int to, double delay);
    void runSTA(int source, int sink);
};

#endif
