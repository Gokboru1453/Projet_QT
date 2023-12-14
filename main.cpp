#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("Equipe1db");

    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName();

        QSqlQuery query;
        query.exec("SELECT * FROM `Equipe1` ");
        while( query.next() ) {
            QString ID = query.value(0).toString();
            QString Nom = query.value(1).toString();
            QString Profession = query.value(2).toString();
            QString Pied = query.value(3).toString();
            QString Poste = query.value(3).toString();
            //QString Vitesse = query.value(3).toString();
            qDebug() << "\t|------------------------------------";
            qDebug() << "\t|"<< ID <<"|"<< Nom << "|"<<Profession << "|"<< Pied << "|"<<Poste<<"|";
        }
        qDebug() <<"\t|------------------------------------";
        qDebug() << "Requete ok ! :)" ;
        db.close();
    }
    else
    {
        qDebug() << "La connexion a échouée, désolé" << db.lastError().text();
    }

    w.show();
    return a.exec();
}
