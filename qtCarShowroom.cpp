#include "qtCarShowroom.h"

qtCarShowroom::qtCarShowroom(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::qtCarShowroomClass();
    ui->setupUi(this);

    carController = NULL;
    carModel = NULL;

    model = new QStringListModel(this);
    
    listView = ui->listView;
    carBodySpinBox = ui->carBodySpinBox;
    fuelConsumptionDoubleSpinBox = ui->fuelConsumptionDoubleSpinBox;
    enginePowerSpinBox = ui->enginePowerSpinBox;
    carPriceSpinBox = ui->carPriceSpinBox;
    submitButton = ui->pushButton;
    nextButton = ui->SubmitPushButton;

    //Walidacja
    carBodySpinBox->setMinimum(0);
    carBodySpinBox->setMaximum(3);
    carBodySpinBox->setValue(0);
    enginePowerSpinBox->setMinimum(100);
    enginePowerSpinBox->setMaximum(600);
    enginePowerSpinBox->setValue(230);
    fuelConsumptionDoubleSpinBox->setMinimum(7);
    fuelConsumptionDoubleSpinBox->setMaximum(30);
    fuelConsumptionDoubleSpinBox->setValue(13.00);
    carPriceSpinBox->setMinimum(112000);
    carPriceSpinBox->setMaximum(600000);
    carPriceSpinBox->setValue(112000);
    
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    
    connections();
}

void qtCarShowroom::connections() {
    connect(submitButton, &QPushButton::clicked, this, &qtCarShowroom::clickedSearchButton);
    connect(listView, &QListView::doubleClicked, this, &qtCarShowroom::doubleClickedListView);
    connect(nextButton, &QPushButton::clicked, this, &qtCarShowroom::clickedSubmitButton);
}

void qtCarShowroom::clickedSearchButton()
{
    carController = new CarController();
    carModel = new CarModel();

    //Dane wprowadzone przez uzytkownika
    carModel->carBody = carBodySpinBox->value();
    carModel->enginePower = enginePowerSpinBox->value();
    carModel->fuelConsumption = fuelConsumptionDoubleSpinBox->value();
    carModel->carPrice = carPriceSpinBox->value();

    //Algorytm wyszukiwania aut z bazy danych
    carController->setInputCarModel(*carModel);
    carController->SelectData();

    QStringList List;
    if (!carController->getOutputCarModel().isEmpty()) {
        //inicjalizacja QVectora lokalnie
        cars = carController->getOutputCarModel();
        for (auto x : carController->getOutputCarModel())
            List << x.carBrand + " " + x.carModel;
    } else {
        List << "W salonie nie ma aut o takiej specyfikacji";
    }

    model->setStringList(List);
    listView->setModel(model);

    delete carController;
}

void qtCarShowroom::doubleClickedListView()
{
    //Wybor auta
    QModelIndex index = listView->selectionModel()->currentIndex();
    carIndex = index.row();
}

void qtCarShowroom::clickedSubmitButton()
{
    //Przycisk zakupu auta
    //qDebug() << cars[carIndex].id << cars[carIndex].carModel;
}

void qtCarShowroom::closeEvent(QCloseEvent* event)
{
    //Przy zamykaniu okna uruchamia sie sygnal ktory wywoluje funkcje ze slotu z Main Window
    emit BackToMainWindow();
}