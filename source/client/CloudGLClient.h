#pragma once

#include <memory>

#include <QObject>

#include "ui_CloudGLClient.h"

class CloudGLClient final:
    public QMainWindow
{
    Q_OBJECT

public:
    CloudGLClient();

private:
    std::unique_ptr<Ui::CloudGLClient> m_ui;

};