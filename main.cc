#include <kglobalaccel.h>
#include <QApplication>
#include <QDesktopWidget>
#include <main_window.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	//KGlobalAccel *k = KGlobalAccel::self();
	main_window w;
	w.setGeometry(QRect(0, 0, QApplication::desktop()->screenGeometry().width(), 50));
	w.show();
	return app.exec();
}

