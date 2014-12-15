/**
 * @file guicell.h
 * @brief GuiCell class header
 * @author nicolas
 * @version 0.1
 */

#ifndef GUICELL_H
#define GUICELL_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <guiimagemanager.h>

/**
 * @class GuiCell
 * @brief Widget herited from QWidget which represents a cell in the graphical grid.
 *
 * Display an image on itself and manage user clicks.
 *
 */
class GuiCell : public QWidget
{
    Q_OBJECT

    int x;
    int y;
    QLabel* imageContainer;
    QPixmap* pawnImage;
    GuiImageManager* imageManager;

public:

    /**
     * @brief Constructor
     * @param anX: position of the cell on the x axis
     * @param anY: position of the cell on the y axis
     * @param im: pointer to the Gui Image Manager to have access to paw images
     */
    explicit GuiCell(int,int,GuiImageManager*);
	
	~GuiCell();
	
    /**
     * @brief resizeEvent Called when the user change the zoom value. Resize the image.
     * @param: event: Unused
     */
     void resizeEvent(QResizeEvent*);

     /**
      * @brief mousePressEvent Called when the user click on a cell. Sends the clicked signal.
      * @param event: Unused
      */
     void mousePressEvent(QMouseEvent *);

     /**
      * @brief setPawnImage Setter for its attribute pawnImage
      * @param index: Identifier of the pawn to get its image
      */
     void setPawnImage(QString index);

     /**
      * @brief getX Getter for its attribute x
      * @return its position on the x axis
      */
     int getX();

     /**
      * @brief getY Getter for its attribute y
      * @return its position on the y axis
      */
     int getY();

signals:

     /**
      * @brief clicked Signal sent when a cell is clicked
      */
     void clicked();
    
public slots:
    
};

#endif // GUICELL_H
