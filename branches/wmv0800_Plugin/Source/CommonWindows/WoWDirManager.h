#ifndef WOWDIRMANAGER_H
#define WOWDIRMANAGER_H

#include "../Engine/wmv_engine.h"

#include <QDir>
#include <QListWidget>
#include "GeneratedFiles/ui_WDM_Main.h"
#include "GeneratedFiles/ui_WDM_Edit.h"
#include "../Engine/classes.h"

class QAbstractItemModel;
class QItemSelectionModel;

namespace WMVEngine {

class WDM_Edit : public QDialog
{
	Q_OBJECT

public:
	explicit WDM_Edit(QWidget *parent = 0);
	~WDM_Edit();
	void init();

private slots:
	void on_btn_Okay_clicked();
	void on_btn_Cancel_clicked() {
		QDialog::close();
	}

private:
	Ui::WDM_Edit *ui_WDM_Edit;
};

class WoWDirManager : public QDialog
{
	Q_OBJECT

public:
	// Public Functions
    WMV_ENGINE_API explicit WoWDirManager(QWidget *parent = 0);
	WMV_ENGINE_API ~WoWDirManager();
	WMV_ENGINE_API void init();

private:
	void SetupList();
	void UpdateList();
	
	/*
	// Icons
	QIcon icon01Vanilla;
	QIcon icon02TBC;
	QIcon icon03WotLK;
	QIcon icon04Cata;
	QIcon icon05MoP;
	QIcon iconPTR;

	QString selected;		// The Selected WoWDir's name
	*/
	QListWidget *List;

	// SubWindows
	WDM_Edit Window_WDMEdit;

	void saveDir(st_WoWDir,bool);				// Save the Directory
	void ListOffset(int);
	template <class UnReal, class Real>
	void ReOrderList(UnReal, Real);				// Re-orders the WoW list

private slots:
	void on_WDM_bDirMakeCurrent_clicked();
	void on_WDM_bDirAdd_clicked();
	void on_WDM_bDirEdit_clicked();
	void on_WDM_bDirUp_clicked();
	void on_WDM_bDirDown_clicked();
	void on_WDM_bDirDeleteAll_clicked();
	void on_buttonBox_Cancel_clicked() {
		QDialog::close();
	}
private:
	Ui::WoWDirManager *ui_WoWDirManager;
};

st_WoWDir ScanWoWDir(QDir, int, int);

} // Namespace

#endif