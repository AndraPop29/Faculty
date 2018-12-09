#include "adminagui.h"
#include "qmessagebox.h"
adminaGUI::adminaGUI(Controller* _c,QWidget *parent)
	:c(_c), QWidget(parent)
{
	ui.setupUi(this);
	connectSignalsAndSlots();
	populateList();
}
void adminaGUI::connectSignalsAndSlots()
{
	QObject::connect(ui.addBut, SIGNAL(clicked()), this, SLOT(addStudent()));
	QObject::connect(ui.removeBut, SIGNAL(clicked()), this, SLOT(removeStudent()));
}
void adminaGUI::populateList() {
	ui.listStudents->clear();
	for (auto it : c->getStudents()) {
		ui.listStudents->addItem(new QListWidgetItem(QString::fromStdString(it.humanString())));
	}
}
int adminaGUI::getSelectedItem() {
	auto v = ui.listStudents->selectedItems();
	if (v.size() == 0)
		return -1;
	return ui.listStudents->row(v[0]);
}
void adminaGUI::removeStudent()
{
	int idx = getSelectedItem();
	if (idx == -1)
		return;
	int ret = QMessageBox::warning(this, "Delete Student", "Are you sure you want to delete the selected student?", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
	if (ret != QMessageBox::Ok)
		return;
	Student s = c->getStudents()[idx];
	c->removeStudent(s);
	populateList();
}
void adminaGUI::addStudent()
{
	int id = ui.idEdit->text().toInt();
	string name = ui.nameEdit->text().toStdString();
	int group = ui.groupEdit->text().toInt();
	c->addStudent(Student(id, name, group, 0, ""));
	populateList();
}
adminaGUI::~adminaGUI()
{

}
