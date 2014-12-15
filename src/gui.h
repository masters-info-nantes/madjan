/**
 * @file gui.h
 * @brief Gui class header
 * @author nicolas
 * @version 0.1
 */

#ifndef GUI_H
#define GUI_H

#include <QtGui/QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QPainter>
#include <QScrollArea>
#include <QLabel>
#include <controler.h>
#include <QSlider>
#include <QLineEdit>
#include <guicell.h>
#include <guibutton.h>
#include <QTimer>
#include <guiimagemanager.h>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

/**
 * @class Gui
 * @brief Manage the entire Graphical User Interface
 *
 * Create, Delete and Update every widget in every window of the application
 *
 */
class Gui : public QWidget
{
    Q_OBJECT

    Controler* controler;
    QGridLayout* mainLayout;
    int zoom;
    QTimer* playTimer;
    QWidget* randomWindow;
    GuiImageManager* imageManager;

    // Menu Bar //

    QMenuBar* menu;
    QMenu* pluginMenu;
    QMenu* helpMenu;

    // Play Pause Next Menu //

    QWidget* playMenu;
    QGridLayout* playMenuLayout;
    QSlider* zoomSlider;
    QPushButton* randomButton;
    QPushButton* playButton;
    QPushButton* pauseButton;
    QPushButton* nextButton;
    QLineEdit* widthEdit;
    QLineEdit* heightEdit;
    QPushButton* applySizeButton;
    QLabel* generationLabel;

    // Random window //
    QLineEdit* randomWidth;
    QLineEdit* randomHeight;
    QList<QLineEdit*>* pawnPourcentages;
    QList<QLineEdit*>* pawnPourcentagesFinish;
    QLineEdit* generationFinish;

    // Cell Menu //

    QScrollArea* cellScrollArea;
    QWidget* cellScrollWrapper;
    QGridLayout* cellScrollLayout;
    QVector<GuiButton*>* cellButtons;

    // Canvas //
    QGridLayout* canvasLayout;
    QVector<QVector<GuiCell*>*>* cells;
    QScrollArea* scrollArea;
    QWidget* layoutContainer;

public:

    /**
     * @brief Default constructor
     */
    Gui();

    /**
     * @brief Default destructor
     */
    ~Gui();

    /**
    * @brief updatePawnButtons Change the buttons when a new plugin is loaded.
    */
    void updatePawnButtons();

    /**
    * @brief Initialize the random generation window
    */
    void createRandomWindow();

public slots:

    /**
     * @brief initGrid Initialize an empty graphic grid by width and height
     * @param width : width of the future grid
     * @param height : height of the future grid
     */
    void initGrid(int width,int height,bool deleteGuiCell = false);

    /**
    * @brief clearGrid Clear the graphical grid
    */
    void clearGrid(bool deleteGuiCell = false);

    /**
    * @brief refreshGrid Refresh each pawn of the graphical grid
    */
    void refreshGrid();

    /**
    * @brief setZoom Change the zoom of the grid. Slot called by the slider.
    * @param value Value of the zoom (1 to 100)
    */
    void setZoom(int value);

    /**
    * @brief changePawn Slot called when clicking on a cell. Call the changePawn method in the controler.
    */
    void changePawn();

    /**
    * @brief changePlugin Slot called when changing the pluging in the menu. Call the changePlugin method of the controller.
    */
    void changePlugin();

    /**
    * @brief play Start the timer which triggers the animation of the grid
    */
    void play();

    /**
    * @brief pause Stop the timer which triggers the animation of the grid
    */
    void pause();

    /**
    * @brief changeGridSize Call the changeGridSize method of the controller. Is called by the "Apply" button
    */
    void changeGridSize();

    /**
    * @brief showRandomWindow Display a new modal window to configure the randomly generated grid
    */
    void showRandomWindow();

    /**
    * @brief generateRandomGrid Call the randomGenerate function of the controler
    */
    void generateRandomGrid();

    /**
    * @brief showAbout Display the "About" dialog when you click on Help->about in the menu bar.
    */
    void showAbout();

    /**
    * @brief showDocumentation Display the User Documentation with your default pdf reader when you click on Help->"User Documentation" in the menu bar.
    */
    void showDocumentation();

    /**
    * @brief nextGeneration Call nextFrame on the controller
    */
    void nextGeneration();

    signals:

    /**
    * @brief closeApp Signal emitted to close the application
    */

};

#endif // GUI_H
