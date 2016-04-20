#include "Digraph.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
// Set set;
// int getSetElePos(int);
Digraph::Digraph(BooleanMatrix const &m, Set const &s)  : Relation(m), set(s) {}
int Digraph::inDegree(int n) {
    int a = getSetElePos(n);
    if (a > relation_matrix.getColums())
        return -1;
    int counter = 0;
    for (int i = 1; i <= relation_matrix.getRow(); i++) {
        if (relation_matrix.getElement(i, a)) {
            counter++;
        }
    }
    return counter;
}
int Digraph::outDegree(int n) {
    int a = getSetElePos(n);
    if (a > relation_matrix.getRow())
        return -1;
    int counter = 0;
    for (int i = 1; i <= relation_matrix.getColums(); i++) {
        if (relation_matrix.getElement(a, i)) {
            counter++;
        }
    }
    return counter;
}

Digraph Digraph::pathOfLength(int n) {
    BooleanMatrix temp = relation_matrix;
    if (n == -1) {
        while (true) {
            if (temp == temp.BooleanProduct(relation_matrix)) {
                break;
            }
            temp = temp.BooleanProduct(relation_matrix);
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            temp = temp.BooleanProduct(relation_matrix);
        }
    }
    Digraph tempD(temp, set);
    return tempD;
}

// Properties of Relations.    
bool Digraph::isReflexive() const {
    for (int i = 1; i <= relation_matrix.getColums(); i++) {
        if (relation_matrix.getElement(i, i) == 0)
            return false;
    }
    return true;
}
bool Digraph::isIrreflexive() const {
    for (int i = 1; i <= relation_matrix.getColums(); i++) {
        if (relation_matrix.getElement(i, i) == 1)
            return false;
    }
    return true;
}
bool Digraph::isSymmetric() const {
    if (relation_matrix.getColums() != relation_matrix.getRow())
        return false;
    for (int i = 1; i <= relation_matrix.getRow(); i++) {
        for (int j = 1; j <= relation_matrix.getColums(); j++) {
            if (relation_matrix.getElement(i, j) == 1 && relation_matrix.getElement(j, i) == 0)
                return false;
        }
    }
    return true;
}
bool Digraph::isAsymmetric() const {
    if (relation_matrix.getColums() != relation_matrix.getRow())
        return false;
    for (int i = 1; i <= relation_matrix.getColums(); i++) {
        for (int j = 1; j <= relation_matrix.getColums(); j++) {
            if (relation_matrix.getElement(i, j) == 1 && relation_matrix.getElement(j, i) == 1)
            return false;
        }
    }
    return true;
}
bool Digraph::isAntisymmetric() const {
    if (relation_matrix.getColums() != relation_matrix.getRow())
        return false;
    for (int i = 1; i <= relation_matrix.getColums(); i++) {
        for (int j = 1; j <= relation_matrix.getColums(); j++) {
            if (i == j)
                continue;
            if (relation_matrix.getElement(i, j) ==0 || relation_matrix.getElement(j, i) == 0)
                continue;
            return false;
        }
    }
    return true;
}

bool Digraph::isTransitive() const {
    for(int i = 1; i <= relation_matrix.getRow(); i++) {
        for (int j = 1; j <= relation_matrix.getColums(); j++) {
            for (int k = 1; k <= relation_matrix.getColums(); k++) {
                if (relation_matrix.getElement(i, k) == 1 && relation_matrix.getElement(k, j) == 1) {
                    if (relation_matrix.getElement(i, j) == 0)
                        return false;
                }
            }
        }
    }
    return true;
}

BooleanMatrix Digraph::getBooleanMatrix() const {
    return relation_matrix;
}
int Digraph::getSetElePos(int n) {
    int counter = 1;
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == n)
            break;
        counter++;
    }
    return counter;
}