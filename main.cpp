#include "principal.h"

#include <QTranslator>
#include <QInputDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Italiano" << "Inglés" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de traducción
    if (idiomaSeleccionado == "Italiano"){
        traducion.load(":/AgendaTelefonica_it.qm");
    }else if (idiomaSeleccionado == "Inglés"){
        traducion.load("://AgendaTelefonica_en.qm");
    }// Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}

