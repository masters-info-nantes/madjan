/**
 * @file gui.cpp
 * @brief Gui class definition
 * @author nicolas
 * @version 0.1
 */

#include "gui.h"

Gui::Gui()
    : QWidget()
{

    this->controler = new Controler();

    //Create and connect the timer to the controler
    this->playTimer = new QTimer();
    QObject::connect(this->playTimer,SIGNAL(timeout()),this,SLOT(nextGeneration()));

    //Create and add the layout to the main window
    this->mainLayout = new QGridLayout();
    this->setLayout(this->mainLayout);

    this->zoom = 2;

    // Menu //

    this->menu = new QMenuBar();
    this->mainLayout->addWidget(this->menu,0,0,1,4);
    this->pluginMenu = new QMenu("Plugins");
    this->helpMenu = new QMenu("Help");
    this->menu->addMenu(this->pluginMenu);
    this->menu->addMenu(this->helpMenu);


        // Plugin Menu //

    //Go through the whole plugin list and add them to the plugin menu

    if(this->controler->getPluginManager()->getPlugins()->size()==0)
    {
        QMessageBox* message = new QMessageBox(0);
        message->setWindowTitle("Error");
        message->setText("No plugin found, check your plugin folder.<br> Close the application and restart it.");
        message->exec();
    }
    else
    {
        for(int i=0; i< this->controler->getPluginManager()->getPlugins()->size();i++)
        {
            QAction* action = new QAction(this->controler->getPluginManager()->getPlugins()->at(i)->getName(),this->pluginMenu);
            this->pluginMenu->addAction(action);
            QObject::connect(action,SIGNAL(triggered()),this,SLOT(changePlugin()));
        }

            // Help Menu //

        QAction* aboutAction = new QAction("About",this->helpMenu);
        QObject::connect(aboutAction,SIGNAL(triggered()),this,SLOT(showAbout()));
        QAction* docAction = new QAction("User Documentation",this->helpMenu);
        QObject::connect(docAction,SIGNAL(triggered()),this,SLOT(showDocumentation()));
        this->helpMenu->addAction(aboutAction);
        this->helpMenu->addAction(docAction);

        // Play Pause Menu //

        this->playMenu = new QWidget();
        this->playMenuLayout = new QGridLayout();
        this->playMenu->setLayout(playMenuLayout);

        this->widthEdit = new QLineEdit();
        this->widthEdit->setText(QString::number(this->controler->getCurrentGrid()->getWidth()));
        this->widthEdit->setPlaceholderText("Width");

        this->heightEdit = new QLineEdit();
        this->heightEdit->setText(QString::number(this->controler->getCurrentGrid()->getHeight()));
        this->heightEdit->setPlaceholderText("Height");

        this->applySizeButton = new QPushButton("Apply");
        QObject::connect(this->applySizeButton,SIGNAL(clicked()),this,SLOT(changeGridSize()));

        this->playButton = new QPushButton("Play");
        QObject::connect(this->playButton,SIGNAL(clicked()),this,SLOT(play()));

        this->pauseButton = new QPushButton("Pause");
        QObject::connect(this->pauseButton,SIGNAL(clicked()),this,SLOT(pause()));
        this->pauseButton->hide(); //The pause button is hidden by default and is shown when you click the play button

        this->nextButton = new QPushButton("Next");
        QObject::connect(this->nextButton,SIGNAL(clicked()),this,SLOT(nextGeneration()));

        this->randomButton = new QPushButton("Edit");
        QObject::connect(this->randomButton,SIGNAL(clicked()),this,SLOT(showRandomWindow()));

        this->zoomSlider = new QSlider();
        this->zoomSlider->setOrientation(Qt::Horizontal);
        this->zoomSlider->setRange(1,100);
        this->zoomSlider->setValue(this->zoom);
        QObject::connect(this->zoomSlider,SIGNAL(valueChanged(int)),this,SLOT(setZoom(int)));

        this->generationLabel = new QLabel("0");

        this->playMenuLayout->addWidget(new QLabel("Width:"),0,0,1,1);
        this->playMenuLayout->addWidget(this->widthEdit,0,1,1,1);
        this->playMenuLayout->addWidget(new QLabel("Height:"),0,2,1,1);
        this->playMenuLayout->addWidget(this->heightEdit,0,3,1,1);
        this->playMenuLayout->addWidget(this->applySizeButton,0,4,1,2);
        this->playMenuLayout->addWidget(randomButton,1,0,1,2);
        this->playMenuLayout->addWidget(playButton,1,2,1,2);
        this->playMenuLayout->addWidget(pauseButton,1,2,1,2);
        this->playMenuLayout->addWidget(nextButton,1,4,1,2);
        this->playMenuLayout->addWidget(new QLabel("Zoom:"),2,0,1,1);
        this->playMenuLayout->addWidget(this->zoomSlider,2,1,1,3);
        this->playMenuLayout->addWidget(new QLabel("Generation: "),2,4,1,1);
        this->playMenuLayout->addWidget(this->generationLabel,2,5,1,1);
        this->mainLayout->addWidget(this->playMenu,1,0,1,3);

        // Random Window //

        createRandomWindow();

        // Cell Menu //

        updatePawnButtons();

        // Canvas //

        this->scrollArea = new QScrollArea();
        this->layoutContainer = new QWidget();
        this->layoutContainer->setStyleSheet("border:1px solid black;");
        this->canvasLayout = new QGridLayout();
        this->cells = new QVector<QVector<GuiCell*>*>();

        this->scrollArea->setWidgetResizable(true);
        this->scrollArea->setWidget(this->layoutContainer);
        this->layoutContainer->setLayout(this->canvasLayout);
        this->canvasLayout->setHorizontalSpacing(0);
        this->canvasLayout->setVerticalSpacing(0);
        this->canvasLayout->setMargin(0);
        this->canvasLayout->setContentsMargins(0,0,0,0);
        this->mainLayout->addWidget(this->scrollArea,2,1,1,1);

        this->initGrid(this->controler->getCurrentGrid()->getWidth(),this->controler->getCurrentGrid()->getHeight(),true);
    }
}

