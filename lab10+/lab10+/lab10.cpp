#include "lab10.h"
#include <sstream>
lab10::lab10(const Controller& ctrl,QWidget *parent)
	: QWidget(parent), controller{ctrl}
{
	//QMainWindow(parent);
	//ui.setupUi(this);
	//this->controller = ctrl;
	this->initializeInterface();
	this->tapesListVector = this->controller.listTapes();
	this->populateRepositoryBox();
	QSize size(1000, 1000);
	this->setFixedSize(size);
	this->indexForTapesIteration = 0;
	this->controller.initializeIndex();
	
}

void lab10::initializeInterface()
{
	//main layout
	QHBoxLayout* layout = new QHBoxLayout{ this };

	//left part of the layout
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//where tapes are displayed
	this->tapesListWidget = new QListWidget{};
	this->tapesListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	//create a separate widget for the tape data
	QWidget* TapeDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ TapeDataWidget };

	//input boxes for the tape fields
	this->titleInput = new QLineEdit{};
	this->filmedAtInput = new QLineEdit{};
	this->creationDateInput = new QLineEdit{};
	this->accessCountInput = new QLineEdit{};
	this->previewInput = new QLineEdit{};

	//labels for the tape input fields
	//and add them to the form layout
	formLayout->addRow("Title:", titleInput);
	formLayout->addRow("Filmed at:", filmedAtInput);
	formLayout->addRow("Creation date:", creationDateInput);
	formLayout->addRow("Access count:", accessCountInput);
	formLayout->addRow("Preview:", previewInput);

	//left side buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	this->filterButton = new QPushButton{ "Filter" };
	this->exitButton = new QPushButton{ "Exit" };
	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(undoButton, 1, 0);
	gridLayout->addWidget(filterButton, 1, 1);
	gridLayout->addWidget(redoButton, 1, 2);
	gridLayout->addWidget(exitButton, 2, 1);

	//add everything to the left side
	leftSide->addWidget(new QLabel{ "Tapes database" });
	leftSide->addWidget(tapesListWidget);
	leftSide->addWidget(TapeDataWidget);
	leftSide->addWidget(buttonsWidget);


	//middle button
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* verticalLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->modeAButton = new QPushButton{ "Mode A" };
	this->modeBButton = new QPushButton{ "Mode B" };
	this->saveButton = new QPushButton{ "Save" };
	verticalLayoutMiddle->addWidget(modeAButton);
	verticalLayoutMiddle->addWidget(modeBButton);
	verticalLayoutMiddle->addWidget(saveButton);


	//right side
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };
	
	//playlist widget
	this->playlistWidget = new QListWidget{};
	
	//buttons for the playlist
	QWidget* playlistButtonsWidget = new QWidget{};
	QHBoxLayout* playlistButtonsLayout = new QHBoxLayout{ playlistButtonsWidget };
	this->play = new QPushButton{ "Open" };
	this->next = new QPushButton{ "Next" };
	playlistButtonsLayout->addWidget(play);
	playlistButtonsLayout->addWidget(next);


	//add everything to the right side
	rightSide->addWidget(new QLabel{ "Playlist" });
	rightSide->addWidget(playlistWidget);
	this->playlistWidget->setDisabled(true);
	rightSide->addWidget(playlistButtonsWidget);

	//add everything to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	//connect the buttons with the respective events
	this->connectSignalsAndSlots();

	this->disableModeAButtons();
	this->disableModeBButtons();
}

void lab10::populateRepositoryBox()
{
	tapesListWidget->clear();
	for (auto tape : tapesListVector) {
		QString listItem = QString::fromStdString(tape.toString());
		QListWidgetItem *listItemWidget = new QListWidgetItem(listItem);
		this->tapesListWidget->addItem(listItemWidget);
	}
	//tapesListWidget->setCurrentRow(0);
}


void lab10::populatePlaylist()
{
	playlistWidget->clear();
	for (auto tape : this->controller.listPlaylist()) {
		QString listItem = QString::fromStdString(tape.toString());
		QListWidgetItem *listItemWidget = new QListWidgetItem(listItem);
		this->playlistWidget->addItem(listItemWidget);
	}
}

void lab10::enableModeA()
{
	this->disableModeBButtons();
	this->enableModeAButtons();
}

void lab10::enableModeB()
{
	this->disableModeAButtons();
	this->enableModeBButtons();
}

void lab10::moveTapeToPlaylist()
{
    controller.saveToPlaylist(this->controller.listTapes()[this->indexForTapesIteration -1].getTitle());
	this->populatePlaylist();
}

