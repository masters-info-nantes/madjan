#include "controler.h"
#include "time.h"

Controler::Controler()
{
    /* initialize random seed: */
     srand (time(NULL));
    this->pawnStop = NULL;
    this->pluginManager = new PluginManager();
    this->currentPawn = 0;
     this->maxGenerations=0;
     if(this->pluginManager->getCurrentPlugin()!=0)
     {
    generateGrid(new QMap<Pawn*, unsigned int>(), NULL, NULL, 15,15);

    this->currentGrid->debugDisplay();
     }
}

PluginManager *Controler::getPluginManager()
{
    return this->pluginManager;
}

bool Controler::generateGrid(QMap<Pawn*, unsigned int>* pawnPartition, QMap<Pawn*, QString>* pawnStop, int generations, int width, int height)
{
    this->maxGenerations=generations;
    if (pawnPartition != NULL) {
        this->frame=0;
        { // Check sum of percent
            int sum = 0;
            for(QMap<Pawn*, unsigned int>::iterator it = pawnPartition->begin(); it != pawnPartition->end(); it++) {
                sum += it.value();
            }
            if (sum > 100) {
                return false;
            }
        }

        { // Reset Grid
            //delete this->currentGrid;

            this->currentGrid = new Grid(width, height);
            if (!this->currentGrid) {
                return false;
            }
        }


        { // new content of grid
            for (int w = 0; w < this->currentGrid->getWidth(); ++w) {
                for (int h = 0; h < this->currentGrid->getHeight(); ++h) {
                    /*
                     * chose a number beetween 0-99
                     * because if random == 100 and sum == 100 we create an empty pawn.
                     */
                    int random = rand() % 100;
                    int sum = 0;
                    for(QMap<Pawn*, unsigned int>::iterator it = pawnPartition->begin(); it != pawnPartition->end() && sum < 100; it++) {
                        sum += it.value();
                        if (random < sum) { // if sum == 0 don't create any pawn because we don't want it
                            this->currentGrid->getCell(w, h)->setPawn(it.key());
                            // replace it.key() by pluginManager->getCurrentPlugin()->getPawn(it.key) if QString key

                            // Stop loop
                            sum = INT_MAX;
                        }
                    }
                    if (sum < 100) { // empty pawn
                        this->currentGrid->getCell(w, h)->setPawn(pluginManager->getCurrentPlugin()->getPawn("empty"));
                    }
                }
            }
        }
    }
    if (pawnStop != NULL) {
        this->pawnStop = pawnStop;
    }

    return true;
}

void Controler::changeCurrentPlugin(QString text)
{
    for(int i=0;i<this->pluginManager->getPlugins()->size();i++)
    {
        if(this->pluginManager->getPlugins()->at(i)->getName()==text)
        {
            qDebug(text.toUtf8());
            this->pluginManager->setCurrentPlugin(i);
        }
    }
}

void Controler::setCurrentPawn(int index)
{
    this->currentPawn = this->pluginManager->getCurrentPlugin()->getPawns()->at(index);
}

void Controler::setCurrentPlugin(int index)
{
    this->pluginManager->setCurrentPlugin(index);
}
Pawn* Controler::getCurrentPawn()
{
    return this->currentPawn;
}

Grid* Controler::getCurrentGrid()
{
    return this->currentGrid;
}

void Controler::changeGridSize(int width, int height)
{
    this->frame=0;
    if(width>0&&height>0)
    {
        this->currentGrid = new Grid(width,height);
    }
    else
    {
        qDebug("Wrong grid size");
    }

}

#include <QDebug>

bool Controler::nextFrame(){
    if((this->maxGenerations==NULL||this->frame<this->maxGenerations)&&this->checkStepDistribution())
    {

        Grid* oldGrid = this->currentGrid->clone();
        Plugin* plugin = this->pluginManager->getCurrentPlugin();

        // All operations are in oldGrid because plugin rules
        // musn't be applied to new grid in constrution
        for(int line = 0; line < oldGrid->getHeight(); line++){
            for(int col = 0; col < oldGrid->getWidth(); col++){
               Cell* currentCell = oldGrid->getCell(col, line);
               QVector<Pawn*>* neighbors = oldGrid->getCellNeighbors(col, line);

               Pawn* newPawn = plugin->getNewPawn(currentCell->getPawn(), neighbors);
               this->currentGrid->getCell(col, line)->setPawn(newPawn);
            }
        }

        this->frame++;
        this->currentGrid->debugDisplay();
        return true;
    }

    return false;
}

int Controler::getFrame()
{
    return this->frame;
}

QMap<Pawn*, double>* Controler::getDistribution() {
    QMap<Pawn*, double>* distribution = new QMap<Pawn*, double>();
    for(int i = 0; i < this->pluginManager->getCurrentPlugin()->getPawns()->size(); i++){
        distribution->insert(this->pluginManager->getCurrentPlugin()->getPawns()->at(i),0);
    }
    Grid* grid = this->getCurrentGrid();
    double percent = 100.0/(grid->getHeight()*grid->getWidth());
    for(int line = 0; line < grid->getHeight(); line++){
        for(int col = 0; col < grid->getWidth(); col++){
             distribution->insert(grid->getCell(col, line)->getPawn(), distribution->value(grid->getCell(col, line)->getPawn())+percent);
        }
    }
    return distribution;
}

bool Controler::checkStepDistribution() {
    if(this->pawnStop != NULL) {
        QMap<Pawn*, double>* distribution = this->getDistribution();
        for(QMap<Pawn*, QString>::iterator it = pawnStop->begin(); it != pawnStop->end(); it++) {
            if(it.value().size() > 2) { // if there is at least one operator and one number
                int a = it.value().mid(1).toInt(); // value of input
                QChar *op = new QChar(it.value().at(0)); // input operator

                for(QMap<Pawn*, double>::iterator it2 = distribution->begin(); it2 != distribution->end(); it2++) {
                    if(it.key() == it2.key()) {
                        if(*op == QChar('>')) {
                            if(it2.value()>=a)
                                return false;
                        }
                        if(*op == QChar('<')) {
                            if(it2.value()<=a)
                                return false;
                        }
                    }

                }

            }
        }
    }
    return true;
}
