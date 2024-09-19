#include <QApplication>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Connect to the Microsoft Access database
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=HRManagement.accdb");
    db.open();

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("HR Management System");
    window.show();

    // Create a query to retrieve employee data
    QSqlQuery query;
    query.exec("SELECT * FROM Employees");

    // Display the employee data in a table
    QTableWidget table;
    table.setRowCount(query.size());
    table.setColumnCount(5);
    table.setHorizontalHeaderLabels(QStringList() << "Employee ID" << "Name" << "Department" << "Job Title" << "Hire Date");

    while (query.next()) {
        table.setItem(query.value(0).toInt(), 0, new QTableWidgetItem(query.value(1).toString()));
        table.setItem(query.value(0).toInt(), 1, new QTableWidgetItem(query.value(2).toString()));
        table.setItem(query.value(0).toInt(), 2, new QTableWidgetItem(query.value(3).toString()));
        table.setItem(query.value(0).toInt(), 3, new QTableWidgetItem(query.value(4).toString()));
        table.setItem(query.value(0).toInt(), 4, new QTableWidgetItem(query.value(5).toString()));
    }

    window.setCentralWidget(&table);

    return app.exec();
}