#include <string>
#include "../../../../include/db/builder/enums/types.hpp"

std::string field_type_to_string(FieldType type) {
    switch (type) {
        case FieldType::INTEGER: return "INTEGER";
        case FieldType::TEXT: return "TEXT";
        case FieldType::REAL: return "REAL";
        case FieldType::BLOB: return "BLOB";
        case FieldType::NUMERIC: return "NUMERIC";
        default: return "";
    }
}