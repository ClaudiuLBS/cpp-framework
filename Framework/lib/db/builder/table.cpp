#include <vector>
#include <string>
#include "../../../include/db/builder/table.hpp"

Table::Table(const std::string& table_name) : name(table_name) {}

void Table::add_field(const std::string& field_name, FieldType type, const std::vector<FieldConstraint>& constraints) {
    fields.emplace_back(field_name, type, constraints);
}

std::string Table::generate_create_table_sql() const {
    std::string sql = "CREATE TABLE " + name + " (\n";
    for (size_t i = 0; i < fields.size(); ++i) {
        sql += "    " + fields[i].name + " " + field_type_to_string(fields[i].type);

        for (const auto& constraint : fields[i].constraints) {
            sql += " " + field_constraint_to_string(constraint);
        }

        if (i < fields.size() - 1) {
            sql += ",";
        }
        sql += "\n";
    }
    sql += ");";
    return sql;
}
