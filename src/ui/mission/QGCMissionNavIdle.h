#ifndef QGCMISSIONNAVIDLE_H
#define QGCMISSIONNAVIDLE_H

#include <QWidget>
#include "WaypointEditableView.h"

namespace Ui {
    class QGCMissionNavIdle;
}

class QGCMissionNavIdle : public QWidget
{
    Q_OBJECT

public:
    explicit QGCMissionNavIdle(WaypointEditableView* WEV);
    ~QGCMissionNavIdle();

// public slots:
//     void updateFrame(MAV_FRAME);

protected:
    WaypointEditableView* WEV;

private:
    Ui::QGCMissionNavIdle *ui;
};

#endif // QGCMISSIONNAVIDLE_H
