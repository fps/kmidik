#include <kglobalaccel.h>
#include <QApplication>
#include <event_filter.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	KGlobalAccel *k = KGlobalAccel::self();
	event_filter f;
	app.installEventFilter(&f);
	return app.exec();
}

