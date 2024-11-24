#pragma once

#include <vector>
#include <string>
#include "field.hpp"

class Table {
public:
    std::string name;                
    std::vector<Field> fields;      

    explicit Table(const std::string& table_name);
    
    void add_field(const std::string& field_name, FieldType type, const std::vector<FieldConstraint>& constraints);

    std::string generate_create_table_sql() const;
};
