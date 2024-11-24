#pragma once

#include <string>

enum class FieldType {
    INTEGER,
    TEXT,
    REAL,
    BLOB,
    NUMERIC
};

std::string field_type_to_string(FieldType type);
