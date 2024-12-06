#include <QStringListModel>
#include <QScroller>
#include <QStandardItemModel>
#include "TestListView.h"
//main
TestListView::TestListView(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

	// ����ListView��ItemDelegate
	CustomItemDelegate* itemDelegate = new CustomItemDelegate(this);
	ui.listView->setItemDelegate(itemDelegate);

	// ����ListView��Model
	QStandardItemModel* model = new QStandardItemModel(this);
	for (int i = 0; i < 100; i++)
	{
		QStandardItem* item = new QStandardItem();
		item->setData(QIcon(":/path/to/icon.png"), Qt::DecorationRole);
		item->setData(QString("Item %1").arg(i), Qt::DisplayRole);
		item->setData(false, Qt::UserRole); // ��ʼ״̬Ϊδѡ��
		model->appendRow(item);

		// �������洢�ؼ�
		QCheckBox* checkBox = new QCheckBox();
		item->setData(QVariant::fromValue(static_cast<QWidget*>(checkBox)), Qt::UserRole + 1);
	}
	ui.listView->setModel(model);

	// ����ƽ������
	ui.listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	
	// ȡ��ListView�߿�
	ui.listView->setFrameShape(QFrame::NoFrame);
}

TestListView::~TestListView()
{}