Gui::~Gui()
{

}

void Gui::setZoom(int value)
{
    this->zoom = value;
    //Resizing each cells one by one
    for(int i = 0; i<this->cells->size();i++)
    {
        for(int j = 0; j<this->cells->at(i)->size();j++)
        {
            this->cells->at(i)->at(j)->setFixedSize(zoom*10,zoom*10);
        }
    }
   //Resizing the layout container to avoid useless margin between cells
   //this->layoutContainer->setFixedSize(this->cells->size()*zoom*10,this->cells->at(0)->size()*zoom*10);
}

void Gui::changePawn()
{
    if(this->controler->getCurrentPawn()!=0)
    {
        GuiCell* cell = dynamic_cast<GuiCell*>(sender());
        //change the graphical pawn
        cell->setPawnImage(this->controler->getCurrentPawn()->getId());
        //change the pawn in the model
        this->controler->getCurrentGrid()->getCell(cell->getX(),cell->getY())->setPawn(this->controler->getCurrentPawn());
    }
}

void Gui::changePlugin()
{
    QAction* action = dynamic_cast<QAction*>(sender());
    this->controler->changeCurrentPlugin(action->text());
    updatePawnButtons();
    //Update the random window with the pawns of the current plugin
    createRandomWindow();
    initGrid(this->widthEdit->text().toInt(),this->heightEdit->text().toInt());
}

void Gui::initGrid(int width, int height, bool deleteGuiCell)
{
    if(this->cells->size()>0)
    {
        this->clearGrid(deleteGuiCell);
    }
    //create each cell of the grid
    for(int i = 0; i<height;i++)
    {
        this->cells->push_back(new QVector<GuiCell*>());
        for(int j = 0; j<width;j++)
        {
            GuiCell* cell = new GuiCell(j,i,this->imageManager);
            cell->setPawnImage(this->controler->getCurrentGrid()->getCell(j,i)->getPawn()->getId());
            cell->setFixedSize(zoom*10,zoom*10);
            QObject::connect(cell,SIGNAL(clicked()),this,SLOT(changePawn()));
            this->cells->at(i)->push_back(cell);
            this->canvasLayout->addWidget(cell,i,j);
        }
    }
    //Resizing the layout container to avoid useless margin between cells
    //this->layoutContainer->setFixedSize(this->cells->size()*zoom*10,this->cells->at(0)->size()*zoom*10);
}

