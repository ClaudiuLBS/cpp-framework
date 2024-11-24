#pragma once

#include <string>
#include <vector>
#include "enums/types.hpp"
#include "enums/constraints.hpp"

struct Field {
    std::string name;
    FieldType type;
    std::vector<FieldConstraint> constraints;

    Field(const std::string& n, FieldType t, const std::vector<FieldConstraint>& c);
};
