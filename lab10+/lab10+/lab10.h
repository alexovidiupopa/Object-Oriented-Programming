#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab10.h"
#include "Controller.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>

class lab10 : public QWidget
{
	Q_OBJECT

public:
	lab10(const Controller &ctrl,QWidget *parent = 0);
	~lab10() {};
	
private:
	Ui::lab10Class ui;
	Controller controller;

	QListWidget* tapesListWidget;
	QListWidget* playlistWidget;

	QLineEdit * titleInput;
	QLineEdit * filmedAtInput;
	QLineEdit * creationDateInput;
	QLineEdit * accessCountInput;
	QLineEdit * previewInput;

	QPushButton* modeAButton;
	QPushButton* modeBButton;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* undoButton;
	QPushButton* redoButton;
	QPushButton* saveButton;
	QPushButton* filterButton;
	QPushButton* play;
	QPushButton* next;
	QPushButton* exitButton;
	std::vector<Tape> tapesListVector;
	void initializeInterface();
	void populateRepositoryBox();
	void connectSignalsAndSlots();
	void populateWithFilter();
	void disableModeAButtons();
	void disableModeBButtons();
	void enableModeAButtons();
	void enableModeBButtons();
	int indexForTapesIteration;

private slots:
	void enableModeA();
	void enableModeB();
	void moveTapeToPlaylist();
	void deleteTape();
	void updateTape();
	void undo();
	void redo();
	void filterTapes();
	void populatePlaylist();
	void addTape();
	void nextTape();
	void playTapes();
	void exit();
};
