#pragma once
#ifndef RELATION_HPP
#define RELATION_HPP

#include "BooleanMatrix.hpp"
#include "ProductSet.hpp"

class Relation
{
public:
    BooleanMatrix getRelationMatrix();
    Relation(BooleanMatrix const &);
protected:
    BooleanMatrix relation_matrix;
};
#endif