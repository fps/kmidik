#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRectF>

#include <iostream>
#include <vector>
#include <map>

struct main_window : public QWidget
{
	Q_OBJECT

	std::map<int, int> m_key_map;
	
	std::vector<bool> m_pressed_keys;
	
	size_t m_lowest_key;
	
	public:
		main_window() :
			QWidget(0, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
			m_pressed_keys(128, false),
			m_lowest_key(60)
		{
			m_pressed_keys[60] = true;
			m_pressed_keys[63] = true;
			//! TODO: Set opaque flag since we paint every pixel anyways
			
			int offset = 0;
			m_key_map[Qt::Key_Z] = offset++;
			m_key_map[Qt::Key_S] = offset++;
			m_key_map[Qt::Key_X] = offset++;
			m_key_map[Qt::Key_D] = offset++;
			m_key_map[Qt::Key_C] = offset++;
			m_key_map[Qt::Key_V] = offset++;
			m_key_map[Qt::Key_G] = offset++;
			m_key_map[Qt::Key_B] = offset++;
			m_key_map[Qt::Key_H] = offset++;
			m_key_map[Qt::Key_N] = offset++;
			m_key_map[Qt::Key_J] = offset++;
			m_key_map[Qt::Key_M] = offset++;
		}

		
		void keyReleaseEvent(QKeyEvent *event) override 
		{
			if (m_key_map.find(event->key()) != m_key_map.end())
			{
				m_pressed_keys[m_lowest_key + m_key_map[event->key()]] = false;
			}
			
			repaint();
		}
		
		void keyPressEvent(QKeyEvent *event) override 
		{
			if (event->key() == Qt::Key_PageUp && m_lowest_key < 10 * 12)
			{
				m_lowest_key += 12;
			}

			if (event->key() == Qt::Key_PageDown && m_lowest_key > 0)
			{
				m_lowest_key -= 12;
			}

			if (event->key() == Qt::Key_Escape)
			{
				QApplication::quit();
			}
			
			if (m_key_map.find(event->key()) != m_key_map.end())
			{
				m_pressed_keys[m_lowest_key + m_key_map[event->key()]] = true;
			}
			
			repaint();
		}
		
		void paintEvent(QPaintEvent *event) override
		{
			// std::cout << "." << std::endl;
			
			const float key_width = (float)geometry().width()/128.0f;
			const float key_height = (float)geometry().height();
			
			const float range_indicator_height = 5;
					
			for (size_t key_index = 0; key_index < 128; ++key_index)
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

					painter.drawRect(QRectF((float)key_index * key_width, 0.0f, key_width, key_height - range_indicator_height));
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
					
					painter.drawRect(QRectF((float)key_index * key_width, (key_height - range_indicator_height) + 1, key_width, range_indicator_height));
				}
				
				{
					QPainter painter(this);
					
					painter.setPen(Qt::gray);
					painter.setBrush(Qt::gray);
					
					const float indicator_extra = 3.0f;
					
					if (m_pressed_keys[key_index])
					{
						painter.drawRect(QRectF((float)key_index * key_width + indicator_extra, indicator_extra, key_width - (2.0f * indicator_extra), (key_height - (2.0f * indicator_extra)) - range_indicator_height));
					}
				}
			}
		}
};

