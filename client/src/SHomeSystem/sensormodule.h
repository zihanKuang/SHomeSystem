#ifndef SENSORMODULE_H
#define SENSORMODULE_H

#include <QAbstractListModel>

class SensorModule : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SensorModule(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // SENSORMODULE_H