#include "QGCMissionNavIdle.h"
#include "ui_QGCMissionNavIdle.h"
#include "WaypointEditableView.h"

QGCMissionNavIdle::QGCMissionNavIdle(WaypointEditableView* WEV) :
    QWidget(WEV),
    ui(new Ui::QGCMissionNavIdle)
{
    ui->setupUi(this);
    this->WEV = WEV;

    //Using UI to change WP:
    connect(this->ui->param1SpinBox, SIGNAL(valueChanged(double)),WEV,SLOT(changedParam1(double)));

    //Reading WP to update UI:
    // connect(WEV,SIGNAL(frameBroadcast(MAV_FRAME)),this,SLOT(updateFrame(MAV_FRAME)));
    connect(WEV,SIGNAL(param1Broadcast(double)),this->ui->param1SpinBox,SLOT(setValue(double)));
}

// void QGCMissionNavIdle::updateFrame(MAV_FRAME frame)
// {
//     switch(frame)
//     {
//     case MAV_FRAME_LOCAL_ENU:
//     case MAV_FRAME_LOCAL_NED:
//         this->ui->posNSpinBox->show();
//         this->ui->posESpinBox->show();
//         this->ui->posDSpinBox->show();
//         this->ui->latSpinBox->hide();
//         this->ui->lonSpinBox->hide();
//         this->ui->altSpinBox->hide();
//         break;
//     case MAV_FRAME_GLOBAL:
//     case MAV_FRAME_GLOBAL_RELATIVE_ALT:
//         this->ui->posNSpinBox->hide();
//         this->ui->posESpinBox->hide();
//         this->ui->posDSpinBox->hide();
//         this->ui->latSpinBox->show();
//         this->ui->lonSpinBox->show();
//         this->ui->altSpinBox->show();
//         break;
//     default:
//         break;
//     }
// }

QGCMissionNavIdle::~QGCMissionNavIdle()
{
    delete ui;
}
