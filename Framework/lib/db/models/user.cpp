#include "../../../include/db/models/user.hpp"

Table User("User");

void initialize_user_fields() {
    User.add_field("id", FieldType::INTEGER, { FieldConstraint::PRIMARY_KEY, FieldConstraint::AUTOINCREMENT });
    User.add_field("name", FieldType::TEXT, { FieldConstraint::NOT_NULL });
    User.add_field("email", FieldType::TEXT, { FieldConstraint::UNIQUE, FieldConstraint::NOT_NULL });
}
