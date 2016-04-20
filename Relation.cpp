#include"Relation.hpp"

BooleanMatrix Relation::getRelationMatrix() {
    return relation_matrix;
}
Relation::Relation(BooleanMatrix const &a) : relation_matrix(a) {}
