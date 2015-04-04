#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRectF>

#include <iostream>
#include <vector>

struct main_window : public QWidget
{
	Q_OBJECT

	std::vector<bool> m_pressed_keys;
	
	size_t m_lowest_key;
	
	public:
		main_window() :
			QWidget(0, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
			m_pressed_keys(128, false),
			m_lowest_key(60)
		{
			//! TODO: Set opaque flag since we paint every pixel anyways
		}
		
		void keyPressEvent(QKeyEvent *event) override 
		{
			if (event->key() == Qt::Key_PageUp)
			{
				m_lowest_key += 12;
			}

			if (event->key() == Qt::Key_PageDown)
			{
				m_lowest_key -= 12;
			}

			//m_lowest_key %= (10 * 12);
			
			repaint();
		}
		
		void paintEvent(QPaintEvent *event) override
		{
			std::cout << "." << std::endl;
			
			const float key_width = (float)geometry().width()/128.0f;
			const float key_height = (float)geometry().height();
			
			const float range_indicator_height = 5;
					
			for (size_t key_index; key_index < 128; ++key_index)
			{
				{
					QPainter painter(this);
					painter.setPen(Qt::black);
				
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
					painter.drawRect((float)key_index * key_width, 0.0f, key_width, key_height - range_indicator_height);
				}
				
				{
					QPainter painter(this);
					
					painter.setBrush(Qt::white);
					painter.setPen(Qt::white);
					
					if ((key_index >= m_lowest_key) && (key_index < m_lowest_key + 24))
					{
						painter.setPen(Qt::blue);
						painter.setBrush(Qt::blue);
					}
					
					painter.drawRect((float)key_index * key_width, (key_height - range_indicator_height) + 1, key_width, range_indicator_height);
				}
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