void lab10::addTape()
{
	std::string title = titleInput->text().toStdString();
	std::string filmedAt = filmedAtInput->text().toStdString();
	std::string creationDate = creationDateInput->text().toStdString();
	int accessCount;
	try {
		accessCount = std::stoi(accessCountInput->text().toStdString());
	}
	catch (std::invalid_argument& invalidArgument)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
		return;
	}
	
	std::string preview = previewInput->text().toStdString();
	std::string tapeString = title + "," + filmedAt + "," + creationDate + "," + std::to_string(accessCount) + "," + preview;

	std::stringstream stream{ tapeString };
	try
	{
		Tape tape;
		stream >> tape;
		controller.addTape(tape.getTitle(), tape.getFilmedAt(), tape.getCreationDate(), tape.getFootagePreview(), tape.getAccessCount());
		tapesListVector = this->controller.listTapes();
		this->populateRepositoryBox();
	}
	catch (ValidatorException& validatorException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& repositoryException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Tape already exists!"));
	}

}


void lab10::deleteTape()
{
	std::string title = titleInput->text().toStdString();
	try
	{
		controller.removeTape(title);
		tapesListVector = this->controller.listTapes();
		this->populateRepositoryBox();
	}
	catch (ValidatorException& validatorException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid title!"));
	}
	catch (RepositoryException& repositoryException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Tape doesn't exist!"));
	}
}

void lab10::updateTape()
{
	std::string title = titleInput->text().toStdString();
	std::string filmedAt = filmedAtInput->text().toStdString();
	std::string creationDate = creationDateInput->text().toStdString();
	int accessCount;
	try {
		accessCount = std::stoi(accessCountInput->text().toStdString());
	}
	catch(std::invalid_argument& invalidArgument)
	{ 
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
		return;
	}
	std::string preview = previewInput->text().toStdString();
	std::string tapeString = title + ", " + filmedAt + ", " + creationDate + ", " + std::to_string(accessCount) + ", " + preview;

	std::stringstream stream{ tapeString };
	try
	{
		Tape tape;
		stream >> tape;
		controller.updateTape(tape.getTitle(), tape.getFilmedAt(), tape.getCreationDate(), tape.getFootagePreview(), tape.getAccessCount());
		tapesListVector = this->controller.listTapes();
		this->populateRepositoryBox();
	}
	catch (ValidatorException& validatorException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& repositoryException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Tape already exists!"));
	}
}

void lab10::undo()
{
	try
	{
		this->controller.undo();
		this->tapesListVector = this->controller.listTapes();
		this->populateRepositoryBox();
	}
	catch (std::runtime_error()){

	}
}

void lab10::redo()
{
}

void lab10::filterTapes()
{
	std::string filmedAt = filmedAtInput->text().toStdString();
	int accessCount;
	try {
		accessCount = std::stoi(accessCountInput->text().toStdString());
	}
	catch (std::invalid_argument& invalidArgument)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
		return;
	}
	std::vector<Tape> filteredTapes = this->controller.listTapesFilmedAtLessThanCount(filmedAt, accessCount);
	QMessageBox messageBox;
	std::string filteredString;
	for (auto tape : filteredTapes) {
		filteredString += tape.toString();
	}
	messageBox.information(0, "Filtering result", QString::fromStdString(filteredString));
}

void lab10::connectSignalsAndSlots()
{
	QObject::connect(tapesListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	
	//connect all the buttons with the functions to be executed when clicked on
	QObject::connect(this->modeAButton, SIGNAL(clicked()), this, SLOT(enableModeA()));
	QObject::connect(this->modeBButton, SIGNAL(clicked()), this, SLOT(enableModeB()));
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addTape()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTape()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateTape()));
	QObject::connect(this->undoButton, SIGNAL(clicked()), this, SLOT(undo()));
	QObject::connect(this->redoButton, SIGNAL(clicked()), this, SLOT(redo()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterTapes()));
	QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(playTapes()));
	QObject::connect(this->next, SIGNAL(clicked()), this, SLOT(nextTape()));
	QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(moveTapeToPlaylist()));
	QObject::connect(this->exitButton, SIGNAL(clicked()), this, SLOT(exit()));
}
void lab10::populateWithFilter()
{
}
void lab10::disableModeAButtons()
{
	this->addButton->setDisabled(true);
	this->deleteButton->setDisabled(true);
	this->updateButton->setDisabled(true);
	this->undoButton->setDisabled(true);
	this->redoButton->setDisabled(true);
}

void lab10::disableModeBButtons()
{
	this->next->setDisabled(true);
	this->filterButton->setDisabled(true);
	this->play->setDisabled(true);
	this->saveButton->setDisabled(true);
}
void lab10::enableModeAButtons()
{
	this->addButton->setDisabled(false);
	this->deleteButton->setDisabled(false);
	this->updateButton->setDisabled(false);
	this->undoButton->setDisabled(false);
	this->redoButton->setDisabled(false);
}
void lab10::enableModeBButtons()
{
	this->next->setDisabled(false);
	this->filterButton->setDisabled(false);
	this->play->setDisabled(false);
	this->saveButton->setDisabled(false);
}
void lab10::nextTape()
{
	if (this->indexForTapesIteration == this->tapesListVector.size())
		this->indexForTapesIteration = 0;
	this->tapesListWidget->setCurrentRow(this->indexForTapesIteration++);
}

void lab10::playTapes()
{
	this->controller.openPlaylist();
}

void lab10::exit()
{
	QApplication::exit();
}
