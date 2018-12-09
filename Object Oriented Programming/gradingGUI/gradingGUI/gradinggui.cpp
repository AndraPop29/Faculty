#include "gradinggui.h"
#include "qlistwidget.h"
#include "qlistview.h"
#include "qmessagebox.h"
gradingGUI::gradingGUI(Controller* _c, Teacher _t, QWidget *parent)
	:c(_c),t(_t), QMainWindow(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(QString::fromStdString(t.getName()));
	connectS();
	PopulateList();
}
void gradingGUI::connectS()
{
	QObject::connect(ui.gradeBut, SIGNAL(clicked()), this, SLOT(gradeStudent()));
}
void gradingGUI::PopulateList()
{
	ui.listStudents->clear();
	vector<Student> s = c->getStudents();
	for (auto stu : s) {
		bool ok = 0;
		for (auto gr : t.getGroups())
			ok |= stu.getGroup() == gr;
		if (ok)
			ui.listStudents->addItem(new QListWidgetItem(QString::fromStdString(stu.humanString())));
	
	}

}
int gradingGUI::getSelectedItem() {
	auto v = ui.listStudents->selectedItems();
	if (v.size() == 0)
		return -1;
	return ui.listStudents->row(v[0]);
}
void gradingGUI::gradeStudent()
{
	int idx = getSelectedItem();
	if (idx == -1)
		return;
	double grade = ui.gradeEdit->text().toDouble();
	
	if (c->getStudents()[idx].getTeach() == "")
	{
		int ret = QMessageBox::warning(this, "Delete Student", "Are you sure you want to delete the selected student?", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		if (ret != QMessageBox::Ok)
			return;
		c->gradeStudent(c->getStudents()[idx], grade, t);
	}
	PopulateList();
}
gradingGUI::~gradingGUI()
{

}
