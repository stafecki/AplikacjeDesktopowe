#include "MainWindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Menu File
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAct = fileMenu->addAction(tr("&Open"));
    QAction *saveAct = fileMenu->addAction(tr("&Save"));
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);

    QPushButton *openButton = new QPushButton("Otwórz plik PPM", this);
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);

    QPushButton *saveButton = new QPushButton("Zapisz plik PPM", this);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveFile);

    layout->addWidget(imageLabel);
    layout->addWidget(openButton);
    layout->addWidget(saveButton); // Dodaj przycisk zapisu

    central->setLayout(layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow() {}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open PPM File"), "", tr("PPM Files (*.ppm)"));
    if (!fileName.isEmpty()) {
        if (!image.loadFromFile(fileName.toStdString())) {
            QMessageBox::warning(this, tr("Error"), tr("Failed to load image."));
        } else {
            updateImageDisplay();
        }
    }
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PPM File"), "", tr("PPM Files (*.ppm)"));
    if (!fileName.isEmpty()) {
        if (!image.saveToFile(fileName.toStdString())) {
            QMessageBox::warning(this, tr("Error"), tr("Failed to save image."));
        }
    }
}

void MainWindow::updateImageDisplay() {
    int w = image.getWidth();
    int h = image.getHeight();
    const unsigned char* data = image.getData();
    if (!data || w == 0 || h == 0) {
        imageLabel->clear();
        return;
    }

    QImage qimg(data, w, h, QImage::Format_RGB888);
    imageLabel->setPixmap(QPixmap::fromImage(qimg));
}
