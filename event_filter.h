#include <QObject>
#include <QEvent>

#include <iostream>

struct event_filter : public QObject
{
	Q_OBJECT

	public:
		event_filter() 
		{

		}

	protected:
		bool eventFilter(QObject *obj, QEvent *event)
		{
			if (event->type() == QEvent::KeyPress)
			{
				std::cout << "." << std::endl;
			}
			return true;
		}
};