void Gui::clearGrid(bool deleteGuiCell)
{
	QVector<QVector<GuiCell*>*>::iterator it_niv1;
	QVector<GuiCell*>::iterator it_niv2;
    for(it_niv1=this->cells->begin();it_niv1!=this->cells->end();it_niv1++)
    {
		if(deleteGuiCell)
		{
			for(it_niv2=(*it_niv1)->begin();it_niv2!=(*it_niv1)->end();it_niv2++)
			{
				if(*it_niv2 != NULL)
					delete *it_niv2;
			}
		}
		//~ (*it_niv1)->clear();
	}
    this->cells->clear();
    
    for(int i = 0; i<this->canvasLayout->rowCount();i++)
    {
        for(int j = 0; j<this->canvasLayout->columnCount();j++)
        {
            //Clear the canvas layout
            QWidget* widget = this->canvasLayout->itemAtPosition(i,j)->widget();
            this->canvasLayout->removeItem(this->canvasLayout->itemAtPosition(i,j));
            delete this->canvasLayout->itemAtPosition(i,j);
            delete widget;
        }
    }
    delete this->canvasLayout;
    this->canvasLayout = new QGridLayout();

    this->layoutContainer->setLayout(this->canvasLayout);
    this->canvasLayout->setHorizontalSpacing(0);
    this->canvasLayout->setVerticalSpacing(0);
    this->canvasLayout->setMargin(0);
    this->canvasLayout->setContentsMargins(0,0,0,0);

}

void Gui::refreshGrid()
{
    this->generationLabel->setText(QString::number(this->controler->getFrame()));
    //Refresh each pawn in each cell
    for(int i = 0; i<this->controler->getCurrentGrid()->getHeight();i++)
    {
        for(int j = 0; j<this->controler->getCurrentGrid()->getWidth();j++)
        {
            GuiCell* cell = dynamic_cast<GuiCell*>(this->canvasLayout->itemAtPosition(i,j)->widget());
            cell->setPawnImage(this->controler->getCurrentGrid()->getCell(j,i)->getPawn()->getId());
        }
    }
}

void Gui::updatePawnButtons()
{
    //Recreate the gui part where the pawns buttons are (left)
    this->cellScrollArea = new QScrollArea();
    this->cellScrollWrapper = new QWidget();
    this->cellScrollLayout = new QGridLayout();
    this->cellButtons = new QVector<GuiButton*>();
    this->cellScrollArea->setWidgetResizable(true);
    this->mainLayout->addWidget(cellScrollArea,2,0,1,1);
    this->cellScrollArea->setWidget(cellScrollWrapper);
    this->cellScrollWrapper->setLayout(cellScrollLayout);
    QVector<Pawn*>::iterator pawnIt;
    int pawnIndex=0;
    for(pawnIt= this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->begin(); pawnIt!=this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->end();pawnIt++,pawnIndex++)
    {
        GuiButton* butt = new GuiButton((*pawnIt)->getName(),pawnIndex);
        QObject::connect(butt,SIGNAL(click(int)),this->controler,SLOT(setCurrentPawn(int)));
        this->cellButtons->push_back(butt);
        this->cellScrollLayout->addWidget(butt);
    }
    //Update the pawns images stored in the image manager
    this->imageManager = new GuiImageManager(this->controler->getPluginManager()->getCurrentPlugin()->getPawns());
}

void Gui::play()
{
    this->playTimer->start(500);
    this->pauseButton->show();
    this->playButton->hide();
}

void Gui::pause()
{
    this->playTimer->stop();
    this->pauseButton->hide();
    this->playButton->show();
}

void Gui::changeGridSize()
{
    this->controler->changeGridSize(this->widthEdit->text().toInt(),this->heightEdit->text().toInt());
    this->initGrid(this->widthEdit->text().toInt(),this->heightEdit->text().toInt(),false);
}

void Gui::showRandomWindow()
{
    this->randomWindow->show();
}

