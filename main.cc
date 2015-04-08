#include <kglobalaccel.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QAction>
#include <QKeySequence>

#include <main_window.h>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	main_window w;

	w.setGeometry(QRect(0, 0, QApplication::desktop()->screenGeometry().width(), 50));
	w.show();

	KGlobalAccel *k = KGlobalAccel::self();
	
	QAction a("Toggle the kmidikeyboard widget's visibility", 0);
	a.setObjectName("kmidikeyboard toggly vis");
	QObject::connect(&a, &QAction::triggered, &w, &main_window::toggle_visibility);
	
	std::cout << (k->setGlobalShortcut(&a, QKeySequence("Ctrl+Shift+M"))) << std::endl;
	
	return app.exec();
}

