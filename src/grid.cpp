/**
 * @file Grid.cpp
 * @brief Grid class definition
 * @author jeremy
 * @version 0.1
 */

#include "grid.h"
#include <QDebug>

Grid::Grid(int width, int height)
    : height(height), width(width)
{
    this->content = new QVector<QVector<Cell*>*>();
    for(int line = 0; line < height; line++){
        QVector<Cell*>* lineContent = new QVector<Cell*>();
        for(int col = 0; col < width; col++){
            Cell* cell = new Cell(new Pawn("empty","Empty","../plugins/test/img/img.jpg"));
            lineContent->push_back(cell);
        }
        this->content->push_back(lineContent);
    }
}

Grid::~Grid()
{
	if(this->content == NULL)
		return;
	QVector<QVector<Cell*>*>::iterator it_niv1;
	QVector<Cell*>::iterator it_niv2;
    for(it_niv1=this->content->begin();it_niv1!=this->content->end();it_niv1++)
    {
		if((*it_niv1) != NULL)
		{
			for(it_niv2=(*it_niv1)->begin();it_niv2!=(*it_niv1)->end();it_niv2++)
			{
				if((*it_niv2) != NULL)
				{
					delete *it_niv2;
				}
			}
			delete *it_niv1;
		}
	}
	delete this->content;
}

bool Grid::cellExists(int column, int line){
    if(column < 0 || column >= this->width){
        return false;
    }
    else if(line < 0 || line >= this->height){
        return false;
    }
    return true;
}

Cell* Grid::getCell(int column, int line){
    if(this->cellExists(column, line)){
        return this->content->at(line)->at(column);
    }
	return NULL; // TODO: add existing exception if possible
}

Cell* Grid::getCellInTore(int column, int line){

    Cell* askedCell = this->getCell(column, line);

    // Cell is in classic grid
    if(askedCell != NULL){
        return askedCell;
    }

    // Use grid as a tore to get cell
    if(column < 0){
        column = this->width + column;
    }
    else if(column >= this->width){
        column = this->width - column;
    }

    if(line < 0){
        line = this->height + line;
    }
    else if(line >= this->height){
        line = this->height - line;
    }

    askedCell = this->getCell(column, line);
    return askedCell;
}

QVector<Pawn*>* Grid::getCellNeighbors(int column, int line){

    // This list will contain close neighbors (1 cell range)
    QVector<Pawn*>* neighbors = new QVector<Pawn*>();
    for(int y = line - 1; y <= line + 1; y++){
        for(int x = column - 1; x <= column + 1; x++){
            Pawn* neighbor = this->getCellInTore(x, y)->getPawn();
            neighbors->push_back(neighbor);
        }
    }
    return neighbors;
}

Grid* Grid::clone(){
    Grid* deepClone = new Grid(this->width, this->height);
    for(int line = 0; line < deepClone->height; line++){
        for(int col = 0; col < deepClone->width; col++){
            deepClone->getCell(col, line)->setPawn(this->getCell(col, line)->getPawn());
        }
    }
    return deepClone;
}


void Grid::debugDisplay(){
    for(int line = 0; line < this->height; line++){
        QString lineString = "";

        for(int col = 0; col < this->width; col++){
            lineString +=  this->getCell(col, line)->getPawn()->getId() + " ";
        }

        qDebug() << lineString;
    }
    qDebug() << "";
}

int Grid::getHeight() { return this->height; }


int Grid::getWidth() { return this->width; }