void Gui::createRandomWindow()
{
    this->pawnPourcentages = new QList<QLineEdit*>();
    this->pawnPourcentagesFinish = new QList<QLineEdit*>();
    this->randomWindow = new QWidget();
    this->randomWindow->setWindowTitle("Edit");
    this->randomWindow->setWindowModality(Qt::ApplicationModal);
    this->randomWidth = new QLineEdit(this->widthEdit->text());
    this->randomHeight = new QLineEdit(this->heightEdit->text());
    QPushButton* generate = new QPushButton("Generate");

    QGridLayout* randomWindowLayout = new QGridLayout();

    this->randomWindow->setLayout(randomWindowLayout);

    randomWindowLayout->addWidget(new QLabel("Creation"),0,1);
    randomWindowLayout->addWidget(new QLabel("Stop Conditions"),0,2);
    randomWindowLayout->addWidget(new QLabel("Width:"),1,0);
    randomWindowLayout->addWidget(this->randomWidth,1,1);
    randomWindowLayout->addWidget(new QLabel("Height:"),2,0);
    randomWindowLayout->addWidget(this->randomHeight,2,1);
    int indexRandomPercentage = 3;
    QVector<Pawn*>::iterator pawnIt;
    for(pawnIt= this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->begin()+1; pawnIt!=this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->end();pawnIt++,indexRandomPercentage++)
    {
        QLabel* label = new QLabel((*pawnIt)->getName());
        QLineEdit* edit = new QLineEdit();
        edit->setPlaceholderText("5");
        QLineEdit* editFinish = new QLineEdit();
        editFinish->setPlaceholderText("<25");

        this->pawnPourcentages->push_back(edit);
        this->pawnPourcentagesFinish->push_back(editFinish);
        randomWindowLayout->addWidget(label,indexRandomPercentage,0);
        randomWindowLayout->addWidget(edit,indexRandomPercentage,1);
        randomWindowLayout->addWidget(editFinish,indexRandomPercentage,2);
    }
    randomWindowLayout->addWidget(new QLabel("Generation: "),indexRandomPercentage+1,0);
    this->generationFinish = new QLineEdit();
    randomWindowLayout->addWidget(this->generationFinish,indexRandomPercentage+1,2);
    randomWindowLayout->addWidget(generate,indexRandomPercentage+2,0,1,3);

    QObject::connect(generate,SIGNAL(clicked()),this,SLOT(generateRandomGrid()));
    QObject::connect(generate,SIGNAL(clicked()),this->randomWindow,SLOT(close()));
}

void Gui::generateRandomGrid()
{
    QMap<Pawn*,unsigned int>* data = new QMap<Pawn*,unsigned int>();
    QMap<Pawn*, QString>* stop = new QMap<Pawn*, QString>();
    for(int i=0;i<this->pawnPourcentages->size();i++)
    {
        if(this->pawnPourcentages->at(i)->text()!="")
            data->insert(this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->at(i+1),this->pawnPourcentages->at(i)->text().toUInt());
    }
    for(int i=0;i<this->pawnPourcentagesFinish->size();i++)
    {
        if(this->pawnPourcentagesFinish->at(i)->text()!="")
            stop->insert(this->controler->getPluginManager()->getCurrentPlugin()->getPawns()->at(i+1),this->pawnPourcentagesFinish->at(i)->text());
    }
    if(data->size()==0)
        data=NULL;
    if(stop->size()==0)
        stop=NULL;
    int generationStop;
    if(this->generationFinish->text()=="")
        generationStop=NULL;
    else
        generationStop=this->generationFinish->text().toInt();
    if(this->controler->generateGrid(data,stop,generationStop,this->randomWidth->text().toInt(),this->randomHeight->text().toInt()))
    {
        this->initGrid(this->randomWidth->text().toInt(),this->randomHeight->text().toInt());
        this->refreshGrid();
        this->widthEdit->setText(this->randomWidth->text());
        this->heightEdit->setText(this->randomHeight->text());
        qDebug("Random grid generation!!!");
    }
    else
    {
        QMessageBox* message = new QMessageBox(0);
        message->setWindowTitle("Error Bad Pourcentages");
        message->setText("The sum of all pourcentages must be less or equal to 100%");
        message->exec();
    }

}

void Gui::showDocumentation()
{
    QDir* doc = new QDir("../doc/manuel/");
    QDesktopServices::openUrl(QUrl("file://"+doc->absolutePath()+"/manuel-Madjan.pdf"));
}

void Gui::showAbout()
{
    QMessageBox* window = new QMessageBox(0);
    window->setWindowTitle("About");
    window->setText("Developed by Adrien Garandel, Anthony Pena,<br>Jeremy Bardon, Maxime Pauvert and Nicolas Brondin<br> within the University of Nantes");
    window->show();
}

void Gui::nextGeneration()
{
    if(this->controler->nextFrame())
        this->refreshGrid();
}

