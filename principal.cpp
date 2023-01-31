#include "principal.h"
#include "ui_principal.h"

#include <QMessageBox>
#include <QTranslator>
#include "QDebug"

Principal::Principal(QWidget *parent)
    : QWidget(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);
    setWindowTitle (tr("Agenda telefónica"));
    // Configurar la tabla
    ui->tblLista->setColumnCount(4);
    QStringList titulo;
    titulo << tr("Nombre") << tr("Apellido") << tr("Teléfono")<< tr("E-mail");
    ui->tblLista->setHorizontalHeaderLabels(titulo);
    // Leer desde el archivo
    cargarDatos();

}

Principal::~Principal()
{
    delete ui;
}

<<<<<<< HEAD
=======


>>>>>>> 7b0efe8a685818d5b52ebf2562e6ef7c4ea1eadc
void Principal::on_btnEliminar_clicked()
{

    QList<QModelIndex>big = ui->tblLista->selectionModel()->selectedRows();
    if(big.isEmpty()){
<<<<<<< HEAD
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
=======
        QMessageBox::information(this,"Seleccion","No se ha seleccionado ninguna fila");
>>>>>>> 7b0efe8a685818d5b52ebf2562e6ef7c4ea1eadc
        return;
    }

    QList<int> list;
    QList<int>::iterator x;
    QList<QModelIndex>::iterator i;

    for (auto &&i : big){
        list.append(i.row());
    }

    for (auto &&x : list){
        ui->tblLista->removeRow(x);
    }
}

void Principal::on_btnEditar_clicked()
{
    int cont=0;
    QList<QModelIndex>seleccion = ui->tblLista->selectionModel()->selectedRows();

    if(seleccion.isEmpty()){
<<<<<<< HEAD
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
=======
        QMessageBox::information(this,"Seleccion","No se ha seleccionado ninguna fila");
>>>>>>> 7b0efe8a685818d5b52ebf2562e6ef7c4ea1eadc
        return;
    }

    QList<QModelIndex>::iterator i;

    for (auto &&i : seleccion){
        cont++;
    }

    if(cont>1){
<<<<<<< HEAD
        QMessageBox::information(this,tr("Seleccion"),tr("Seleccione una fila"));
=======
        QMessageBox::information(this,"Seleccion","Seleccionr un fila");
>>>>>>> 7b0efe8a685818d5b52ebf2562e6ef7c4ea1eadc
        QMessageBox about;
        about.exec();
        return;
    }

    int row = ui->tblLista->currentRow();

    QTableWidgetItem *nombre = ui->tblLista->item(row, (NOMBRE));
    QTableWidgetItem *apellido = ui->tblLista->item(row, APELLIDO);
    QTableWidgetItem *telefono = ui->tblLista->item(row, TELEFONO);
    QTableWidgetItem *email = ui->tblLista->item(row, EMAIL);

    PersonaDialog pd(this);
    pd.setWindowTitle(tr("Agregar contacto"));

    pd.set_datos(nombre->text(), apellido->text(), telefono->text(), email->text());

    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Persona *p = pd.persona();

    ui->tblLista->setItem(row, NOMBRE, new QTableWidgetItem(p->nombre()));
    ui->tblLista->setItem(row, APELLIDO, new QTableWidgetItem(p->apellido()));
    ui->tblLista->setItem(row, TELEFONO, new QTableWidgetItem(p->telefono()));
    ui->tblLista->setItem(row, EMAIL, new QTableWidgetItem(p->email()));
}

void Principal::cargarDatos()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblLista->rowCount();
            ui->tblLista->insertRow(fila);
            ui->tblLista->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblLista->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
            ui->tblLista->setItem(fila, TELEFONO, new QTableWidgetItem(datos[TELEFONO]));
            ui->tblLista->setItem(fila, EMAIL, new QTableWidgetItem(datos[EMAIL]));
        }
        archivo.close();
    }
}



void Principal::on_btnAgregar_clicked()
{
    // Crear y mostrar el dialogo
    PersonaDialog pd(this);
    pd.setWindowTitle(tr("Agregar contacto"));
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Persona *p = pd.persona();
    //Agregar a la tabla
    int fila = ui->tblLista->rowCount();
    ui->tblLista->insertRow(fila);
    ui->tblLista->setItem(fila, NOMBRE, new QTableWidgetItem(p->nombre()));
    ui->tblLista->setItem(fila, APELLIDO, new QTableWidgetItem(p->apellido()));
    ui->tblLista->setItem(fila, TELEFONO, new QTableWidgetItem(p->telefono()));
    ui->tblLista->setItem(fila, EMAIL, new QTableWidgetItem(p->email()));
}



void Principal::on_btnGuardar_clicked()
{
    // Verificar que exista datos para guardar
    int filas = ui->tblLista->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,tr("Guardar contactos"),tr("Agenda sin datos para guardar"));
        return;
    }
    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblLista->item(i, NOMBRE);
            QTableWidgetItem *apellido = ui->tblLista->item(i, APELLIDO);
            QTableWidgetItem *telefono = ui->tblLista->item(i, TELEFONO);
            QTableWidgetItem *email = ui->tblLista->item(i, EMAIL);
            salida << nombre->text() << ";" << apellido->text() << ";";
            salida << telefono->text() << ";" << email->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this,tr("Guardar contactos"),tr("Contactos guardados con éxito"));
    }else{
        QMessageBox::critical(this,tr("Guardar contactos"),tr("No se puede escribir sobre ") + ARCHIVO);
    }

}
