#include <QStringListModel>
#include <QScroller>
#include <QStandardItemModel>
#include "TestListView.h"
//main
TestListView::TestListView(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

	// 设置ListView的ItemDelegate
	CustomItemDelegate* itemDelegate = new CustomItemDelegate(this);
	ui.listView->setItemDelegate(itemDelegate);

	// 设置ListView的Model
	QStandardItemModel* model = new QStandardItemModel(this);
	for (int i = 0; i < 100; i++)
	{
		QStandardItem* item = new QStandardItem();
		item->setData(QIcon(":/path/to/icon.png"), Qt::DecorationRole);
		item->setData(QString("Item %1").arg(i), Qt::DisplayRole);
		item->setData(false, Qt::UserRole); // 初始状态为未选中
		model->appendRow(item);

		// 创建并存储控件
		QCheckBox* checkBox = new QCheckBox();
		item->setData(QVariant::fromValue(static_cast<QWidget*>(checkBox)), Qt::UserRole + 1);
	}
	ui.listView->setModel(model);

	// 启用平滑滚动
	ui.listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	
	// 取消ListView边框
	ui.listView->setFrameShape(QFrame::NoFrame);
}

TestListView::~TestListView()
{}
