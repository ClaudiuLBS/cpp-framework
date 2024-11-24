#include <string>
#include "../../../../include/db/builder/enums/constraints.hpp"

std::string field_constraint_to_string(FieldConstraint constraint) {
    switch (constraint) {
    case FieldConstraint::PRIMARY_KEY: return "PRIMARY KEY";
    case FieldConstraint::AUTOINCREMENT: return "AUTOINCREMENT";
    case FieldConstraint::NOT_NULL: return "NOT NULL";
    case FieldConstraint::UNIQUE: return "UNIQUE";
    case FieldConstraint::DEFAULT: return "DEFAULT";
    default: return "";
    }
}