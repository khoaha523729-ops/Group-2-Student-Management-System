#include "Login.h"
#include "Database.h"

int main() {
    Database db;
    Login app;
    app.run(db);
    return 0;
}