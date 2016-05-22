#include "CloudGLClient.h"

CloudGLClient::CloudGLClient()
{
    m_ui.reset(new Ui::CloudGLClient());
    m_ui->setupUi(this);
}