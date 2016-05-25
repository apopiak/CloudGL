#include "CloudGLClient.h"

#include <QTimer>

#include "CreateSessionDialog.h"

CloudGLClient::CloudGLClient()
{
    m_ui.reset(new Ui::CloudGLClient());
    m_ui->setupUi(this);

    QTimer::singleShot(0, this, SLOT(createSession()));
}

void CloudGLClient::createSession() {
    CreateSessionDialog dialog(this);
    dialog.exec();
}

