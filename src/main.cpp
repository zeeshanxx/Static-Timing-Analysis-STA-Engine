#include "../include/sta_engine.h"

// Example circuit to demonstrate timing propagation
// Node 0 -> primary input
// Node 5 -> primary output

int main() {
    STAEngine sta(6);

    sta.addEdge(0, 1, 2.0);
    sta.addEdge(0, 2, 3.0);
    sta.addEdge(1, 3, 2.5);
    sta.addEdge(2, 3, 1.5);
    sta.addEdge(3, 4, 2.0);
    sta.addEdge(4, 5, 1.0);

    sta.runSTA(0, 5);
    return 0;
}
