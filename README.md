# Static Timing Analysis (STA) Engine in C++

This project is a simplified implementation of a Static Timing Analysis (STA)
engine written in C++. The goal of the project is to understand how timing
analysis is performed in digital circuits by modeling the circuit as a graph
and applying basic graph algorithms.

The implementation focuses on core STA concepts such as arrival time,
required time, slack calculation, and critical path identification.

This is an educational project inspired by EDA fundamentals rather than a
replacement for commercial tools.

---

## What this project does

- Models a digital circuit as a Directed Acyclic Graph (DAG)
- Computes arrival time using forward traversal
- Computes required time using backward traversal
- Calculates slack for each node
- Identifies timing-critical paths in the circuit

---

## Why this project

Static Timing Analysis is a fundamental concept in electronic design
automation. I built this project to strengthen my understanding of:

- C++ and STL
- Graph data structures
- Topological sorting
- Forward and backward graph traversal
- Timing analysis concepts used in EDA tools

---

## Technologies Used

- C++
- STL (vector, queue, algorithms)
- Graph algorithms

---

## How to Build

```bash
make
