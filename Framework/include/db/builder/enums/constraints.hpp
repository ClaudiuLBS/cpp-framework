#pragma once

#include <string>

enum class FieldConstraint {
    PRIMARY_KEY,
    AUTOINCREMENT,
    NOT_NULL,
    UNIQUE,
    DEFAULT
};

std::string field_constraint_to_string(FieldConstraint constraint);
