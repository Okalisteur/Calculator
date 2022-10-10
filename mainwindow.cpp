#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));


    connect(ui->pushButton_plus_minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_pourcentage,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_egal,SIGNAL(released()),this,SLOT(on_pushButton_egal_released()));

     connect(ui->pushButton_addittion,SIGNAL(released()),this,SLOT(pourLes_operation()));
     connect(ui->pushButton_soustraction,SIGNAL(released()),this,SLOT(pourLes_operation()));
     connect(ui->pushButton_multiplication,SIGNAL(released()),this,SLOT(pourLes_operation()));
     connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(pourLes_operation()));

     ui->pushButton_addittion->setCheckable(true);
     ui->pushButton_soustraction->setCheckable(true);
     ui->pushButton_multiplication->setCheckable(true);
     ui->pushButton_division->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){
   //Envoie les valeurs de chaque QPushButton à la variable button qui est devenue l'addresse de chaque QPushButton pointée différement
    QPushButton * button =(QPushButton*)sender();

    //Permet d'afficher à chaque fois les valeurs des nouveaux boutton
    double nombre_compil;
    QString Affiche_chiffre;
     nombre_compil=( ui->label->text() + button->text()).toDouble();

     Affiche_chiffre=QString::number(nombre_compil,'g',12);


   //Fait sortir par l'interface utilisateur ui(Utilisateur Interface) le texte du button
   ui->label->setText(Affiche_chiffre);
}
void MainWindow::on_pushButton_virgule_released()
{
    ui->label->setText(ui->label->text() + ".");
}
void MainWindow::unary_operation_pressed(){
    QPushButton * button =(QPushButton*)sender();

    double nombre_compil;
    QString Affiche_chiffre;

    if (button->text()== "+/-")
    {
       nombre_compil= ui->label->text().toDouble();
       nombre_compil= nombre_compil * (-1);
       Affiche_chiffre= QString::number(nombre_compil,'g',12);
       ui->label->setText(Affiche_chiffre);
   }

    if (button->text()== "%")
    {
       nombre_compil= ui->label->text().toDouble();
       nombre_compil= nombre_compil * (0.01);
       Affiche_chiffre= QString::number(nombre_compil,'g',12);
       ui->label->setText(Affiche_chiffre);
   }
}


void MainWindow::on_pushButton_clear_released()
{
    double nombre_compil;
    QString Affiche_chiffre;
    nombre_compil= ui->label->text().toDouble();
    nombre_compil= nombre_compil * 0;
    Affiche_chiffre= QString::number(nombre_compil);
     ui->label->setText(Affiche_chiffre);

}


void MainWindow::on_pushButton_egal_released()
{
    double resultat,second_nombre;
    QString nouveaux_affiche ;

    second_nombre= label->text.toDouble();
   if (ui->pushButton_addittion->isChecked())
   {
       resultat= firstNum + second_nombre;
       nouveaux_affiche = QString::number(resultat,'g',15);
       ui->label->setText(nouveaux_affiche);
       ui->pushButton_addittion->setChecked(false);
   }

   else if (ui->pushButton_soustraction->isChecked())
   {

   }

   else if (ui->pushButton_multiplication->isChecked())
   {

   }

   else if (ui->pushButton_division->isChecked())
   {

   }
}
void MainWindow::pourLes_operation()
{
    QPushButton * button =(QPushButton*)sender();
    firstNum=ui->label->text().toDouble();



    button->setChecked(true);
}

