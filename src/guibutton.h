/**
 * @file guibutton.h
 * @brief GuiButton class header
 * @author nicolas
 * @version 0.1
 */

#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include <QPushButton>

/**
 * @class GuiButton
 * @brief Widget herited from QPushButton used to send custom signal
 *
 * This widget has an index which is sent when the user click on it.
 * It is used to select a new pawn.
 *
 */
class GuiButton : public QPushButton
{
    Q_OBJECT

    int index;

public:

    /**
     * @brief Constructor
     * @param text : Text which will be displayed on the button
     * @param value : index of the pawn which will be stored in the index attribute
     */
    explicit GuiButton(QString text,int value);
    
signals:

    /**
     * @brief click Signal emited when the user click on a GuiButton
     * @param int : information send by the signal
     */
    void click(int);
    
public slots:

    /**
     * @brief recieveClick Slot which handle the click and send the click signal
     */
    void recieveClick();
    
};

#endif // GUIBUTTON_H
