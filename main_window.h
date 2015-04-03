#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>

#include <iostream>
#include <vector>

struct main_window : public QWidget
{
	Q_OBJECT

	std::vector<bool> m_pressed_keys;
	
	size_t m_lowest_key;
	
	public:
		main_window() :
			QWidget(nullptr, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
			m_pressed_keys(128, false),
			m_lowest_key(60)
		{
			//! TODO: Set opaque flag since we paint every pixel anyways
		}
		
		void paintEvent(QPaintEvent *event) override
		{
			std::cout << "." << std::endl;
			
			QPainter painter(this);
			painter.setPen(Qt::black);
			
			for (size_t key_index; key_index < 128; ++key_index)
			{
				const size_t key = key_index % 12;
				if (key == 1 || key == 3 || key == 6 || key == 8 || key == 10)
				{
					painter.setBrush(Qt::black);
				} 
				else
				{
					painter.setBrush(Qt::white);
				}
#if 0
				if (true == m_pressed_keys[key_index])
				{
					//painter.setBrush(Qt::red);
				}
#endif
				const float width = (float)geometry().width()/128.0f;
				
				const float height = 50;// = (float)geometry().height();
				
				painter.drawRect((float)key_index * width, 0, width, height - 2);
#if 0
				
				painter.setBrush(Qt::black);
				if (key_index >= m_lowest_key && key_index < m_lowest_key + 24)
				{
						painter.setPen(Qt::red);
						painter.setBrush(Qt::red);
				}
				
				painter.drawRect((float)key_index * width, height - 2, width, 2);
#endif
			}
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

