#pragma once

#include <QtWidgets/QDialog>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QMouseEvent>
#include "ui_TestListView.h"
#include <QCheckBox>
#include <QScrollBar>

class CustomItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	CustomItemDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
	{
		painter->save();

		// ���ÿ����
		painter->setRenderHint(QPainter::Antialiasing, true);

		// �Զ�����ƴ���
		QRect rect = option.rect.adjusted(5, 5, -5, -5); // �������������������
		painter->setPen(Qt::gray);
		// ����Բ�Ǿ���
		painter->drawRoundedRect(rect, 10, 10);

		// ����ͼ��
		QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
		QRect iconRect = rect.adjusted(10, 10, -rect.width() + 30, -10);
		icon.paint(painter, iconRect);

		// ��������
		QRect textRect = rect.adjusted(40, 10, -10, -10);
		painter->drawText(textRect, Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

		// ��ȡ�����ƴ洢��item data�еĿؼ�
		QWidget* widget = qvariant_cast<QWidget*>(index.data(Qt::UserRole + 1));
		if (widget)
		{
			widget->setGeometry(option.rect.adjusted(150, 10, -10, -10));
			widget->render(painter, widget->pos(), QRegion(), QWidget::DrawChildren);
		}

		painter->restore();
	}

	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override
	{
		return QSize(200, 80); // �Զ���Item��С
	}

	//QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override
	//{
	//	QCheckBox* checkBox = new QCheckBox(parent);
	//	return checkBox;
	//}

	//void setEditorData(QWidget* editor, const QModelIndex& index) const override
	//{
	//	bool checked = index.data(Qt::UserRole).toBool();
	//	QCheckBox* checkBox = static_cast<QCheckBox*>(editor);
	//	checkBox->setChecked(checked);
	//}

	//void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override
	//{
	//	QCheckBox* checkBox = static_cast<QCheckBox*>(editor);
	//	model->setData(index, checkBox->isChecked(), Qt::UserRole);
	//}

	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override
	{
		editor->setGeometry(option.rect.adjusted(150, 10, -10, -10));
	}

signals:
	void itemClicked(const QModelIndex& index) const;

private:
	QSize m_szItem;
	QRect m_rcIcon;
	QRect m_rcAuthor;
	QRect m_rcMenuBtn;
	QRect m_rcSubject;
	QRect m_rcSubject;
	QRect m_rcCheckBox;
	QRect m_rcDateTime;
};

class TestListView : public QDialog
{
    Q_OBJECT

public:
    TestListView(QWidget *parent = nullptr);
    ~TestListView();

private:
    Ui::TestListViewClass ui;
};
