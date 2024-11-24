#pragma once

#include <string>
#include <vector>
#include "../../../include/db/builder/enums/types.hpp"
#include "../../../include/db/builder/enums/constraints.hpp"
#include "../../../include/db/builder/field.hpp"

Field::Field(const std::string& n, FieldType t, const std::vector<FieldConstraint>& c)
    : name(n), type(t), constraints(c) {}
