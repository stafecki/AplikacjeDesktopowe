#pragma once
#include <QMainWindow>
#include <QLabel>
#include "PPMImage.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();
    void saveFile();

private:
    PPMImage image;
    QLabel* imageLabel;
    void updateImageDisplay();
};